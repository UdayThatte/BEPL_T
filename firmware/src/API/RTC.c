
#include "RTC.h"
#include "BCD_Utils.h"

extern volatile uint8_t RTC_Stat;


bool GetMachinesRTC(USER_RTC_Time* MyTime) //MyTime uint8_t 
{
 RTC_Time Time;	
 
	if(RTC1_GetTime(&Time))
    {
	MyTime->Day = BCDtoChar(Time.Day);
	MyTime->Month = BCDtoChar(Time.Month);
	MyTime->Year = ((uint32_t)(BCDtoChar(Time.Year)) + 2000);
	MyTime->DayOfWeek = BCDtoChar(Time.DayOfWeek);
	MyTime->Hour = BCDtoChar(Time.Hour);
	MyTime->Minute = BCDtoChar(Time.Minute);
	MyTime->Second = BCDtoChar(Time.Second);
    return true;
    }
 return false;
}

bool SetMachinesRTC(USER_RTC_Time* MyTime)
{
//LDD_RTC_TTime Time;
 RTC_Time Time;
 
    CharToBCD(MyTime->Day,&Time.Day);
	CharToBCD(MyTime->Month,&Time.Month); 
	CharToBCD((uint8_t)((MyTime->Year)-2000),&Time.Year); 
    CharToBCD(MyTime->DayOfWeek,&Time.DayOfWeek); 
	CharToBCD(MyTime->Hour,&Time.Hour); 
	CharToBCD(MyTime->Minute,&Time.Minute); 
	CharToBCD(MyTime->Second,&Time.Second); 
   
	return RTC1_SetTime(&Time);
    //Time = Time;
		
}

bool Check_Validity_Of_RTC_For_BB(USER_RTC_Time* CheckTime)
{
			
	if  ( ((int)CheckTime->Month > 12 ) || 
		  ((int)CheckTime->Month == 0 ) ||
		  ((int)CheckTime->Day == 0 )   ||
		  ((int)CheckTime->Day > 31 )   ||
		  ((int)CheckTime->Year > 2050) ||
		  ((int)CheckTime->Year < 2025) ||
		  ((int)CheckTime->Hour > 23)   ||
		  ((int)CheckTime->Minute > 59) 
	    )
        return false;
    else //It is observed that Some times due to rise from VBAT to VCC on the Power of RTC chip seconds reg gets corrupted
    {
        if((int)CheckTime->Second > 59)
        {
            CheckTime->Second = 30;
            SetMachinesRTC(CheckTime);
        }
            
        return true;    
    }
        
	 
}

