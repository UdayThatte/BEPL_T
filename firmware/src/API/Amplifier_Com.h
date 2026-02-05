/* 
 * File:   Amplifier.h
 * Author: UT
 *
 * Created on June 5, 2025, 8:10 PM
 */

#ifndef AMPLIFIER_H
#define	AMPLIFIER_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

#include "CAN_Comm.h"
    
#define AmplStat_Problem_Mask 0x4f
#define AmplStat_Enable_Mask 0x6f    

//Ampl Control Word Bit Commands
//it2..0    
#define Amp_SHUT_DOWN 0x06 //but voltage not disabled???
#define Amp_QUICKSTOP 0x02    //this frees the holding torqu
#define Amp_DISABLE_VOLTAGE 0x0    
#define Amp_SWITCH_ON 0x07
#define Amp_ENABLE_OPERATION 0x0f
#define Amp_DISABLE_OPERATION 0x07 //But power is not switched off To be used for temp stopping Else use SHUT_DOWN    
///----
//For rising edge of a bit appropriate Control word bit ORing would be required to write into control word    
#define Amp_New_Set_Point_Mask 0x10 //rising edge in Postion/Velocity mode will start the operation    
#define Amp_Change_Position_Immediate 0x20   //bit 5 
#define Amp_Relative_Set_Point 0x40 //bit 6 - Only in Postion Mode 0-Absolute 1 -relative
#define Amp_FAULT_BIT_Mask 0x80 //bit 7 a Rising Edge on this bit is required
#define Amp_Halt_Operation 0x100  //bit 8   
    
    
//Amplifier Status Word Definitions MATTKE
#define NOT_READY_TO_SWITCH_ON  0x00
#define SWITCH_ON_DISABLED      0x40
#define FAULT_REACTION_ACTIVE   0x0f
#define AMPL_FAULT              0x08 //this Group should use AmplStat_Problem_Mask
    
#define READY_TO_SWITCH_ON      0x21
#define SWITCHED_ON             0x23
#define OPERATION_ENABLE        0x27
#define QUICK_STOP_ACTIVE       0x07   //This group should use  AmplStat_Enable_Mask
#define SetPoint_Acknowledge_Mask 0x1000 //Bit12         
#define Target_Reached_Mask     0x400 //Bit 10
#define Timeout_Action_By_AmpInmSec 500    
#define Timeout_Action_GO_AmpInmSec 200  //This depends upon Accelration Set bec checking is done on velocity      

//Ampl Homing Methods Constants
#define HOMING_NORUN      34// 34/35  Compatibility Issue TODO to be chekced sometimes it was working with 35
#define LIMIT_SW_POSITIVE 18
#define LIMIT_SW_NEGATIVE 17    
    

//Object Addresses for MATTKE
#define PRE_DEFINED_ERROR_FIELD 0x1003   
#define CONTROL_WORD   0x6040
#define STATUS_WORD    0x6041
#define MODE_OF_OPERATION 0x6060
#define MODE_OF_OPERATION_DISPL 0x6061
#define POSITION_ACTUAL_VALUE 0x6064
#define VELOCITY_ACTUAL_VALUE 0x606c
#define TARGET_VELOCITY 0x60ff
#define TARGET_POSITION 0x607A   
#define POLARITY 0x607E    
#define TARGET_ACCELERATION 0x6083
#define TARGET_DECELERATION 0x6084
#define HOMING_METHOD 0x6098    

//This is Polarity of Position and Velocity By default Normal Polarity
#define NORMAL_POLARITY 0x0
#define REVERSE_POLARITY 0xc0
    

typedef enum
{
    AMPL_STATE_OK,
    AMPL_CAN_COMM_ERR, //CAN_state indicates reason of this CAN error
    AMPL_OPERATION_NOT_SUCCEEDED //due to Error status received
}AmplComm_Status;

