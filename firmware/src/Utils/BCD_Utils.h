#ifndef __BCD_UTILS_H
#define __BCD_UTILS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

void Asc_To_PackHex_String(char Inp[],unsigned char Out[],int NoOfAscii);

void CharToBCD(unsigned char inp,unsigned char BCDStr[]);
void LongToBCDStr(unsigned long inp,unsigned char BCDStr[] );
void LongToBCDStr3(unsigned long inp,unsigned char BCDStr[] );
void IntToBCDStr(unsigned short int inp,unsigned char BCDStr[]);

unsigned char BCDtoChar(unsigned char inp);
unsigned long BCDStrToUnsignedLong(unsigned char BCDStr[]);
unsigned short int BCD2StrToShortInt(unsigned char BCDStr[]);
unsigned long BCD3StrToLong(unsigned char BCDStr[]);

#ifdef	__cplusplus
}
#endif


#endif
