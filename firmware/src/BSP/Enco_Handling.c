#include "Enco_Handling.h"
#include <math.h>

void Encoder_Init(EncoderHandle_t *h,
                  uint32_t firstRaw,
                  uint32_t totalBits,
                  uint32_t cpr,
                  double gearRatio)
{
    h->prevRaw = firstRaw;
    h->accCounts = 0;
    h->initialized = 1;

    h->totalBits = totalBits;
    h->cpr = cpr;
    h->gearRatio = gearRatio;
}

void Encoder_Update(EncoderHandle_t *h, uint32_t raw)
{
    if (!h->initialized)
    {
        h->prevRaw = raw;
        h->accCounts = 0;
        h->initialized = 1;
        return;
    }

    uint32_t maxRaw = 1UL << h->totalBits;

    int32_t diff = (int32_t)(raw - h->prevRaw);

    if (diff >  (int32_t)(maxRaw / 2))
        diff -= maxRaw;
    else if (diff < -(int32_t)(maxRaw / 2))
        diff += maxRaw;

    h->prevRaw = raw;
    h->accCounts += diff;
}

double Encoder_GetTableAngleDeg(const EncoderHandle_t *h)
{
    double encRevs = (double)h->accCounts / h->cpr;
    return (encRevs / h->gearRatio) * 360.0;
}

double Encoder_GetWrappedAngleDeg(const EncoderHandle_t *h)
{
    double a = fmod(Encoder_GetTableAngleDeg(h), 360.0);
    if (a < 0)
        a += 360.0;
    return a;
}

void Encoder_ResetPosition(EncoderHandle_t *h)
{
    h->accCounts = 0;
}