typedef enum
{
    Ampl_POSITION_Mode = 1,
    Ampl_VELOCITY_Mode = 3,
    Ampl_TORQUE_Mode = 4,
    Ampl_HOMING_Mode =6,
    Ampl_Interpolated_POSITION_Mode = 7        
    
}AmplOprMode;
//Pg170


//returns status
//CAN_state contains reason code
AmplComm_Status Disable_Amplifier(uint8_t AmplNode);

//returns true-success false-failed
//CAN_state contains reason code
//Posi - is updated for Position of Motor
bool Get_Actual_Motor_Position(uint8_t AmplNode,int32_t* Posi);

//returns true-success false-failed
//CAN_state contains reason code
//Stat - is updated for Status Word (if successful)
bool GetAmplStatus(uint8_t AmplNode,uint16_t* Stat);

//returns true-success false-failed
//CAN_state contains reason code
//if successful ErrCode is updated for the Latest Error code
bool Get_Amp_Error_if_Any(uint8_t AmplNode,uint32_t* ErrCode);        


//THIS APPLIES TO ALL FUNCTIONS RETURNING enum AmplComm_Status
//return AMPL_STATE_OK is successful
//if returned AMPL_CAN_COMM_ERR then CAN_state contains error code
//if returned AMPL_OPERATION_NOT_SUCCEEDED then 
//global vaiable AmplStatus contains the error response given by ampl

AmplComm_Status Enable_Amplifier(uint8_t AmplNode);

//gets Curent mode of operation
bool GetOperationMode(uint8_t AmplNode,uint8_t* Stat);

//mode- as per enum AmplOprMode
AmplComm_Status Set_Operating_Mode(uint8_t AmplNode,AmplOprMode mode);

//Vel- Target Velocity in speed_units
AmplComm_Status Set_Target_Velocity_Count(uint8_t AmplNode,uint32_t Vel);

//Pos - Position target in position unit
//Isrelative - indicates if Target is relative to current or Absolute
AmplComm_Status Set_Target_Position_Count(uint8_t AmplNode,int32_t Pos,bool IsRelative);

//Accl - Target Acceleration in Accl units
AmplComm_Status Set_Target_Acceleration_Count(uint8_t AmplNode,uint32_t Accl);

//Decl - Target Deceleration in Accl units
AmplComm_Status Set_Target_Deceleration_Count(uint8_t AmplNode,uint32_t Decl);

//ActImmediate - When set the Action will be taken immediately. Else the action to target will be taken
//after first motion  is complete
AmplComm_Status Issue_GO_Command(uint8_t AmplNode,bool ActImmediate);

//Active Halt and waits for Target reached
//Then resets the Halt bit
AmplComm_Status Issue_Halt(uint8_t AmplNode);

//activate Quick stop
bool Issue_Quick_Stop(uint8_t AmplNode);

//Check if Previous Target is reached 
AmplComm_Status Check_if_Target_Reached(uint8_t AmplNode,bool* Reached);

//Get actual speed of motor
//used in Finding if motor is stopped completely in vel mode.
AmplComm_Status Get_ActualSpeed_Count_of_Motor(uint8_t AmplNode,uint32_t* speed);

//true if moving
bool Is_Motor_Moving(uint8_t AmplNode);

//Gives bit4 of Control word a rising edge to start homing
AmplComm_Status Command_For_Homing(uint8_t AmplNode);

//
bool Set_Homing_Method_To_NORUN(uint8_t AmplNode);

//Direction of Rotation of Motor for All commands for Position /Velocity is decided with This obect
//No Need to set it reverse unless required.
//May be ion case StartBoard or Port side it will be required.
AmplComm_Status Set_Polarity_Of_Rotation(uint8_t AmplNode,bool IsReverse);

//Resets the fault status
//calling routine must check if the fault is reset by again checking the fault register
AmplComm_Status Reset_Fault(uint8_t AmplNode);

#ifdef	__cplusplus
}
#endif

#endif	/* AMPLIFIER_H */

