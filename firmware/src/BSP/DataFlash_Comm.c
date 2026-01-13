/*
 * AtmelFlashMem_K20.C
 *
 *  Created on: Sep 19, 2012
 *      Author: myself
 */
#include "DataFlash_Comm.h"
//#include "RTC_Kinetis.h"
#include "AtmelFlashMem.h"
#include "peripheral/gpio/plib_gpio.h"


extern volatile bool SPIDataSendReceivedFlag;


void SPI_SendRcv_Block (uint8_t* InpData,uint8_t* OutData,int NoofChars)
{
    bool SPI_Ok;

    SPI_CS2_Set();//other chips are deselected
    SPI_CS1_Set(); //second chip deselected made sure
    SPI_CS0_Clear();
    _nop();
	SPI_Ok = SPI1_WriteRead ((uint8_t*)OutData, NoofChars,(uint8_t*)InpData, NoofChars);
    SPI_CS0_Set();
    
    if(!SPI_Ok)
        printf("\nSPI Error");
    
}

 



unsigned short GetAutoPageStart() 
{
unsigned short RetVal;

    ReadDataFlash (AUTOPAGE_ADR,(unsigned char*) &RetVal,2);
    return RetVal;
}
void StoreAutoPageStart(unsigned short PageAdr)
{
 
    WriteDataFlash (AUTOPAGE_ADR,(unsigned char*) &PageAdr,2);
}

unsigned short GetAutoPageCount() 
{
unsigned short RetVal;

    ReadDataFlash (AUTOPAGE_CNT,(unsigned char*) &RetVal,2);
    return RetVal;
    
}
void StoreAutoPageCount(unsigned short PageAdr)
{
 
    WriteDataFlash (AUTOPAGE_CNT,(unsigned char*) &PageAdr,2);
}

