/* 
 * File:   BoardTemp.h
 * Author: UT
 *
 * Created on October 25, 2025, 2:48 PM
 */

#ifndef BOARDTEMP_H
#define	BOARDTEMP_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

#define TempI2CAdr 0x48 //I2C address of TMP1075
#define Mulfactor_TMP1075 0.0625

bool Get_Temp(float* Temp);

#ifdef	__cplusplus
}
#endif

#endif	/* BOARDTEMP_H */

