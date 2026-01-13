#include "I2C_Comm.h"

extern volatile I2C_TRANSFER_STATUS transferStatus;
extern volatile int32_t mSecCntr;


uint8_t Get_I2C2_Adresses(uint8_t* Adrs)
{
    uint8_t temp,tempr[2];
	unsigned char AdrTostore;
    //APP_TRANSFER_STATUS state = APP_TRANSFER_STATUS_IDLE;
    int found=0;
    volatile uint32_t starttime,lapsedtime;
    //bool I2CErr=false;      
	
    //uint32_t timing;
    
    temp = 0x0;
    
	for(AdrTostore=0x08;AdrTostore<0x78;AdrTostore++) //only 7 bit addressing
	{

        starttime = GetSystemMs();
        transferStatus = I2C_TRANSFER_STATUS_IN_PROGRESS;
         I2C2_Read((uint16_t)AdrTostore,&tempr[0],1);
         
        while(  (transferStatus != I2C_TRANSFER_STATUS_ERROR) 
       && (transferStatus != I2C_TRANSFER_STATUS_SUCCESS) ) //wait till Interrupt is serviced
        {
            lapsedtime = GetSystemMs()-starttime ;
            if(lapsedtime > I2C_Comm_TimeOut) //if no interrupt generated in 20mSec
            {
                printf("\nI2C Timeout Error In Get_I2C2_Adresses() on Address %02X ",AdrTostore);
                transferStatus = I2C_TRANSFER_STATUS_IDLE;
                return found;
            }
                
        }

         if(transferStatus == I2C_TRANSFER_STATUS_SUCCESS)
         {
            *(Adrs+found) = AdrTostore;
            printf("\nFound I2C Address: %02X",AdrTostore);
            found++;
            if(found==8) 
            {
                transferStatus = I2C_TRANSFER_STATUS_IDLE;
                return found;
            }
                
         }
         
         
    }    
    
    transferStatus = I2C_TRANSFER_STATUS_IDLE;
		return found;	 //not found


}
