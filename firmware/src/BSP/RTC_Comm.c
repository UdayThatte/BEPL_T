/*
 * RTC_Kinetis.C
 *
 *  Created on: Mar 27, 2013
 *      Author: Uday
 */
#include "RTC_Comm.h"
#include "I2C_Comm.h"

extern uint8_t I2C_Addrs[];
extern void LongBeep();
extern volatile uint8_t RTC_Stat;
extern volatile I2C_TRANSFER_STATUS transferStatus;

static RTC_OBJ rtcobj;


bool Init_RTC()
{
 uint8_t Adr;   
 RTC_Time t ;
 bool ret;
 
    Adr = I2C_Addrs[1];    //Address of RTC 
    if (Adr == 0)
    {
        RTC_Stat = RTC_Comm_Failed;
         return false; //no RTC Found //no RTC found
    }
    RTC_Stat = RTC_OK;
    
         rtcobj.address = Adr;  
     
     switch(Adr)
     {
         case MCP_RTC_DEV_ADR:
                    rtcobj.gettimecallback = MCP_RTC1_GetTime;
                    rtcobj.settimecallback = MCP_RTC1_SetTime;
                    rtcobj.initcallback = MCP_Init_RTC;

                    rtcobj.ramstart = 0x20;
                    break;
         case PCF_RTC_DEV_ADR:
                    rtcobj.gettimecallback = PCF_RTC1_GetTime;
                    rtcobj.settimecallback = PCF_RTC1_SetTime;
                    rtcobj.initcallback = PCF_Init_RTC;
                    
                    rtcobj.ramstart = 0x03;
                    break;
         default:
                RTC_Stat = RTC_Comm_Failed;
                return false;
     }
     
    
    //return ret;
     return rtcobj.initcallback();
}
bool RTC1_GetTime(RTC_Time *Time)
{
    if(RTC_Stat != RTC_OK) return false;
    rtcobj.parameter = Time;
    return rtcobj.gettimecallback(rtcobj.parameter);
}

bool RTC1_SetTime(RTC_Time *Time)
{
    if(RTC_Stat != RTC_OK) return false;
    rtcobj.parameter = Time;
    return rtcobj.settimecallback(rtcobj.parameter);
}


//=====================================
bool PCF_Init_RTC()
{
   uint8_t temp,tempr[2];
   bool Rslt;
   volatile uint32_t starttime,lapsedtime;
   
    temp = PCF_CONTRL_1;
    tempr[1] = 0x0;

    starttime = GetSystemMs();
    transferStatus = I2C_TRANSFER_STATUS_IN_PROGRESS;
    
    Rslt = I2C2_WriteRead(PCF_RTC_DEV_ADR,&temp,1,&tempr[1],1);
    
    while(  (transferStatus != I2C_TRANSFER_STATUS_ERROR) 
            && (transferStatus != I2C_TRANSFER_STATUS_SUCCESS) ) //wait till Interrupt is serviced
    {
        lapsedtime = GetSystemMs()-starttime ;
        if(lapsedtime >I2C_Comm_TimeOut) //if no interrupt generated in 20mSec
        {
            printf("\nI2C Timeout Error In PCF_Init_RTC()");
            transferStatus = I2C_TRANSFER_STATUS_IDLE;
            return false;
        }

    }
    if(transferStatus != I2C_TRANSFER_STATUS_SUCCESS)
    {
            printf("\nI2C Error In PCF_Init_RTC()");
            transferStatus = I2C_TRANSFER_STATUS_IDLE;
            LongBeep();
            return false;
    }
    
    return Rslt;
    
}
static int oscfailed = 0;

