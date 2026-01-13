/*
 * AtmelFlashMem_K20.H
 *
 *  Created on: Sep 19, 2012
 *      Author: myself
 */

#ifndef __AtmelFlash_Kinetis_H
#define __AtmelFlash_Kinetis_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

#define AUTOPAGE_ADR 0x3FFFFCUL //2 bytes 
//This assumes 512 bytes per page on safer side
 //actual all parts will have 528 bytes by default
#define AUTOPAGE_CNT 0x3FFFFEUL //2 bytes 

void SPI_SendRcv_Block (uint8_t* InpData,uint8_t* OutData,int NoofChars);
void StoreAutoPageStart(unsigned short PageAdr);
unsigned short GetAutoPageStart(void);
unsigned short GetAutoPageCount();
void StoreAutoPageCount(unsigned short PageAdr);

#ifdef	__cplusplus
}
#endif

#endif
