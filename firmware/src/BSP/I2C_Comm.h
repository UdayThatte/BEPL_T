/* 
 * File:   I2C_Comm.h
 * Author: UT
 *
 * Created on October 25, 2025, 3:08 PM
 */

#ifndef I2C_COMM_H
#define	I2C_COMM_H


#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes


typedef enum
{
    I2C_TRANSFER_STATUS_IN_PROGRESS,
    I2C_TRANSFER_STATUS_SUCCESS,
    I2C_TRANSFER_STATUS_ERROR,
    I2C_TRANSFER_STATUS_IDLE,

} I2C_TRANSFER_STATUS;

#define I2C_Comm_TimeOut    20 //in mSec
//checks on I2C and finds maximum 8 deivces on it 
//returns No of devices found and populate the Array with addresses
//checks Addresses from 0x08 to 0x77 (others are reserved)

//Temp is 0x48 & RTC 0x51 / 0x6f 

//On error prints Error Address on console and returns found addresses


uint8_t Get_I2C2_Adresses(uint8_t* Adrs);


#ifdef	__cplusplus
}
#endif

#endif	/* I2C_COMM_H */