bool PCF_RTC1_GetTime(RTC_Time *Time)
{
    volatile uint32_t starttime,lapsedtime;
    uint8_t temp,tempr[8],tempwr[2];
    
    temp = PCF_Reg_RTCSEC;
    starttime = GetSystemMs();
    transferStatus = I2C_TRANSFER_STATUS_IN_PROGRESS;
    I2C2_WriteRead(PCF_RTC_DEV_ADR,&temp,1,&tempr[0],7);
    
    while(  (transferStatus != I2C_TRANSFER_STATUS_ERROR) 
            && (transferStatus != I2C_TRANSFER_STATUS_SUCCESS) ) //wait till Interrupt is serviced
    {
        lapsedtime = GetSystemMs()-starttime ;
        if(lapsedtime >I2C_Comm_TimeOut) //if no interrupt generated in 20mSec
        {
            printf("\nI2C Timeout Error In PCF_RTC1_GetTime()");
            transferStatus = I2C_TRANSFER_STATUS_IDLE;
            return false;
        }

    }
    if(transferStatus != I2C_TRANSFER_STATUS_SUCCESS)
    {
            printf("\nI2C Error In PCF_RTC1_GetTime()");
            transferStatus = I2C_TRANSFER_STATUS_IDLE;
            return false;
    }
    
    

    Time->Second = tempr[0] & 0x7F; //mask OS bit ;
    Time->Minute = tempr[1];
    Time->Hour = tempr[2];
    Time->Day = tempr[3];
    Time->DayOfWeek = tempr[4];
    Time->Month = tempr[5];
    Time->Year = tempr[6];
    return true;
}
bool PCF_RTC1_SetTime(RTC_Time *Time)
{
       //uint8_t temp;
    uint8_t tempr[8];
    volatile uint32_t starttime,lapsedtime;
    
    tempr[0] = PCF_Reg_RTCSEC;
    tempr[1] = Time->Second & 0x7f;
    tempr[2] = Time->Minute ;
    tempr[3] = Time->Hour  ;
    tempr[4] = Time->Day;
    tempr[5] = Time->DayOfWeek;
    tempr[6] = Time->Month  ;
    tempr[7] = Time->Year  ;
    
    starttime = GetSystemMs();
    transferStatus = I2C_TRANSFER_STATUS_IN_PROGRESS;
    
    I2C2_Write(PCF_RTC_DEV_ADR,&tempr[0],8);
    while(  (transferStatus != I2C_TRANSFER_STATUS_ERROR) 
            && (transferStatus != I2C_TRANSFER_STATUS_SUCCESS) ) //wait till Interrupt is serviced
    {
        lapsedtime = GetSystemMs()-starttime ;
        if(lapsedtime >I2C_Comm_TimeOut) //if no interrupt generated in 20mSec
        {
            printf("\nI2C Timeout Error In PCF_RTC1_SetTime()");
            transferStatus = I2C_TRANSFER_STATUS_IDLE;
            return false;
        }

    }
    if(transferStatus != I2C_TRANSFER_STATUS_SUCCESS)
    {
            printf("\nI2C Error In PCF_RTC1_SetTime()");
            transferStatus = I2C_TRANSFER_STATUS_IDLE;
            return false;
    }
    return true;

}
//=====================================
bool MCP_Init_RTC()
{
   // make sure osc is enabled and running AND BATTERY IS ENABLED
   uint8_t temp,tempr[10],tempwr[2];
   bool Rslt;
   volatile uint32_t starttime,lapsedtime;
   
    RTC_Stat = RTC_OK;   
 
//////    
    temp = MCP_Reg_RTCWDAY;
    starttime = GetSystemMs();
    transferStatus = I2C_TRANSFER_STATUS_IN_PROGRESS;
    
    I2C2_WriteRead(MCP_RTC_DEV_ADR,&temp,1,&tempr[1],1);
    while(  (transferStatus != I2C_TRANSFER_STATUS_ERROR) 
            && (transferStatus != I2C_TRANSFER_STATUS_SUCCESS) ) //wait till Interrupt is serviced
    {
        lapsedtime = GetSystemMs()-starttime ;
        if(lapsedtime >I2C_Comm_TimeOut) //if no interrupt generated in 20mSec
        {
            printf("\nI2C Timeout Error In MCP_Init_RTC()");
            transferStatus = I2C_TRANSFER_STATUS_IDLE;
            return false;
        }

    }
    
    if(transferStatus != I2C_TRANSFER_STATUS_SUCCESS)
    {
            printf("\nI2C Error In MCP_Init_RTC()");
            transferStatus = I2C_TRANSFER_STATUS_IDLE;
            LongBeep();
            return false;
    }
    
    
    if(!(tempr[1] & MCP_RTC_VBATENB_MASK))
    {
        tempr[0] = MCP_Reg_RTCWDAY;
        tempr[1] |= MCP_RTC_VBATENB_MASK;
        starttime = GetSystemMs();
        transferStatus = I2C_TRANSFER_STATUS_IN_PROGRESS;
        I2C2_Write(MCP_RTC_DEV_ADR,&tempr[0],2);
        while(  (transferStatus != I2C_TRANSFER_STATUS_ERROR) 
                && (transferStatus != I2C_TRANSFER_STATUS_SUCCESS) ) //wait till Interrupt is serviced
        {
            lapsedtime = GetSystemMs()-starttime ;
            if(lapsedtime >I2C_Comm_TimeOut) //if no interrupt generated in 20mSec
            {
                printf("\nI2C Timeout Error In MCP_Init_RTC()");
                transferStatus = I2C_TRANSFER_STATUS_IDLE;
                return false;
            }

        }
            if(transferStatus != I2C_TRANSFER_STATUS_SUCCESS)
            {
                    printf("\nI2C Error In MCP_Init_RTC()");
                    transferStatus = I2C_TRANSFER_STATUS_IDLE;
                    return false;
            }

        
        
    }
//Vbat is enabled   
//Now check if osc running
    if(!(tempr[1] & MCP_RTC_OSC_STATUS_MASK))
    {
//if not then enable in Sec reg
        temp = MCP_Reg_RTCSEC;
        starttime = GetSystemMs();
        transferStatus = I2C_TRANSFER_STATUS_IN_PROGRESS;

        I2C2_WriteRead(MCP_RTC_DEV_ADR,&temp,1,&tempr[1],1);
        while(  (transferStatus != I2C_TRANSFER_STATUS_ERROR) 
                && (transferStatus != I2C_TRANSFER_STATUS_SUCCESS) ) //wait till Interrupt is serviced
        {
            lapsedtime = GetSystemMs()-starttime ;
            if(lapsedtime >I2C_Comm_TimeOut) //if no interrupt generated in 20mSec
            {
                printf("\nI2C Timeout Error In MCP_Init_RTC()");
                transferStatus = I2C_TRANSFER_STATUS_IDLE;
                return false;
            }
        }

        if(transferStatus != I2C_TRANSFER_STATUS_SUCCESS)
            {
                    printf("\nI2C Error In MCP_Init_RTC()");
                    transferStatus = I2C_TRANSFER_STATUS_IDLE;
                    return false;
            }



        
        tempr[0] = MCP_Reg_RTCSEC;
        tempr[1] |= MCP_RTC_OSC_START_MASK;
        starttime = GetSystemMs();
        transferStatus = I2C_TRANSFER_STATUS_IN_PROGRESS;

        I2C2_Write(MCP_RTC_DEV_ADR,&tempr[0],2);
        while(  (transferStatus != I2C_TRANSFER_STATUS_ERROR) 
                && (transferStatus != I2C_TRANSFER_STATUS_SUCCESS) ) //wait till Interrupt is serviced
        {
            lapsedtime = GetSystemMs()-starttime ;
            if(lapsedtime >I2C_Comm_TimeOut) //if no interrupt generated in 20mSec
            {
                printf("\nI2C Timeout Error In MCP_Init_RTC()");
                transferStatus = I2C_TRANSFER_STATUS_IDLE;
                return false;
            }
        }

        if(transferStatus != I2C_TRANSFER_STATUS_SUCCESS)
            {
                    printf("\nI2C Error In MCP_Init_RTC()");
                    transferStatus = I2C_TRANSFER_STATUS_IDLE;
                    return false;
            }
        
        
    }
//osc started if not already running    
    
    return true;
}

