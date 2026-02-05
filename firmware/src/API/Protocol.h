/* 
 * File:   Protocol.h
 * Author: UT
 *
 * Created on June 16, 2025, 4:59 PM
 */

#ifndef PROTOCOL_H
#define	PROTOCOL_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

    

#define ByteRcvTimeOutInmSec 10 //TODO 2msec 
//@57600 (from ethernet each byte will take 0.19uS )
//with time ISR of 1 msec +- 1msec error is expected in Timeout calculation So 2 mSec 
//after 4 mSec of last byte received action would be taken    
    //practically the bytes are sent by the GUI at a slow pace
#define MinimumCmdLength 5  //At a minimum SOF,NN,CC,CS,EOF this is minimum command length expected 
#define Proto_SOF 0x24
#define Proto_EOF 0x0d    


typedef enum
{
    PROTO_NOT_INITED,
    PROTO_INITIATED,        
    PROTO_DATA_RCV_PROGRESS, 
    PROTO_FRAME_RCVD,        
    PROTO_CMD_RCVD,
    PROTO_CMD_IN_PROCESS,        
    PROTO_FORMAT_ERROR,
    PROTO_CHKSM_ERROR,
    PROTO_FRAME_TIMEOUT        
}PROTO_STATUS;

typedef struct
{
    uint8_t* BufferFor_DataRcv;
    int* CharsInRcvBuffer ;        
    //uint8_t* BufferFor_Response;
    uint8_t Protocol_State;       
}Protocol_Info;

//Protocol_Info varibale is intialized for
//Pointer to Buffer receiving the data
//Pointer of Count of Rcvd bytes
//Current State of Protocol Commu. as per enum PROTO_STATUS
void Init_Protocol_stack_On_ETH(); //This is used fro ETH DATA port
void Init_Protocol_stack_On_PNDNT();//This is used by RS422 for pendent

//function Indicates End of Request 
//this is to be Called from ISR at the time out of 2mSec after last bytes received
void Protocol_Frame_done(Protocol_Info* Proto);


//fucntion indicate that receiving of data is going on
//This is to be called from ISR after each data byte is received
void Protocol_Receiving_stage(Protocol_Info* Proto);

//This function will check the DAta bytes received as pointed by BufferFor_DataRcv
//with No of characters received as pointed by CharsInRcvBuffer
//This will update Current State of Protocol Commu. as per enum PROTO_STATUS
//to the Protocol_State of the structure Passed
void Protocol_Chk(Protocol_Info* ProtoStruct);

//Separate Response functions are written as no of bytes in response are different
//in both the responses
void Send_Response_ETH();
void Send_Response_PNDNT();

void Restart_Proto(Protocol_Info* Proto);
bool Is_Proto_Running(Protocol_Info* Proto);
#ifdef	__cplusplus
}
#endif

#endif	/* PROTOCOL_H */

