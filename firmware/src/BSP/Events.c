
#include "Events.h"
#include "Port_Definitions.h"
#include "CAN_Comm.h"
#include "I2C_Comm.h"
#include "Protocol.h"
#include "KBD_5X8_rd.h"



extern uint16_t ADC_Spr1,ADC_Spr2;
extern volatile  bool ADC_result_ready;


extern volatile bool KeyBoardEnable;
extern volatile uint32_t NoKeyTimeOut;
extern void UserTimer10mSec();
extern volatile int32_t mSecCntr,Countfor1Sec,Cnt1Sec,Countfor10mSec,Count10mSec;
extern volatile int32_t TmOut,Dlycnt;

extern volatile CAN_APP_STATES CAN_state;
extern char ATResponse[];
extern char ETH_AT_Buffer[];
extern uint8_t ETH_DAT_Buffer[];

extern volatile bool rcvdATResp,rcvdETHCmd,XmtETHProgress;
extern volatile int IN_AT_BUF;
extern volatile int IN_DAT_BUF;

extern volatile bool XmtATProgress  ;
extern volatile uint8_t ETH_ByteRcvTimeOutCntr;
extern volatile uint8_t PNDNT_ByteRcvTimeOutCntr;

extern volatile bool I2CXferDone;
extern Protocol_Info ETH_Proto_Ptrs;
extern Protocol_Info PNDNT_Proto_Ptrs;

void I2C2_I2cXferDone(uintptr_t context )
{
    
    I2C_TRANSFER_STATUS* transferStatusEvent = (I2C_TRANSFER_STATUS*)context;

   I2C_ERROR Err;
   Err = I2C2_ErrorGet();
   
   
    if( Err == I2C_ERROR_NONE)
    {

        if (transferStatusEvent)
        {
            *transferStatusEvent = I2C_TRANSFER_STATUS_SUCCESS;
        }
    }
    else
    {

        if (transferStatusEvent)
        {
            *transferStatusEvent = I2C_TRANSFER_STATUS_ERROR;
            
        }
        
        
    }

}

//Port0 UART1 is DataPort
//Port1 UART3 is AT command Port

void ETH_Port1_OnBlockReceived( uintptr_t context)
{
    UART_ERROR err = ETH_AT_PORT_ErrorGet();
    
    
    if(UART_ERROR_NONE == err)
        IN_AT_BUF++;
    else
    {
       printf("\nETM Module AT Port Response %d",err);
       IN_AT_BUF = 0;
       ETH_AT_PORT_ReadAbort();
    }
       
        
    ETH_AT_PORT_Read(&ETH_AT_Buffer[IN_AT_BUF],1);   
   if( strstr(ETH_AT_Buffer,ATResponse)!= NULL ) 
       rcvdATResp = true;
}

void ETH_Port1_OnBlockSent( uintptr_t context)
{
    XmtATProgress = false;
    
}


extern void Process_ETH_Rcv();
void ETH_Port0_OnBlockReceived( uintptr_t context)
{
     
    UART_ERROR err = ETH_DAT_PORT_ErrorGet();
    
    
    if(UART_ERROR_NONE == err)
    {
        if(Is_Proto_Running(&ETH_Proto_Ptrs)) //either not started or processing or error
        {
            IN_DAT_BUF++;   
            Protocol_Receiving_stage(&ETH_Proto_Ptrs);//This function and Timeour is to be initialized after each byte received
            ETH_ByteRcvTimeOutCntr = ByteRcvTimeOutInmSec; 
        }
        //else just ignore the byte
        
    }
    else
    {
        IN_DAT_BUF = 0;
        printf("\nETM Module Data Port Response %d",err);
        ETH_DAT_PORT_ReadAbort();
    }
    
    ETH_DAT_PORT_Read(&ETH_DAT_Buffer[IN_DAT_BUF],1); 
}

void ETH_Port0_OnBlockSent( uintptr_t context)
{
    XmtETHProgress = false;
}


void Intr1Msec(uint32_t status, uintptr_t context)
{
    mSecCntr++;
    if(ETH_ByteRcvTimeOutCntr) 
    {
        ETH_ByteRcvTimeOutCntr--;
        if(!ETH_ByteRcvTimeOutCntr) //if timeout has occured
            Protocol_Frame_done(&ETH_Proto_Ptrs);
    }
    if(PNDNT_ByteRcvTimeOutCntr) 
    {
        PNDNT_ByteRcvTimeOutCntr--;
        if(!PNDNT_ByteRcvTimeOutCntr) //if timeout has occured
            Protocol_Frame_done(&PNDNT_Proto_Ptrs);
    }    
    if(Dlycnt) Dlycnt--;//used by Delay routine
    if(TmOut) TmOut--; //used fro many routine
    NoKeyTimeOut++;
    
    Countfor10mSec++;
    if(Countfor10mSec>=10)
    {
        Countfor10mSec = 0;
        Count10mSec++;
        if(KeyBoardEnable)
            KbdProcessInTimer();
        UserTimer10mSec();
    }
    
    Countfor1Sec++;
    if(Countfor1Sec>=1000) 
    {
        Countfor1Sec=0;
        Cnt1Sec++;
    }
    
        
}


void CAN_InterruptHandler(uintptr_t context)
{
     /* Check CAN Status */
    uint32_t status = CAN1_ErrorGet();
    //if ((status & (CAN_ERROR_TX_RX_WARNING_STATE | CAN_ERROR_RX_WARNING_STATE |
    //               CAN_ERROR_TX_WARNING_STATE | CAN_ERROR_RX_BUS_PASSIVE_STATE |
    //               CAN_ERROR_TX_BUS_PASSIVE_STATE | CAN_ERROR_TX_BUS_OFF_STATE)) == CAN_ERROR_NONE)
    if(status == CAN_ERROR_NONE)
    {
        switch ((CAN_APP_STATES)context)
            {
                case STATE_CAN_RECEIVE:
                        CAN_state =  STATE_CAN_RCV_SUCCESSFUL;
                        break;
                case STATE_CAN_TRANSMIT:
                        CAN_state = STATE_CAN_SEND_SUCCESSFUL;
                        break;
                default:
                    break;
            }
    }
    else
    {
        printf("\nCAN SDO Interrupt Error..");
        CAN_state = STATE_CAN_COMM_ERROR;
    }
    
}

void ADC_ResultHandler(uintptr_t context)
{
    static int AvgCntr = 0;
    
     ADC_result_ready = true;        
     ADC_Spr1 = ADC_ResultGet(ADC_RESULT_BUFFER_0) ;
     ADC_Spr2 = ADC_ResultGet(ADC_RESULT_BUFFER_1) ;
     
}