bool MCP_RTC1_GetTime(RTC_Time *Time)
{
    uint8_t temp,tempr[8];
    volatile uint32_t starttime,lapsedtime;
    
    temp = MCP_Reg_RTCSEC;
    starttime = GetSystemMs();
    transferStatus = I2C_TRANSFER_STATUS_IN_PROGRESS;

    I2C2_WriteRead(MCP_RTC_DEV_ADR,&temp,1,&tempr[0],7);
    while(  (transferStatus != I2C_TRANSFER_STATUS_ERROR) 
            && (transferStatus != I2C_TRANSFER_STATUS_SUCCESS) ) //wait till Interrupt is serviced
    {
        lapsedtime = GetSystemMs()-starttime ;
        if(lapsedtime >I2C_Comm_TimeOut) //if no interrupt generated in 20mSec
        {
            printf("\nI2C Timeout Error In MCP_RTC1_GetTime()");
            transferStatus = I2C_TRANSFER_STATUS_IDLE;
            return false;
        }
    }

    if(transferStatus != I2C_TRANSFER_STATUS_SUCCESS)
        {
                printf("\nI2C Error In MCP_RTC1_GetTime()");
                transferStatus = I2C_TRANSFER_STATUS_IDLE;
                return false;
        }

    Time->Second = tempr[0] & ~(MCP_RTC_OSC_START_MASK);
    Time->Minute = tempr[1];
    Time->Hour = tempr[2];
    Time->DayOfWeek = tempr[3];
    Time->Day = tempr[4];
    Time->Month = tempr[5]  & 0x1f; //UPPER BIT IS LEAP YEAR;
    Time->Year = tempr[6];
    return true;
}


