/* 
 * File:   Para_Calculations.h
 * Author: UT
 *
 * Created on December 24, 2025, 5:36 PM
 */

#ifndef PARA_CALCULATIONS_H
#define	PARA_CALCULATIONS_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

#include "Ampli_functions.h"
//#include "Enco_Handling.h" 
    
typedef struct
{
    bool IsitGrayCode;
    int8_t direction;
    uint32_t revBits;
    uint32_t angBits;
    uint32_t gearRatio;
}EncoderParas_t;

//Deprecated NOW used for single turn in early stages
//Input EncoReading - Count Receied from Encoder
//Returns  angle-Angle of the load
void Get_Paras_12Bit_Encoders(uint32_t EncoReading,double* angle,uint16_t GearRatio);


//new structure based
//All following routines would get the Count to be loade in amplifier
//Depending upon the parameter structure passed  Paras
uint32_t Get_Count_Accl_Deccl_deg(double Accl,Ampl_Paras* Paras);
uint32_t Get_Count_Accl_Deccl_RPM(double Accl,Ampl_Paras* Paras);
uint32_t Get_Pos_Count_ForAmp(double difftogo,Ampl_Paras* Paras);
uint32_t Get_Vel_Count_ForAmp_degSec(double Velocity,Ampl_Paras* Paras);
uint32_t Get_Vel_Count_ForAmp_RPM(double Velocity,Ampl_Paras* Paras);
uint32_t Get_Accl_Deccl_Count_Foramp(double Accl,Ampl_Paras* Paras);

//Returns the Angle of Azimuth 0-360 when Raw Data is passed 
//This takes care of single and Multi turn encoders
//The parameter EncoderParas_t will be used for calculation
double Encoder_ComputeAbsLoadAngle(uint32_t raw,EncoderParas_t* Paras);

#ifdef	__cplusplus
}
#endif

#endif	/* PARA_CALCULATIONS_H */

