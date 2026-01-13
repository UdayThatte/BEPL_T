/* 
 * File:   Events.h
 * Author: UT
 *
 * Created on April 18, 2025, 1:11 PM
 */

#ifndef EVENTS_H
#define	EVENTS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

void I2C2_I2cXferDone( uintptr_t context);
void ETH_Port1_OnBlockReceived( uintptr_t context);
void ETH_Port0_OnBlockReceived( uintptr_t context);
void ETH_Port1_OnBlockSent( uintptr_t context);
void ETH_Port0_OnBlockSent( uintptr_t context);
void Intr1Msec(uint32_t status, uintptr_t context);
void CAN_InterruptHandler(uintptr_t context);
void ADC_ResultHandler(uintptr_t context);


#ifdef	__cplusplus
}
#endif

#endif	/* EVENTS_H */

