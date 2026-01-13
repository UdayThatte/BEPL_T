/* 
 * File:   Beeps.h
 * Author: UT
 *
 * Created on September 22, 2021, 1:27 PM
 */


#ifndef BEEPS_H
#define	BEEPS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "toolchain_specifics.h" //for definition of WEAK
//#include "definitions.h"                // SYS function prototypes


void __WEAK LongBeep();
void __WEAK ShortBeep();


#ifdef	__cplusplus
}
#endif

#endif	/* BEEPS_H */

