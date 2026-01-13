/* 
 * File:   CAN_Comm.h
 * Author: UT
 *
 * Created on June 5, 2025, 8:12 PM
 */

#ifndef CAN_COMM_H
#define	CAN_COMM_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
    
#define CAN_Base_Adress 0x600  
#define CAN_Node_Encoder0 1
#define CAN_Node_Encoder1 2
#define CAN_Node_Encoder2 3
#define CAN_Node_Amp0 11    
#define CAN_Node_Amp1 12        
#define CAN_Node_Amp2 13        
    
#define CAN_Comm_ResponseTimeOut_In_mSec 1500//Saving parameter of encoder takes more time some times 1.2Sec !!
typedef enum
{
    FIFO_Enco_0 = 1, //FIFO 0 is reserved for SDO send
    FIFO_Enco_1,        
    FIFO_Enco_2,                    
    FIFO_Ampl_0 ,
    FIFO_Ampl_1,
    FIFO_Ampl_2,
    FIFO_Send_RTR,  //FIFO 7 is reserved for NMT(RTR) send
    FIFO_RTR_Enco_0, //seperate FIFO is assigned because Mask for ID is different
    FIFO_RTR_Enco_1,            
    FIFO_RTR_Enco_2,            
    FIFO_RTR_Ampl_0 ,
    FIFO_RTR_Ampl_1,
    FIFO_RTR_Ampl_2,
            
}FIFO_No_for_Resp;

typedef enum
{
    CAN_Rd_Cmd = 0x40 ,
    CAN_Wr_Cmd_8Bit = 0x2f ,
    CAN_Wr_Cmd_16Bit = 0x2b,
    CAN_Wr_Cmd_24Bit = 0x27,          
    CAN_Wr_Cmd_32Bit = 0x23,        
    CAN_Wr_Cmd_Exp = 0x22       //used to preset only  all other commands indicatew no of bytes  
            
}CAN_Cmd_token;
typedef enum
{
    Read_RespToken_8Bit = 0x4f,
    Read_RespToken_16Bit = 0x4b,        
    Read_RespToken_24Bit = 0x47,                
    Read_RespToken_32Bit = 0x43,
    Write_RespToken = 0x60,
    Error_RespToken = 0x80        
}RespToken;

typedef enum
{
    Data_8Bit = 1,
    Data_16Bit,
    Data_24Bit,
    Data_32Bit        
            
}DataBits;

    typedef enum
{
    STATE_CAN_IDLE,     //operational enums
    STATE_CAN_RECEIVE,
    STATE_CAN_TRANSMIT,
    STATE_CAN_COMM_ERROR,
            
    STATE_CAN_SEND_SUCCESSFUL, //any xfr send/received
    CAN_XMT_TIMEOUT,        
            
    STATE_CAN_RCV_SUCCESSFUL,

    CAN_RCV_TIMEOUT,        
    CAN_RCV_FORMAT_ERROR, //no of bytes diferent or expected bytes not received
    CAN_RCV_TOKEN_FAULT,//any response not Listed
    CAN_RCV_ERROR_TOKEN, //received 0x80 as response
    CAN_RCV_BOOT_DEVICE_MSG  
            //when para saving is done response to next command is 1 byte 0x70x boot message NMT message     
            //this Error when received is to be ignored and Operation should continue
} CAN_APP_STATES;

typedef struct
{
  uint8_t NodeID;  //offset from Base ID 0x600
  uint8_t* CmdToSnd;
  uint8_t CmdLength;//DLC
  RespToken Exp_resp_token;
  uint8_t* Exp_resp_seq; //usually the DeviceObject Adress and Sub Index
  uint8_t ExpLengthOfRxMsg;
  DataBits NoOfBits; //1-8 bit 2-16 bit 4-32 bit
  FIFO_No_for_Resp FifoNum;//for Xmt FIFO 0  for Encoders Rcv1,2,3,  for Amplifiers 4,5,6 
  uint8_t dummy;
  uint8_t dummy1;
  uint32_t RegValue;
  int ResponseTimeoutmSec;
}CAN_Tx_Rx_Block;

//Performs SDO operation on CAN bus
//returns true or false if successful or not
//CAN_state indicates if the operation is successful or NOT
//CAN_Idle indicates successful
//
//If the CAN_state is set to CAN_Rcv_ERROR_TOKEN (0x80)
//then global variable CAN_SDO_RESP_ERROR will contain 32 bit error code (Pg30 of CAN manual)
bool CAN_SDO_Operation(CAN_Tx_Rx_Block* CanMsg);

//returns true or false if successful or not
//Send NMT Message 0x70x in RTR mode and gets the response
//If IsNMT flag is set then Adress is set to 0x0
//CAN_state indicates if the operation is successful or NOT
bool CAN_RTR_Operation(CAN_Tx_Rx_Block* CanMsg,bool IsNMT);
//
//returns true-Success false-unsuccessful
//Updates Value of the parameter requested in ReadValue
//CAN_state contains cause of failure
bool Read_CAN_Object(uint8_t Node,uint16_t ObjAdr,uint8_t SubIdx,DataBits NoofBits,FIFO_No_for_Resp fifonunm,uint32_t* ReadValue);

//returns true-Success false-unsuccessful
//CAN_state contains cause of failure
//Reason of the error is in CAN_state
bool Write_CAN_Object(uint8_t Node,uint16_t ObjAdr,uint8_t SubIdx,DataBits NoofBits,uint32_t DataToWrite,FIFO_No_for_Resp fifonunm);

//This function Not used for NOW
//in SDO mode for every Query there is response so practically no FIFO is required
//Pg28 of manual
//"The object dictionary can be accessed with Service Data Objects (SDO).
//This access is particularly easy and clear. 
//Therefore it is recommended to base the application on SDOs first and later adapt some accesses 
//to the certainly faster but more complicated Process Data Objects (PDOs)."
uint8_t NoOfMessagesInFIFO(uint8_t fifonum);
    



#ifdef	__cplusplus
}
#endif

#endif	/* CAN_COMM_H */

