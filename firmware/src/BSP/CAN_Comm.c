
#include "CAN_Comm.h"
#include "Events.h"
#include "device.h"

extern volatile CAN_APP_STATES CAN_state;
extern volatile int32_t TmOut;
extern uint32_t CAN_SDO_RESP_ERROR;


bool CAN_RTR_Operation(CAN_Tx_Rx_Block* CanMsg,bool IsNMT)
{
    uint8_t CAN_rxMsgLength=0,CAN_Msg[16];
    uint32_t CAN_rx_messageID;
    uint16_t timestamp;
    CAN_MSG_RX_ATTRIBUTE msgAttr= CAN_MSG_RX_DATA_FRAME;
    uint32_t RetVal=0;
  
  
    CAN1_MessageAbort(CanMsg->FifoNum);// FIFO cleared because in SDO mode for every query there is Answer
    
    
    memset(CAN_Msg,0x0,sizeof(CAN_Msg)); 
    CAN_state = STATE_CAN_IDLE;
    
    if(CanMsg->CmdLength) //if command to send
    {
        CAN1_CallbackRegister(CAN_InterruptHandler,(uintptr_t)STATE_CAN_TRANSMIT,7); //transmit interrupt is expected
        if(IsNMT) //for NMT message Adress is 0x0
            CAN1_MessageTransmit(0x0, CanMsg->CmdLength, CanMsg->CmdToSnd, 7, CAN_MSG_TX_DATA_FRAME);//Fifo 7 is fixed for Sending
        else    
            CAN1_MessageTransmit(CAN_Base_Adress+0x100+CanMsg->NodeID, CanMsg->CmdLength, CanMsg->CmdToSnd, 7, CAN_MSG_TX_REMOTE_FRAME);//Fifo 7 is fixed for Sending
        //wait while message is transmitted
        //No interrupt is generated for RTR !!!
        
        //delay_mS(CanMsg->ResponseTimeoutmSec);//
        
            TmOut = 50;//50msec timeout
                    while ((CAN_state!=STATE_CAN_COMM_ERROR) && (CAN_state!=STATE_CAN_SEND_SUCCESSFUL))
                    {
                        if(TmOut==0) //timeout has occured
                        {
                            printf("\nError CAN1 Xmt1!..");
                            CAN_state = CAN_XMT_TIMEOUT;
                            return false;
                            break;
                        }
                    }

        CAN_state = STATE_CAN_IDLE;
    }

        
    CAN1_CallbackRegister(CAN_InterruptHandler,(uintptr_t)STATE_CAN_RECEIVE,CanMsg->FifoNum); //prepare for Receive response
    CAN1_MessageReceive(&CAN_rx_messageID, &CAN_rxMsgLength, CAN_Msg, &timestamp,(uint8_t)CanMsg->FifoNum, &msgAttr);    
    //delay_mS(CanMsg->ResponseTimeoutmSec);//
        TmOut = CanMsg->ResponseTimeoutmSec;//
            while ((CAN_state!=STATE_CAN_COMM_ERROR) && (CAN_state!=STATE_CAN_RCV_SUCCESSFUL))
            {
                if(TmOut==0) //timeout has occured
                {
                    printf("\nError CAN1 Rcv1!..");
                    CAN_state = CAN_XMT_TIMEOUT;
                    return false;
                    break;
                }
            }
    
    //in case of Read/Write Error 0x80 is returned as Response Token and length is 8 irrespective of expected bytes
     if(CAN_rxMsgLength != CanMsg->ExpLengthOfRxMsg) 
        {
            CAN_state = CAN_RCV_FORMAT_ERROR;
            return false;
        }

//       if(CAN_rxMsgLength !=1)          
//       {
//           CAN_state = CAN_RCV_FORMAT_ERROR;
//           return false;
//       }
        CanMsg->RegValue = (uint32_t)(CAN_Msg[0]);//only one byte is received for this message
        CAN_state = STATE_CAN_IDLE; //response if successful
        return true;
}


