#include "Protocol.h"
#include "System_Configuration.h"
#include "App_Protocol.h"

extern uint32_t EL_Enco_Position; //CAN
extern double EL_Enco_Angle;
extern uint32_t AZ_Enco_Position; //SSI
extern double AZ_Enco_Angle;

extern uint8_t PNDNT_OUT_Buffer[];
extern uint8_t ETH_OUT_Buffer[];
extern volatile int IN_DAT_BUF;
extern uint8_t ETH_DAT_Buffer[];
extern volatile int IN_PNDNT_BUF;//No of Characters received through RS422 port (pendent))
extern uint8_t PNDNT_DAT_Buffer[];//RS422 Port connected to pendent.
extern uint8_t BIT_TX_BYTE;

//uint8_t Resp_Snd_Buf[128];
extern Protocol_Info ETH_Proto_Ptrs;
extern Protocol_Info PNDNT_Proto_Ptrs;
extern uint8_t FC_byte_in_feedback;
//extern uint8_t Status_Byte1_in_feedback;

void Init_Protocol_stack_On_ETH()
{
    ETH_Proto_Ptrs.BufferFor_DataRcv = &ETH_DAT_Buffer[0];
    IN_DAT_BUF = 0;
    ETH_Proto_Ptrs.CharsInRcvBuffer = (int*)&IN_DAT_BUF;
    //ETH_Proto_Ptrs.BufferFor_Response = &Resp_Snd_Buf[0];
    ETH_Proto_Ptrs.Protocol_State = PROTO_INITIATED;
}
void Init_Protocol_stack_On_PNDNT()
{
    PNDNT_Proto_Ptrs.BufferFor_DataRcv = &PNDNT_DAT_Buffer[0];
    IN_PNDNT_BUF = 0;
    PNDNT_Proto_Ptrs.CharsInRcvBuffer = (int*)&IN_PNDNT_BUF;
    //ETH_Proto_Ptrs.BufferFor_Response = &Resp_Snd_Buf[0];
    PNDNT_Proto_Ptrs.Protocol_State = PROTO_INITIATED;
}

void Restart_Proto(Protocol_Info* Proto)
{
    *(Proto->CharsInRcvBuffer) = 0x0;
    Proto->Protocol_State = PROTO_INITIATED;
}

bool Is_Proto_Running(Protocol_Info* Proto)
{
    if( (Proto->Protocol_State == PROTO_INITIATED) ||
        (Proto->Protocol_State == PROTO_DATA_RCV_PROGRESS)         
      )      
        return true;
   return false; 
}

void Protocol_Frame_done(Protocol_Info* Proto)
{
    Proto->Protocol_State = PROTO_FRAME_RCVD;
}

void Protocol_Receiving_stage(Protocol_Info* Proto)
{
    Proto->Protocol_State = PROTO_DATA_RCV_PROGRESS;
}



void Protocol_Chk(Protocol_Info* ProtoStruct)
{
    int n;
    uint8_t Chksm=0;
    
    if ((*(ProtoStruct->BufferFor_DataRcv)== 0x0) ||
        (*(ProtoStruct->CharsInRcvBuffer)== 0x0)  
       )
            return;// PROTO_NOT_INITED; //not intialised
        
    if ( *(ProtoStruct->CharsInRcvBuffer) < MinimumCmdLength)
    {
        *(ProtoStruct->CharsInRcvBuffer) = 0;
        ProtoStruct->Protocol_State = PROTO_FORMAT_ERROR;
        return;
    }
    //check first and last character    
   if( (*(ProtoStruct->BufferFor_DataRcv) != Proto_SOF ) ||
       (*(ProtoStruct->BufferFor_DataRcv + *(ProtoStruct->CharsInRcvBuffer) -1  ) != Proto_EOF )    
      )  
    {
        *(ProtoStruct->CharsInRcvBuffer) = 0;
        ProtoStruct->Protocol_State = PROTO_FORMAT_ERROR;
        return;
    }
    //NN should be no of characters received -4 SOF,CHKSM, EOF, NN
    if( *(ProtoStruct->BufferFor_DataRcv +1) !=  (*(ProtoStruct->CharsInRcvBuffer)-4) )
    {
        *(ProtoStruct->CharsInRcvBuffer) = 0;
        ProtoStruct->Protocol_State = PROTO_FORMAT_ERROR;
        return ;
    }
    //Go for Checking Chksm
    for(n=1;n<(*(ProtoStruct->CharsInRcvBuffer)-2);n++)
        Chksm ^= (uint8_t)(*(ProtoStruct->BufferFor_DataRcv +n));
    
    if(Chksm != *(ProtoStruct->BufferFor_DataRcv +n)) //pointing to Chksm byte
       {
        *(ProtoStruct->CharsInRcvBuffer) = 0;
        ProtoStruct->Protocol_State = PROTO_CHKSM_ERROR;
        return ;
       }
   //here the command format checking is complete Now Can take action 
    ProtoStruct->Protocol_State = PROTO_CMD_RCVD;    
    return;
}

void Send_Response_ETH()
{

   Prepare_fb_string(); //from app_protocol
   Send_DATA_Str_to_ETH(ETH_OUT_Buffer,10);
   
   
}

void Send_Response_PNDNT()
{
//   uint8_t Response[10];
//   uint8_t Chksm=0;
// 
//   PNDNT_OUT_Buffer[0] = Proto_SOF;
//   PNDNT_OUT_Buffer[1] = 0x08;
//   PNDNT_OUT_Buffer[2] = FC_byte_in_feedback;
//   PNDNT_OUT_Buffer[3] = Response[4] = 0x7f;  //TODO Dummy value of 0x7f7f AZ feeddback
//   PNDNT_OUT_Buffer[5] = Response[6] = 0x7f; //TODO Dummy value of 0x7f7f EL feeddback
//   PNDNT_OUT_Buffer[7] = Status_Byte1_in_feedback;
//   PNDNT_OUT_Buffer[8] = BIT_TX_BYTE;
//   PNDNT_OUT_Buffer[9] = 0x0;//spare
//   PNDNT_OUT_Buffer[11] = Proto_EOF;
//   
//    for(int n=1;n<10;n++)
//        Chksm ^= PNDNT_OUT_Buffer[n];
// 
//    PNDNT_OUT_Buffer[8] = Chksm;
  
//TODO After configuring the Port for RS422 (pendent)   
    //Send_DATA_Str_to_PNDNT(PNDNT_OUT_Buffer,12);
   
}