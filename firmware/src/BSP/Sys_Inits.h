/* 
 * File:   Sys_Inits.h
 * Author: UT
 *
 * Created on December 22, 2025, 5:28 PM
 */

#ifndef SYS_INITS_H
#define	SYS_INITS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

//All system peripherals are to be initialized and all Interrupt vestors are to be inited
//using this 
//this should be the First routine to call in the main ()
void PON_Inits();    
//this checks if the Flash is 4MB or 8MB
//modifies FlashSize and FlashCap variables
void Check_DataFlash();
//Checks if I2C bus is OK
//Finds out if Temp Sensor IC is ok
//and finds out Type of RTC used on the board
void Check_I2C_Bus();


#ifdef	__cplusplus
}
#endif

#endif	/* SYS_INITS_H */