bool Write_CAN_Object(uint8_t Node,uint16_t ObjAdr,uint8_t SubIdx,DataBits NoofBits,uint32_t DataToWrite,FIFO_No_for_Resp fifonunm)
{
    int32_t RetVal;
    CAN_Tx_Rx_Block blk;
    uint8_t TxCmd[] = {0x0,(ObjAdr & 0xff),(ObjAdr>>8)&0xff,SubIdx,
                        (DataToWrite & 0xff),
                        ((DataToWrite>>8) & 0xff),
                        ((DataToWrite>>16) & 0xff),
                        ((DataToWrite>>24) & 0xff),
                        }; 
    uint8_t RxMsg[] = {(ObjAdr & 0xff),(ObjAdr>>8)&0xff,SubIdx};
    
   //Write command depends upon no of bits in the Data to write 
        switch(NoofBits)
    {
        case Data_8Bit:
            TxCmd[0] = CAN_Wr_Cmd_8Bit;
            blk.CmdLength = 4 + 1; //4 fixed as Token+Adress+subindex
            break;
        case Data_16Bit:
            TxCmd[0] = CAN_Wr_Cmd_16Bit;
            blk.CmdLength = 4 + 2; 
            break;
        case Data_24Bit:
            TxCmd[0] = CAN_Wr_Cmd_24Bit;
            blk.CmdLength = 4 + 3; 
            break;
        case Data_32Bit:
            TxCmd[0] = CAN_Wr_Cmd_32Bit;
            blk.CmdLength = 4 + 4; 
            break;
    }
        
    blk.NodeID = Node;   //first Amplifier
    blk.CmdToSnd = TxCmd;
    blk. Exp_resp_seq = RxMsg; //usually the DeviceObject Adress and Sub Index
    blk.ExpLengthOfRxMsg = 8;// always returns 8 bytes irrespective of requested bytes only requeste no of bytes are valid)
     blk.Exp_resp_token = Write_RespToken;
    blk.NoOfBits = NoofBits; //there is no response as data so this is Not applicable 
    blk.FifoNum = fifonunm ;
    blk.ResponseTimeoutmSec = CAN_Comm_ResponseTimeOut_In_mSec;
    
    if(!CAN_SDO_Operation(&blk)) return false; 
        //return value has no meaning
    return true;

}
bool Read_CAN_Object(uint8_t Node,uint16_t ObjAdr,uint8_t SubIdx,DataBits NoofBits,FIFO_No_for_Resp fifonunm,uint32_t* ReadValueptr)
{
    int32_t RetVal;
    CAN_Tx_Rx_Block blk;
    uint8_t TxCmd[] = {CAN_Rd_Cmd,(ObjAdr & 0xff),(ObjAdr>>8)&0xff,SubIdx}; 
    uint8_t RxMsg[] = {(ObjAdr & 0xff),(ObjAdr>>8)&0xff,SubIdx};
    
    switch(NoofBits)
    {
        case Data_8Bit:
            blk.Exp_resp_token = Read_RespToken_8Bit;
            break;
        case Data_16Bit:
            blk.Exp_resp_token = Read_RespToken_16Bit;
            break;
        case Data_24Bit:
            blk.Exp_resp_token = Read_RespToken_24Bit;
            break;
        case Data_32Bit:
            blk.Exp_resp_token = Read_RespToken_32Bit;
            break;
    }
    
    blk.NodeID = Node;   //first Amplifier
    blk.CmdToSnd = TxCmd;
    blk.CmdLength = 4; //Fixed for Read Command
    //blk.Exp_resp_token = Read_RespToken_16Bit ;
    blk. Exp_resp_seq = RxMsg; //usually the DeviceObject Adress and Sub Index
    blk.ExpLengthOfRxMsg = 8;// always returns 8 bytes irrespective of requested bytes only requeste no of bytes are valid)
    blk.NoOfBits = NoofBits; //1-8 bit 2-16 bit 3-24bit 4-32 bit for valid value
    blk.FifoNum = fifonunm ;
    blk.ResponseTimeoutmSec = CAN_Comm_ResponseTimeOut_In_mSec;
    
    if(!CAN_SDO_Operation(&blk)) return false;
    *(ReadValueptr) = blk.RegValue;
    return true;

}

uint8_t NoOfMessagesInFIFO(uint8_t fifonum)
{//each register is placed 0x40 bytes apart
    return (uint8_t)( (C1FIFOCI0 + (fifonum*0x40)) & 0x1f) ;//only 5 bits even all higher are 0
}

