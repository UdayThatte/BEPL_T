
#include "AtmelFlashMem.h"
#include "Utils.h"
//#include "LCD128_64.h"
//#include "RTC_Kinetis.h"

extern void LongBeep();
extern uint8_t FlashInpData[];
extern uint8_t FlashOutData[];
extern unsigned int FlashSize;
extern unsigned int FlashCap;
extern unsigned int AutoPageCnt;

//specific to Kinetis in AtmelFlashMem_Kinetis
extern void StoreAutoPageStartToVBatMem(unsigned short PageAdr);
extern unsigned short GetAutoPageStartFromVBatMem(void);
extern void SPI_SendRcv_Block (unsigned char *InpData,unsigned char *OutData,int NoofChars);


long GetFlashAddress (long fAddr)
{
	long lAddr;

	lAddr = fAddr;
	if (FlashSize == Bytes528InPage)
		lAddr = ((fAddr / FlashSize) << 10) | (fAddr % FlashSize);
	return (lAddr);
}
///////////////////
bool WriteDataFlash (long fAddr, uint8_t *mAddr, int Count)
{
	long StartPage, EndPage;
	int PageBytes;
    
	if ((Count <= 0) || (Count > 250) || (FlashSize <= 0))
		return (false);

	StartPage = fAddr / FlashSize;
	EndPage = (fAddr + Count - 1) / FlashSize;
	PageBytes = FlashSize - (fAddr % FlashSize);
	if (StartPage != EndPage)
	{
		if (WriteDataFlashWithinPage (fAddr, mAddr, PageBytes))
		{
			fAddr += PageBytes;
			mAddr += PageBytes;
			return (WriteDataFlashWithinPage (fAddr, mAddr, Count - PageBytes));
		}
		else
			return (false);
	}
	else
		return (WriteDataFlashWithinPage (fAddr, mAddr, Count));
}
////


bool WriteDataFlashWithinPage(long FlashAddr, uint8_t *mAddr, int Count)
{
	char disp_str[20];
	long fAddr;
	unsigned char retry;
	bool match_done;
	
	retry = 0;
	match_done = false;
	while(1)
	{
			fAddr = GetFlashAddress (FlashAddr);
			FlashOutData[0]=0x53;	//Read Page in the Buffer
			FlashOutData [1] = fAddr >> 16;
			FlashOutData [2] = (fAddr >> 8) & 0x00ff;
			FlashOutData [3] = fAddr & 0x00ff;
			
			SPI_SendRcv_Block (FlashInpData,FlashOutData,4); 
	
	
	//Wait till reading to Page is over
            while(FlashBusy());
			  
            FlashOutData[0]=0x82;	//Write to Page through Buffer
            FlashOutData [1] = fAddr >> 16;
            FlashOutData [2] = (fAddr >> 8) & 0x00ff;
            FlashOutData [3] = fAddr & 0x00ff;
            memcpy(&FlashOutData[4],mAddr,Count);

            SPI_SendRcv_Block (FlashInpData,FlashOutData,4+Count);
				
//write is over now compare and multi try etc
			while(FlashBusy()); //wait till writing is over
		  
            FlashOutData[0]=0x60;	//Write to Page through Buffer
            FlashOutData [1] = fAddr >> 16;
            FlashOutData [2] = (fAddr >> 8) & 0x00ff;
            FlashOutData [3] = fAddr & 0x00ff;
		  
            SPI_SendRcv_Block (FlashInpData,FlashOutData,4);
		  
            while(FlashBusy()); //till comp is over
		  
            match_done = Flash_Page_Buffer_Match();
            
            if (match_done) break; 
            
            if(retry == 3) break; 
            
            retry++;	  
		  
	}	 //while ends here 	  		 
		  	  	
//
		  if(!match_done)
		  	  { 
			   //critical error of Memory Failed
			  	  return (false);
		  	  }
		  else
		  {
			  if(retry)
			  {
				  //Multiple Try
				  		printf("\nTried Multiple times to Write Flash Data..%d",retry);
				  		delay_mS(500);
				  return(true);
				  
			  }	  
		  }
		  AutoPageCnt++;
		  return(true);
	
}

