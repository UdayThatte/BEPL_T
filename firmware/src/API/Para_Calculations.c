
#include "Para_Calculations.h"
#include "Ampli_functions.h"
#include <math.h>


void Get_Paras_12Bit_Encoders(uint32_t EncoReading,double* angle,uint16_t GearRatio) 
{
//Following code works for Gear Ratio Power of 2
//This is faster not involving complex calculations    
//uint32_t Countfor1Rev = GearRatio * 4096;
//
//    EncoReading &= 0xFFFFFF; //takes care of MT/ST
//    *angle =   (EncoReading % Countfor1Rev) * (360.0 / Countfor1Rev);
    uint32_t RevRemainder = (EncoReading>>12) % GearRatio;
             RevRemainder *= 360;
             *angle = RevRemainder + (EncoReading & 0xFFF) * 0.0879;   // 360/4096  
             *angle /= GearRatio;
             *angle *= GearRatio;
             
}

///////////////////////////////----------------------------------
uint32_t Get_Count_Accl_Deccl_deg(double Accl,Ampl_Paras* Paras)
{
   if(Accl > Paras->default_acc) Accl = Paras->default_acc;
    return (uint32_t)((Accl * Paras->GR_motor_to_load)/6.0);//??
}

uint32_t Get_Count_Accl_Deccl_RPM(double Accl,Ampl_Paras* Paras)
{
   if(Accl > Paras->default_acc) Accl = Paras->default_acc;
    return (uint32_t)((Accl * Paras->GR_motor_to_load));//??
}

uint32_t Get_Pos_Count_ForAmp(double difftogo,Ampl_Paras* Paras)
{
int Sign=1;
 uint32_t retval;
 
    if(difftogo > Paras->Max_Positive) difftogo = Paras->Max_Positive;
    if(difftogo < Paras->Max_Negative) difftogo = Paras->Max_Negative;
 
    if(difftogo<0)
    {
        Sign=-1;
        difftogo *= Sign;
    }
    
// Find absolute value in Revolutions
    difftogo *= (Paras->GR_motor_to_load * Paras->AmplCountForOneRot);
    difftogo /= 360; //in revolutions
    
    retval = (uint32_t)(difftogo*Sign);
    
    return retval;    
}

uint32_t Get_Vel_Count_ForAmp_degSec(double Velocity,Ampl_Paras* Paras)
{
    if(Velocity > Paras->Max_Velocity) Velocity = Paras->Max_Velocity;
    
    return (uint32_t)((Velocity * Paras->GR_motor_to_load)/6.0);//
}


uint32_t Get_Vel_Count_ForAmp_RPM(double Velocity,Ampl_Paras* Paras)
{
    if(Velocity > Paras->Max_Velocity) Velocity = Paras->Max_Velocity;
    
    return (uint32_t)((Velocity * Paras->GR_motor_to_load));//
}


uint32_t Get_Accl_Deccl_Count_Foramp(double Accl,Ampl_Paras* Paras)
{
    if(Accl > Paras->default_acc) Accl = Paras->default_acc;
    
    return (uint32_t)((Accl * Paras->GR_motor_to_load)/6.0);//??
    
    
}

double Encoder_ComputeAbsLoadAngle(uint32_t raw,EncoderParas_t* Paras)
{
    uint32_t revMask = (1UL << Paras->revBits) - 1;
    uint32_t angMask = (1UL << Paras->angBits) - 1;

    uint32_t encRev = (raw >> Paras->angBits) & revMask;
    uint32_t encAng = raw & angMask;

    int32_t signedRev;

    /* convert to signed for wrap safety */
    if (encRev <= (revMask >> 1))
        signedRev = encRev;
    else
        signedRev = (int32_t)encRev - (int32_t)(revMask + 1);

    double deg =
        ((signedRev % (int32_t)Paras->gearRatio) * 360.0 +
         encAng * (360.0 / (1UL << Paras->angBits))) / Paras->gearRatio;

    if (deg < 0)
        deg += 360.0;
    
    if(Paras->direction == -1)
    {
        deg = 360.0 - deg;
    } 
    return deg;
}


//new to check 080426
double Encoder_ComputeAbsLoadAngle1(uint32_t raw, EncoderParas_t* Paras)
{
    uint32_t revMask = (1UL << Paras->revBits) - 1;
    uint32_t angMask = (1UL << Paras->angBits) - 1;

    uint32_t encRev = (raw >> Paras->angBits) & revMask;
    uint32_t encAng = raw & angMask;

    int32_t signedRev;

    if (encRev <= (revMask >> 1))
        signedRev = encRev;
    else
        signedRev = (int32_t)encRev - (int32_t)(revMask + 1);

    /* total linear position */
    double totalCounts =
        ((double)signedRev * (1UL << Paras->angBits)) + encAng;

    /* scale to 0?360 using gear ratio */
    double deg = totalCounts *
        (360.0 / ((1UL << Paras->angBits) * Paras->gearRatio));

    /* wrap to 0?360 */
    deg = fmod(deg, 360.0);
    if (deg < 0)
        deg += 360.0;

    if (Paras->direction == -1)
        deg = 360.0 - deg;

    return deg;
}