//in read operation the value is 32bit but returning error will require 64 bit
bool CAN_SDO_Operation(CAN_Tx_Rx_Block* CanMsg)
{
    uint8_t CAN_rxMsgLength,CAN_Msg[16];
    uint32_t CAN_rx_messageID;
    uint16_t timestamp;
    CAN_MSG_RX_ATTRIBUTE msgAttr= CAN_MSG_RX_DATA_FRAME;
    uint32_t RetVal=0;
  
  
    CAN1_MessageAbort(CanMsg->FifoNum);// FIFO cleared because in SDO mode for every query there is Answer
    
    
    memset(CAN_Msg,0x0,sizeof(CAN_Msg)); 
    CAN_state = STATE_CAN_IDLE;
    CAN1_CallbackRegister(CAN_InterruptHandler,(uintptr_t)STATE_CAN_TRANSMIT,0); //transmit interrupt is expected

    CAN1_MessageTransmit(CAN_Base_Adress+ CanMsg->NodeID, CanMsg->CmdLength, CanMsg->CmdToSnd, 0, CAN_MSG_TX_DATA_FRAME);//Fifo 0 is fixed for Sending
    //wait while message is transmitted
    TmOut = 5;//50msec timeout
    while ((CAN_state!=STATE_CAN_COMM_ERROR) && (CAN_state!=STATE_CAN_SEND_SUCCESSFUL))
    {
        if(TmOut==0) //timeout has occured
        {
            printf("\nError CAN1 Xmt!..");
            CAN_state = CAN_XMT_TIMEOUT;
            return false;
            break;
        }
            
    }
///
        CAN_state = STATE_CAN_IDLE;

    if(CanMsg->ExpLengthOfRxMsg == 0) 
        return false;
        
    CAN1_CallbackRegister(CAN_InterruptHandler,(uintptr_t)STATE_CAN_RECEIVE,CanMsg->FifoNum); //prepare for Receive response
    CAN1_MessageReceive(&CAN_rx_messageID, &CAN_rxMsgLength, CAN_Msg, &timestamp,(uint8_t)CanMsg->FifoNum, &msgAttr);    
    TmOut = CanMsg->ResponseTimeoutmSec;//
    while ((CAN_state!=STATE_CAN_COMM_ERROR) && (CAN_state!=STATE_CAN_RCV_SUCCESSFUL))
    {
        if(TmOut==0) //timeout has occured
        {
            //if( (CAN_rx_messageID & 0xf00) == 0x700 ) //boot up device 
            //This message is ignored as expected Mask is say 0x581 and receives 0x701
            //so the message is ignore by Chip
          if(CAN_rxMsgLength == 1)
            {
                printf("\nDevice CAN1 Boot!");
                CAN_state = CAN_RCV_BOOT_DEVICE_MSG; //ignore
                return false;
            }

            printf("\nError CAN1 Rcv!..");
            CAN_state = CAN_RCV_TIMEOUT;
            return false;
            break;
        }
    }    

    


    //in case of Read/Write Error 0x80 is returned as Response Token and length is 8 irrespective of expected bytes
                 
         if(CAN_Msg[0] != CanMsg->Exp_resp_token) 
         {
             if(CAN_Msg[0] == Error_RespToken) //0x80
             {
                 CAN_state = CAN_RCV_ERROR_TOKEN;
                 CAN_SDO_RESP_ERROR = ( (uint32_t)(CAN_Msg[7]*65536) + (CAN_Msg[6]*4096) + (CAN_Msg[5]*256) +CAN_Msg[4] );
             }
                 
             else
                CAN_state = CAN_RCV_TOKEN_FAULT;
             
             return false;
         }

         if(CAN_rxMsgLength != CanMsg->ExpLengthOfRxMsg) 
         {
             CAN_state = CAN_RCV_FORMAT_ERROR;
             return false;
         }
                 
    
        if ((CAN_Msg[1]!= *(CanMsg->Exp_resp_seq)) || 
         (CAN_Msg[2]!= *(CanMsg->Exp_resp_seq+1)) || 
         (CAN_Msg[3]!= *(CanMsg->Exp_resp_seq+2))  
         )
    {
        CAN_state = CAN_RCV_FORMAT_ERROR;
        return false;
    }
    CAN_state = STATE_CAN_IDLE; //response if successful
    
    switch(CanMsg->NoOfBits)
    {
        case Data_8Bit: 
             RetVal = (uint32_t)CAN_Msg[4];
             break;
        case Data_16Bit: //16 bit
             RetVal = ( (uint32_t)((uint32_t)CAN_Msg[5]*0x100)+CAN_Msg[4] );//Lo-Hi byte position        
             break;
        case Data_24Bit:
            RetVal = ( (uint32_t)((uint32_t)CAN_Msg[6]*0x10000) + ((uint32_t)CAN_Msg[5]*0x100) +CAN_Msg[4] );
            break;
        case Data_32Bit: //32 bit
             RetVal = ( (uint32_t)((uint32_t)CAN_Msg[7]*0x1000000) + ((uint32_t)CAN_Msg[6]*0x10000) + ((uint32_t)CAN_Msg[5]*0x100) +CAN_Msg[4] );
             break;
    }
    
    CanMsg->RegValue = RetVal;
   return true;

}
