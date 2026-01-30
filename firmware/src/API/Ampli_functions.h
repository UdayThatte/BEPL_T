/* 
 * File:   Ampli_functions.h
 * Author: UT
 *
 * Created on June 9, 2025, 4:37 PM
 */

#ifndef AMPLI_FUNCTIONS_H
#define	AMPLI_FUNCTIONS_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

#include "Amplifier_Com.h"    
#include "CAN_Comm.h"    
#include "System_Configuration.h"
    
typedef struct
{
    uint8_t motor_rotation_direction;
    double GR_motor_to_load;
    double Max_Positive;
    double Max_Negative;
    uint32_t AmplCountForOneRot;
    double Max_Velocity;    //deg/sec 
    double default_Velocity;
    double default_acc; //deg/sec2
}Ampl_Paras;


  
//Error codes
#define POWER_BREAKDOWN				0x3285
#define OVER_TEMP_GENERAL           0x4200
#define OVER_TEMP_ELEX              0x4210    
#define	OVER_TEMP_MOTOR				0x4310
#define	IIT_MOTOR					0x2312
#define	IIT_SERVO_DRIVE				0x2311
#define HOMING_RUN					0x8A80
#define CAN_RX_COMM_ERROR			0x8182
#define ENCO_RESOLVER_ERROR			0x7380
#define LIMIT_SW_ERROR				0x8A84



//returns true-Success false-failed
//in case of failure CAN_state or AmplStatus contains the Error code
//mode- is required mode of operation 
//In case of Position mode,   Default Velocity and acceleration as defined here would be used
//for proper conversion GR (Gear Ration ) is used     
bool Init_Amplifier_old(uint8_t AmplNode,AmplOprMode mode);
bool Init_Amplifier(uint8_t AmplNode,AmplOprMode mode,Ampl_Paras* Paras);

//returns true when Motion is complete
//returns false - if failed due to CAN comm ot Ampl Error response
//in case of failure CAN_state or AmplStatus contains the Error code
//bool Wait_Till_Axis_Is_Moving(uint8_t AmplNode);

//This would read the latest Error from Amplifier and Display the same 
//in user understandable strings, will also send it to Debug Port
//The error code is returned
//0 - No error
//0xffff - No error code can be read )
uint32_t Get_and_Display_Ampl_Error(uint8_t AmplNode,char* ErrorString,char* AmplName);

//When Passed the Error code received from Amplifier this will
//Display the same in user understandable strings, will also send it to Debug Port
void DisplayAmplifier_Error(uint8_t AmplNode,uint32_t ErrCode,char* ErrorString,char* AmplName);

//Current Position of Motor is treated as HOME
///returns false if failed
bool Set_Motor_Home_Position(uint8_t AmplNode);

#ifdef	__cplusplus
}
#endif

#endif	/* AMPLI_FUNCTIONS_H */