bool MCP_RTC1_SetTime(RTC_Time *Time)
{
    //uint8_t temp;
    uint8_t tempr[8];
    volatile uint32_t starttime,lapsedtime;
    
    tempr[0] = MCP_Reg_RTCSEC;
    tempr[1] = Time->Second | MCP_RTC_OSC_START_MASK;
    tempr[2] = Time->Minute ;
    tempr[3] = Time->Hour  ;
    tempr[4] = Time->DayOfWeek | MCP_RTC_VBATENB_MASK;
    tempr[5] = Time->Day;
    tempr[6] = Time->Month  ;
    tempr[7] = Time->Year  ;
    
    starttime = GetSystemMs();
    transferStatus = I2C_TRANSFER_STATUS_IN_PROGRESS;
    I2C2_Write(MCP_RTC_DEV_ADR,&tempr[0],8);
    while(  (transferStatus != I2C_TRANSFER_STATUS_ERROR) 
            && (transferStatus != I2C_TRANSFER_STATUS_SUCCESS) ) //wait till Interrupt is serviced
    {
        lapsedtime = GetSystemMs()-starttime ;
        if(lapsedtime >I2C_Comm_TimeOut) //if no interrupt generated in 20mSec
        {
            printf("\nI2C Timeout Error In MCP_RTC1_SetTime()");
            transferStatus = I2C_TRANSFER_STATUS_IDLE;
            return false;
        }
    }

    if(transferStatus != I2C_TRANSFER_STATUS_SUCCESS)
        {
                printf("\nI2C Error In MCP_RTC1_SetTime()");
                transferStatus = I2C_TRANSFER_STATUS_IDLE;
                return false;
        }

    return true;
}


void Put_Stop()
//leaves both pins high
{
	CLRSDA;
	e_delay(20);
	SETSCL;
	e_delay(20);
	SETSDA;
}


bool Reset_I2C()
{
    int n=9;
    
    printf("\nResetting I2C Bus..");
    
    I2C2CONCLR = _I2C2CON_ON_MASK; //Disable I2C2 Module release pins
    SETSCLOUT; //TRISAbits.TRISA2 = 0; //SCL
    SETSDAOUT; //TRISAbits.TRISA3 = 0; //SDA
    SETSCL;  //  LATAbits.LATA2 = 1;
    SETSDA; //LATAbits.LATA3 = 1; //Set Both to '1'

    Put_Stop();
    
    SETSDAIN;
  //If SDA is stuck to Gnd  
    if(!CheckSDA) //clock SCL 9 times or till SDA is released 
    {
        do
        {
            CLRSCL;
            e_delay(20);
            SETSCL;
            n--;
        }while((CheckSDA) && (n));
        
        if(!CheckSDA) 
        {
            printf("\nFailed to Reset I2C Bus..");
            I2C2CONSET = _I2C2CON_ON_MASK; //Enable I2C2 Module release pins
            I2C2_Initialize();
            return false; 
        }
      //if SDA is released put a Stop condition
        Put_Stop();
    }
    //if SDA is already 1 then nothing to reset !!
    I2C2CONSET = _I2C2CON_ON_MASK; //Enable I2C2 Module release pins
    I2C2_Initialize();
    return true;
}
