#include "Sys_Inits.h"
#include "System_Configuration.h"
#include "Events.h"
#include "BoardTemp.h"
#include "RTC_Comm.h"
#include "I2C_Comm.h"

extern unsigned int FlashSize;
extern unsigned int FlashCap;
extern volatile I2C_TRANSFER_STATUS transferStatus;
extern volatile int IN_DAT_BUF;
extern char ETH_AT_Buffer[];
extern uint8_t ETH_DAT_Buffer[];
extern uint8_t I2C_Addrs[];
extern volatile int IN_DAT_BUF;
extern volatile int IN_AT_BUF;
extern volatile bool KeyBoardEnable;
extern volatile bool InputReadEnable;

void PON_Inits()
{
        /* Initialize all modules */
    SYS_Initialize ( NULL );
    
 
    I2C2_CallbackRegister(I2C2_I2cXferDone,(uintptr_t)&transferStatus );

    //-- AT Command Port Initialization
    ETH_AT_PORT_ReadCallbackRegister(ETH_Port1_OnBlockReceived,(uintptr_t)NULL);
    ETH_AT_PORT_WriteCallbackRegister(ETH_Port1_OnBlockSent,(uintptr_t)NULL);
    IN_AT_BUF = 0;
    ETH_AT_PORT_Read(&ETH_AT_Buffer[IN_AT_BUF],1);  //Prepare to receive data
    
    //TCP Data Port initialization
    ETH_DAT_PORT_ReadCallbackRegister(ETH_Port0_OnBlockReceived,(uintptr_t)NULL);
    ETH_DAT_PORT_WriteCallbackRegister(ETH_Port0_OnBlockSent,(uintptr_t)NULL);
    ETH_DAT_PORT_Read(&ETH_DAT_Buffer[0],1);   //Prepare to receive data
    IN_DAT_BUF = 0;
    
    //General Purpose Timer Init
    CORETIMER_CallbackSet (Intr1Msec, (uintptr_t)NULL );
    CORETIMER_Start();
    
    ADC_CallbackRegister(ADC_ResultHandler, (uintptr_t)NULL);
    //Detecting and initializing Flash mem related variables is done at the start 
    //Flash mem 
    Check_DataFlash();
//Now Check I2C Bus
    Check_I2C_Bus();//this will find RTC Chips
    
    if(Reset_I2C())
        printf("\rI2C Bus OK..");
    else
        printf("\rI2C Bus Problem..");
    //RTC to be initiated after I@C bus us checked and OK
    Init_RTC();        

    KeyBoardEnable = true;
    InputReadEnable = true;

}



void Check_DataFlash()
{
    volatile uint32_t starttime,lapsedtime;
        starttime = GetSystemMs();
    do
    {
        lapsedtime = GetSystemMs() - starttime;
        
    }while (FlashBusy() && (lapsedtime < 100));
	
		
	if (lapsedtime >= 100) 
    {
	  printf("\rDATAFLASH MEMORY FAIL (BUSY)");
	  LongBeep();
      delay_mS(2000);
	  LongBeep();
      delay_mS(2000);
      LongBeep();
	}
    else
    {
        FlashSize = GetFlashPageSize();
        FlashCap = GetFlashMemCapacity();
        printf("\rFlash PerPage %d Cap %04X",FlashSize,FlashCap);
    }   


}


void Check_I2C_Bus()
{
  uint8_t found =  Get_I2C2_Adresses(I2C_Addrs);  
  
  if(found)
  {
      printf("\rFound %d Devices on I2C - %02X,%02X",found,I2C_Addrs[0],I2C_Addrs[1]);
      
      if((I2C_Addrs[0]== PCF_RTC_DEV_ADR) || (I2C_Addrs[0]==MCP_RTC_DEV_ADR) )
      {
         printf("\rTMP1075 NOT Found..");
         I2C_Addrs[1] = I2C_Addrs[0];
         I2C_Addrs[0] = 0;
      }
      else
      {  if (I2C_Addrs[0]== TempI2CAdr)
                printf("\rTMP1075 Found..");
         else
                printf("\rUnknown Device Found.. %02X @first place",I2C_Addrs[0]);
      }
      
      switch(I2C_Addrs[1])
      {
          case PCF_RTC_DEV_ADR:
             printf("\rRTC PCF85x63 Found..");
             break;
          case MCP_RTC_DEV_ADR:
             printf("\rRTC MCP7940 Found..");  
             break;
          default:
            printf("\rUnknown Device Found..%02X @ 2nd place",I2C_Addrs[1]);    
      }
      
  }
  else
  {
    printf("\rI2C Bus Problem..");
    I2C_Addrs[0] = 0x0;
    I2C_Addrs[1] = 0x0;
  }
    
}
