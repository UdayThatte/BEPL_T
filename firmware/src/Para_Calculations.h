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

//This defined machine dependant Parameters for calculation of Ampl / Enco values
#define    AZ_motor_rotation_direction  1 //decides normal or Reverse Rotation   
#define    AZ_GR_motor_to_load    128// 1 or 128.0//128.0
#define    AZ_Max_Positive         359.99
#define    AZ_Max_Negative         -359.99    
#define    AZ_AmplCountForOneRot   65536UL //Page 65 of manual Factor Group
#define    AZ_Max_Velocity          150.0 // deg/sec
#define    AZ_default_Velocity      140.0	//Max 150.0 deg/Sec (Protocol Ddocument)
#define    AZ_default_acc          190.0	// Unit? deg/Sec2 ?? 
    
#define    EL_motor_rotation_direction  -1 //decides normal or Reverse Rotation
#define    EL_GR_motor_to_load      164.07   //163.07
#define    EL_Max_Postitive         90.0
#define    EL_Max_Negative          -90.0    
#define    EL_AmplCountForOneRot   65536UL    
#define    EL_Max_Velocity           90.0   //deg/sec
#define    EL_default_Velocity       60.0    //Max 90deg/sec (Protocol Ddocument)
#define    EL_default_acc            60.0   //100.0          //240.0
    

//Input EncoReading - Count Receied from Encoder
//Returns  angle-Angle of the load
void Get_Paras_12Bit_Encoders(uint32_t EncoReading,double* angle,uint16_t GearRatio);
void Get_Paras_13Bit_Encoders(uint32_t EncoReading,double* angle,uint16_t GearRatio); //12 bit gray

//Input Diff angle to go in degrees ( -359.99 to 359.99) On destination
//returns Position Count to be loaded to Amp.
//This will clamp the values to these Limits
uint32_t Get_Count_ForAmpAZ(double difftogo);

//Input Diff angle to go in degrees ( -90.0 to 90) On destination
//returns Position Count to be loaded to Amp.
//This will clamp the values to these Limits
uint32_t Get_Count_ForAmpEL(double difftogo);

//Input desired Load side velocity deg/sec 0.1 to 150.0 deg /sec
//Drive is set for unit RPM by default  i.e. =6deg/Sec
//Our unit is deg/sec or deg/Sec sq
uint32_t Get_AZ_Count_Velocity(double Velocity);
uint32_t Get_EL_Count_Velocity(double Velocity);
//Input Accl/deccl in deg/sec sq.
uint32_t Get_AZ_Count_Accl_Deccl(double Accl);
uint32_t Get_EL_Count_Accl_Deccl(double Accl);

#ifdef	__cplusplus
}
#endif

#endif	/* PARA_CALCULATIONS_H */

