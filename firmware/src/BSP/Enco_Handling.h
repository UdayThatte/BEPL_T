

#ifndef ENCO_HANDLING_H
#define	ENCO_HANDLING_H


#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <string.h>    
#include "definitions.h"                // SYS function prototypes

#ifdef	__cplusplus
extern "C" {
#endif

    
typedef struct
{
    uint32_t prevRaw;
    int64_t  accCounts;     // signed accumulated encoder counts
    uint8_t  initialized;

    uint32_t totalBits;
    uint32_t cpr;          // counts per rev (angle bits)
    double   gearRatio;    // encoder revs per table rev

} EncoderHandle_t;

void Encoder_Init(EncoderHandle_t *h,
                  uint32_t firstRaw,
                  uint32_t totalBits,
                  uint32_t cpr,
                  double gearRatio);

void Encoder_Update(EncoderHandle_t *h, uint32_t newRaw);
double Encoder_GetTableAngleDeg(const EncoderHandle_t *h);
double Encoder_GetWrappedAngleDeg(const EncoderHandle_t *h);
void Encoder_ResetPosition(EncoderHandle_t *h);

#ifdef	__cplusplus
}
#endif

#endif	/* PARA_CALCULATIONS_H */
    