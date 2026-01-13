
#include "Para_Calculations.h"

//These routines depend upon the type of encoder Connected / Gear ratio etc for the Project

void Get_Paras_13Bit_Encoders(uint32_t EncoReading,double* angle,double GearRatio) //12 bit gray
{
int Revs;
uint32_t temp;

        Revs = (int)((EncoReading>>13)& 0x0FFF); 
        *angle = (EncoReading & 0x1FFF) * 0.0439;  // enc * (360/8192)
        if(Revs)
        {
         *angle = (Revs * 360.0) + *angle; //total angle
         *angle /= GearRatio; //
         temp = (uint32_t)(*angle * 100);//upto 2 digits only
         temp %= 360;
         *angle = (temp/100.0);
        }
    
}
void Get_Paras_12Bit_Encoders(uint32_t EncoReading,double* angle,double GearRatio) 
{
int Revs;
uint32_t temp;

        Revs = (int)((EncoReading>>12)& 0x0FFF); 
        *angle = (EncoReading & 0x0FFF) * 0.0879;  // enc * (360/4096)
        if(Revs)
        {
         *angle = (Revs * 360.0) + *angle; //total angle
         *angle /= GearRatio; //
         temp = (uint32_t)(*angle * 100);//upto 2 digits only
         temp %= 360;
         *angle = (temp/100.0);
        }
        
}


uint32_t Get_Count_ForAmpAZ(double difftogo)
{
 int Sign=1;
 uint32_t retval;
 
    if(difftogo>AZ_Max_Positive) difftogo = AZ_Max_Positive;
    if(difftogo<AZ_Max_Negative) difftogo = AZ_Max_Negative;
 
    if(difftogo<0)
    {
        Sign=-1;
        difftogo *= Sign;
    }
    
// Find absolute value in Revolutions
    difftogo *= (AZ_GR_motor_to_load * AZ_AmplCountForOneRot);
    difftogo /= 360; //in revolutions
    
    retval = (uint32_t)(difftogo*Sign);
    
    return retval;
    
}
uint32_t Get_Count_ForAmpEL(double difftogo)
{
 int Sign=1;
 uint32_t retval;
 
    if(difftogo>EL_Max_Postitive) difftogo = EL_Max_Postitive;
    if(difftogo<EL_Max_Negative) difftogo = EL_Max_Negative;
 
    if(difftogo<0)
    {
        Sign=-1;
        difftogo *= Sign;
    }
    
// Find absolute value in Revolutions
    difftogo *= (EL_GR_motor_to_load * EL_AmplCountForOneRot);
    difftogo /= 360; //in revolutions
    
    retval = (uint32_t)(difftogo*Sign);
    
    return retval;
    
}

uint32_t Get_AZ_Count_Velocity(double Velocity)
{
    if(Velocity > AZ_Max_Velocity) Velocity = AZ_Max_Velocity;
    
    return (uint32_t)((Velocity * AZ_GR_motor_to_load)/6.0);//??
    
}

uint32_t Get_AZ_Count_Accl_Deccl(double Accl)
{
    if(Accl > AZ_default_acc) Accl = AZ_default_acc;
    
    return (uint32_t)((Accl * AZ_GR_motor_to_load)/6.0);//??
    
}

uint32_t Get_EL_Count_Velocity(double Velocity)
{
  //Drive is in 1 RPM   default  i.e. =6deg/Sec
  //Our unit is deg/sec
    if(Velocity > EL_Max_Velocity) Velocity = EL_Max_Velocity;
    
    return (uint32_t)((Velocity * EL_GR_motor_to_load)/6.0);//??
    
}
uint32_t Get_EL_Count_Accl_Deccl(double Accl)
{
    if(Accl > EL_default_acc) Accl = EL_default_acc;
    
    return (uint32_t)((Accl * EL_GR_motor_to_load)/6.0);//??
    
}

