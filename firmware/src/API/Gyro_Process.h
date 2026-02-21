#ifndef GYRO_PROCESS_H
#define GYRO_PROCESS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <stdio.h>
#include "definitions.h"                // SYS function prototypes
#include "Board_Configuration.h"
#include "Sys_Inits.h"


    
void CommitFrame(uint8_t start);
void GyroParserPush(uint8_t ByteRcvd);
bool Get_Gyro_Data(uint8_t* RcvdData);
void ParserReset();
    
    
#ifdef	__cplusplus
}
#endif
#endif	/* __ETH_NETBURNER_H_ */    