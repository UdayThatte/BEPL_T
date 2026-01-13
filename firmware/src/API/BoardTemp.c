
#include "BoardTemp.h"
#include "I2C_Comm.h"
#include "Utils.h"

extern volatile I2C_TRANSFER_STATUS transferStatus;

//This is used for TMP1075 with I2C interface
bool Get_Temp(float* Temp)
{
   unsigned char temp[3];
   float Temperature=-999.0;//in case of fault
   char Sign;
   int n;
   volatile uint32_t starttime,lapsedtime;
    
        temp[2] = 0x0;
        starttime = GetSystemMs();
        transferStatus = I2C_TRANSFER_STATUS_IN_PROGRESS;
        I2C2_WriteRead(TempI2CAdr, &temp[2],1, temp,2);
        while(  (transferStatus != I2C_TRANSFER_STATUS_ERROR) 
                && (transferStatus != I2C_TRANSFER_STATUS_SUCCESS) ) //wait till Interrupt is serviced
        {
            lapsedtime = GetSystemMs()-starttime ;
            if(lapsedtime >I2C_Comm_TimeOut) //if no interrupt generated in 20mSec
            {
                printf("\nI2C Timeout Error In Get_Temp()");
                transferStatus = I2C_TRANSFER_STATUS_IDLE;
                return false;
            }
                
        }
        
        if(transferStatus == I2C_TRANSFER_STATUS_SUCCESS)
        {
            Sign = '+';
            n = (temp[0] * 256) + temp[1] ;
            n = n>>4; //shift right 4 bits                
            if (n > 0x7FF)
                {
                    n = 0xFFF - n + 1 ; //2s complement
                    Sign = '-'; //temp is minus
                }
            Temperature = ((float)n * Mulfactor_TMP1075);
            if(Sign == '-') Temperature *=-1;
            
            *(Temp) = Temperature;
            transferStatus = I2C_TRANSFER_STATUS_IDLE;
            return true;
        }
   printf("\nI2C Comm Error Error In Get_Temp()");     
   transferStatus = I2C_TRANSFER_STATUS_IDLE;
   return false;
}

