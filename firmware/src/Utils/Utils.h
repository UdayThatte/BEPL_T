/* 
 * File:   Utils.h
 * Author: UT
 *
 * Created on June 12, 2025, 3:29 PM
 */

#ifndef UTILS_H
#define	UTILS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <strings.h>
#include "definitions.h"                // SYS function prototypes
    

//Returns miliseconds elapsed since system booted
//this rollsvack after 0xFFFFFFFF    
uint32_t GetSystemMs(void);    
    
//Approx (50nS * dly) for  80MHz clock (4 cycles)
//used where very small delay is required
//Like LCD init or SSI 
void e_delay(uint32_t dly);


void delay_mS(int Interval);

//This will get the character if its ready on Debug_port
//will Not wait for character or Enter by the user on the Debug Port
uint8_t Read_stdin_if_ready();

//iternal routines to Convert frey coded data to Binary    
uint32_t grayToBinary(uint32_t gray) ;

char* Replace_char(char* str, char find, char replace) ;


#ifdef	__cplusplus
}
#endif

#endif	/* UTILS_H */

