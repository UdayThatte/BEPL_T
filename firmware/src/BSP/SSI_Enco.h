/* 
 * File:   Enco.h
 * Author: UT
 *
 * Created on April 16, 2025, 12:53 PM
 */

#ifndef SSI_ENCO_H
#define	SSI_ENCO_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

#define PlsDly 10 //each count 125uS
#define ST_Enc_NoofBits_ToRead_Bin 12
#define ST_Enc_NoofBits_ToRead_Gray 13 //for Single turn gray 13 
#define MT_Enc_NoofBits_ToRead 25 //for MultiTurn 25 bits Not yet tested for Multi Turn   

#define MAX_NO_OF_SSI_CHS 3    
    
#define Clear_Enco0_RST SPR4_Clear()
#define Set_Enco0_RST   SPR4_Set()
    
#define Clear_Enco1_RST SPR5_Clear()    
#define Set_Enco1_RST   SPR5_Set()
    
#define Clear_Enco2_RST SPR6_Clear()    
#define Set_Enco2_RST   SPR6_Set()    
    
    

//Returns Reading of Single Turn Encoder (13bit))
//Value is valid if global variable  SSI_encode_Fault is not Set
//Do not use value of SSI_encode_Fault = true
uint32_t Get_SSI_Enco_Count_ST(uint8_t ChNo,bool IsitGrayCode);//ChNo 0,1,2 

//Returns Reading of Multi Turn Encoder (24bit))
//Value is valid if global variable  SSI_encode_Fault is not Set
//Do not use value of SSI_encode_Fault = true

uint32_t Get_SSI_Enco_Count_MT(uint8_t ChNo,bool IsitGrayCode);


void Reset_SSI_Enco(uint8_t ChNo);

#ifdef	__cplusplus
}
#endif

#endif	/* ENCO_H */

