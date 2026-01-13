/* 
 * File:   RTC.h
 * Author: UT
 *
 * Created on October 23, 2021, 5:48 PM
 */

#ifndef RTC_H
#define	RTC_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

#include "RTC_Comm.h"


bool GetMachinesRTC(USER_RTC_Time* MyTime);
bool SetMachinesRTC(USER_RTC_Time* MyTime);
bool Check_Validity_Of_RTC_For_BB(USER_RTC_Time* CheckTime);

#ifdef	__cplusplus
}
#endif

#endif	/* RTC_H */

