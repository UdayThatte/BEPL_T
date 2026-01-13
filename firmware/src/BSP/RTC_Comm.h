/*
 * RTC_Kinetis.H
 *
 *  Created on: Mar 27, 2013
 *      Author: Uday
 */

#ifndef __RTC_KINETIS_H_
#define __RTC_KINETIS_H_

#ifdef	__cplusplus
extern "C" {
#endif

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

//Following definitions are used for Resetting the I2C Bus in case of some issue.
//Pins are used as GPIO    
#define SETSDA 		(LATASET = (1<<3))
#define CLRSDA 		(LATBCLR = (1<<3))
#define SETSDAOUT	(TRISACLR = (1<<3))
#define SETSDAIN	(TRISASET = (1<<3))

#define SETSCL 		(LATASET = (1<<2))
#define CLRSCL 		(LATBCLR = (1<<2))
#define SETSCLOUT 	(TRISACLR = (1<<2))

#define CheckSCL 	GPIO_PinRead(GPIO_PIN_RA2)
#define CheckSDA	GPIO_PinRead(GPIO_PIN_RA3)
    
typedef union Address
  {
    uint32_t complete;
    uint8_t ArrValue[4];
    struct
    {
      uint16_t low;
      uint16_t high;        
    }Words;
    struct
    {
      uint8_t ll;
      uint8_t lh;
      uint8_t hl;
      uint8_t hh;
    }Bytes;
    
}AddressType; //used for storing and retriving data from SRAM (32bit wide data))


typedef struct {                       /* Structure used for time operation */
  uint8_t Second;                     /* seconds (0 - 59) */
  uint8_t Minute;                     /* minutes (0 - 59) */
  uint8_t Hour;                       /* hours (0 - 23) */
  uint8_t DayOfWeek;                  /* day of week (0-Sunday, .. 6-Saturday)  */
  uint8_t Day;                        /* day (1 - 31) */
  uint8_t Month;                      /* month (1 - 12) */
  uint8_t dummy;    //make boudary of 4 byte
  uint8_t dummy1;   //for the next element
  uint32_t Year;                       /* year */
} USER_RTC_Time; //user defined used in all higher level prgms which is in Binary

typedef struct {                       /* Structure used for time operation */
  uint8_t Second;                     /* seconds (0 - 59) */
  uint8_t Minute;                     /* minutes (0 - 59) */
  uint8_t Hour;                       /* hours (0 - 23) */
  uint8_t DayOfWeek;                  /* day of week (0-Sunday, .. 6-Saturday)  */
  uint8_t Day;                        /* day (1 - 31) */
  uint8_t Month;                      /* month (1 - 12) */
  uint8_t Year;                       /* year  20xx */
  uint8_t dummy;    //make boudary of 4 byte
} RTC_Time; //used for HAL for IC whic is BCD


typedef enum {
    RTC_OK,
    RTC_Comm_Failed,
    RTC_Comm_timeout,
    RTC_Clock_Failed        
} RTC_Err;


typedef bool (*RTC_CALLBACK) (RTC_Time*  parameter);

typedef bool (*RTC_ICALLBACK)();

typedef struct
{
    uint8_t                address;
    RTC_ICALLBACK       initcallback;
    RTC_CALLBACK           gettimecallback;
    RTC_CALLBACK           settimecallback;
    RTC_Time*              parameter;
    uint8_t               ramstart; //if 0 means no RAM
    uint8_t               ramlength;// no of Ram bytes  

} RTC_OBJ;

#define TimeOutI2C 4 //mutliple of 50mSec


                         //0x68 DS13xx
#define PCF_RTC_DEV_ADR 0x51 //0x51 PCF8563 85063 but 8563 DOES NOT HAVE RAM BYTE
//CONTROL WORD  0X00 AT  THIS STAGE NO CORRECTION
#define PCF_CONTRL_1 0x0
#define PCF_CONTRL_2 0x1
#define PCF_Offset 0x2
#define PCF_RAM 0x3

#define PCF_Reg_RTCSEC 0x04
#define PCF_Reg_RTCMIN 0x05
#define PCF_Reg_RTCHr 0x06
#define PCF_Reg_RTCDATE 0x04
#define PCF_Reg_RTCWDAY 0x03
#define PCF_Reg_RTCMTH 0x05
#define PCF_Reg_RTCYR 0x06

//---------------------------------------
#define MCP_RTC_DEV_ADR 0x6f //     MCP7940 /79400

#define MCP_Reg_RTCSEC 0x00
#define MCP_Reg_RTCMIN 0x01
#define MCP_Reg_RTCHr 0x02
#define MCP_Reg_RTCWDAY 0x03
#define MCP_Reg_RTCDATE 0x04
#define MCP_Reg_RTCMTH 0x05
#define MCP_Reg_RTCYR 0x06
#define MCP_Reg_RTCCNTRL 0x07
#define MCP_Reg_RTCOSCTRM 0x08
#define MCP_Reg_RTCEEUNLOCK 0x09 //only for 79401/2 variant

#define MCP_RTC_CNTRL_EXTOSC_MASK 0x08 //alarm functionality not used

#define MCP_RTC_SRAM_START 0x20 //onwards 64 bytes

#define MCP_RTC_VBATENB_MASK 0x08 //in wkday
#define MCP_RTC_OSC_STATUS_MASK 0x20 //in wkday
#define MCP_RTC_OSC_START_MASK 0x80 //in sec

#define MCP_RTC_EEPR_ADR 0x57
//---------------------------------------



bool Init_RTC();
bool RTC1_GetTime(RTC_Time *Time);
bool RTC1_SetTime(RTC_Time *Time);

bool MCP_Init_RTC();
bool MCP_RTC1_GetTime(RTC_Time *Time);
bool MCP_RTC1_SetTime(RTC_Time *Time);

bool PCF_Init_RTC();
bool PCF_RTC1_GetTime(RTC_Time *Time);
bool PCF_RTC1_SetTime(RTC_Time *Time);

void Put_Stop();
//this Sends Sequence on RTC to reset the Bus
//if Bus is stucked then Error is sent on Console
bool Reset_I2C();
#ifdef	__cplusplus
}
#endif


#endif /* RTC_KINETIS_H_ */