bool ReadDataFlash (long FlashAddr,uint8_t *mAddr, int Count)
{
	
	long fAddr;

	if ((Count <= 0) || (Count > 255) || (FlashSize <= 0))
		return (false);
	
	fAddr = GetFlashAddress (FlashAddr);
		FlashOutData [0] = 0xe8;
		FlashOutData [1] = fAddr >> 16;
		FlashOutData [2] = (fAddr >> 8) & 0x00ff;
		FlashOutData [3] = fAddr & 0x00ff;
		FlashOutData[4]=0;
		FlashOutData[5]=0;
		FlashOutData[6]=0;//dummy 4 bytes as per instruction format
		FlashOutData[7]=0; 
		 while(FlashBusy());
		 
		 SPI_SendRcv_Block (FlashInpData,FlashOutData,8+Count);
		 memcpy(mAddr,&FlashInpData[8],Count);
		
		return (true);	
				
}

unsigned int GetFlashMemCapacity()
{
	unsigned char InpD[2];
	unsigned char OutD[2];
		
	OutD[0] = 0xD7;
	
	SPI_SendRcv_Block (InpD,OutD,2);
	return  (  (InpD[1] >> 2 ) & 0x0F  );	
}

//returns 1 if Buffer / Page data matches 
//Bit6=0

unsigned int GetFlashPageSize()
{
	uint8_t InpD[2];
	uint8_t OutD[2];
		
	OutD[0] = 0xD7;
	SPI_SendRcv_Block (InpD,OutD,2);    
    //SPI1_WriteRead(OutD, 1, InpD, 1);
	return  ( ( (InpD[1] & 0x01)== 0x0) ? Bytes528InPage:Bytes512InPage );	
}

bool Flash_Page_Buffer_Match()
{
	unsigned char InpD[2];
	unsigned char OutD[2];
		
		OutD[0] = 0xD7;
		SPI_SendRcv_Block (InpD,OutD,2);
	return  ( ( (InpD[1] & 0x40)== 0x0) ? true:false );			
}

//returns 1 if busy
bool FlashBusy()
{
unsigned char InpD[2];
unsigned char OutD[2];
	
	OutD[0] = 0xD7;
	SPI_SendRcv_Block (InpD,OutD,2);
    
 return  ( ( (InpD[1] & 0x80)== 0x0) ? true:false );			  
}


//
void AutoPageReWrite()
{
unsigned short int AutoPageStart,fAddr;
//int rW;
//char ss[20];
   	while(FlashBusy());// Wait till busy
    AutoPageCnt = GetAutoPageCount();
	if (!AutoPageCnt) return;
    
		
		AutoPageStart =  GetAutoPageStart();  


		if (AutoPageStart > MaxNoOfPage) AutoPageStart = 0;
//get adress of the page to rewrite
	do
	{	
		fAddr = AutoPageStart << 1;  //for 512 bytes
		if (FlashSize == Bytes528InPage)
			fAddr <<= 1;  //for 528 bytes
		
		FlashOutData[0]=0x58;	//autopage re write
		FlashOutData [1] = (fAddr >> 8) & 0x00ff;
		FlashOutData [2] = (fAddr & 0x00ff);
		FlashOutData [3] = 0;
		
		SPI_SendRcv_Block (FlashInpData,FlashOutData,4);
//Wait till operation is over
		while(FlashBusy());
			
        AutoPageCnt	--;
        AutoPageStart++;
        if (AutoPageStart > MaxNoOfPage) AutoPageStart = 0;
        
	} while(AutoPageCnt);

		StoreAutoPageStart(AutoPageStart);
        StoreAutoPageCount(0);
}

