/* 
 * File:   CAN_Enco.h
 * Author: UT
 *
 * Created on April 18, 2025, 1:07 PM
 */

#ifndef CAN_ENCO_H
#define	CAN_ENCO_H

#ifdef	__cplusplus
extern "C" {
#endif

    
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes


#define  AZ_Encode_Node CAN_Node_Encoder0
#define  EL_Encode_Node CAN_Node_Encoder1

    //various Data Objects
#define CURRENT_POSITION    0x2000
#define PRESET_VALUE        0x6003
#define SAVE_PARA          0x2300
    

//Reads the Encoder Current Value At Object 0x2000
//return false - if failed and CAN_sate contains the reason
//return true- Successful
//When successful @CntrPtr 32 bit value would be available
bool Get_Enco_Count_CAN(uint8_t EncoNode,uint32_t* CntPtr);

//Data sheet shows Command 0x22 which is used for unknown no of data bytes
//but as it is known that data is 32bit it is not used here instead 0x23 is used
//Sets the Current Position oas HOME position of the Encoder
//return false- if failed CAN_stat contains the reason code
//true- when successful
bool Set_Zero_For_Enco_CAN(uint8_t EncoNode);

//Saves the Homing position
//Using Obj 0x2300 wit Magic word 0x55aaaa55
//return false- if failed CAN_stat contains the reason code
//true- when successful
bool Save_Parameters_To_CAN_Enco(uint8_t EncoNode);


//This is Optional 
//If this is not done then the First read instruction fails Which received a 0x700+Node response 
//But after around 3minutes of Power on the encoder sends out this bootup message and then you can read encoder

//ADR : 0x000  DLC 0x02 01 NN where NN is node number 01,02,03
//response is 0x700+Node DLC 01  Data:00
//If this bootup message is already transmitted by Encoer then it send TPDO with COB 0x180+Node
//in both cases Value recevied is Zero indicating that Encoder is Booted and operational
bool Send_Start_NMT(uint8_t EncoNode,uint32_t* ReadValueptr);

bool Send_Preop_NMT(uint8_t EncoNode,uint32_t* ReadValueptr);

void Reset_CAN_Enco(uint8_t EncodeNode);

#ifdef	__cplusplus
}
#endif

#endif	/* CAN_ENCO_H */

