
#include "CAN_Enco_Com.h"
#include "Events.h"
#include "CAN_Comm.h"

extern volatile CAN_APP_STATES CAN_state;
extern volatile int TmOut;


bool Get_Enco_Count_CAN(uint8_t EncoNode,uint32_t* CntPtr)
{
     return Read_CAN_Object(EncoNode,CURRENT_POSITION,0x0,Data_32Bit,FIFO_Enco_0+(EncoNode - CAN_Node_Encoder0),CntPtr);
}

bool Set_Zero_For_Enco_CAN(uint8_t EncoNode)
//Data sheet shows Command 0x22 which is used for unknown no of data bytes
//but as it is known that data is 32bit it is not used here instead 0x23 is used
{
    return Write_CAN_Object(EncoNode,PRESET_VALUE,0,Data_32Bit,0x0,FIFO_Enco_0+(EncoNode - CAN_Node_Encoder0));
}

//saves the parameters
bool Save_Parameters_To_CAN_Enco(uint8_t EncoNode)
//Sub Index 01 is to be used for Saving the para
{
    
    //0x55AA55AA Pg41 manual
    return Write_CAN_Object(EncoNode,SAVE_PARA,0,Data_32Bit,0x55aaaa55,FIFO_Enco_0+(EncoNode - CAN_Node_Encoder0));
}


//This is Optional 
//ADR : 0x000  DLC 0x02 01 NN where NN is node number 01,02,03
//response is 0x700+Node DLC 01  Data:00
//If this bootup message is already transmitted by Encoer then it send TPDO with COB 0x180+Node
//in both cases Value recevied is Zero indicating that Encoder is Booted and operational
bool Send_Start_NMT(uint8_t EncoNode,uint32_t* ReadValueptr)
{
    CAN_Tx_Rx_Block blk;
    uint8_t TxCmd[2]={1,EncoNode};
    
    blk.FifoNum = FIFO_RTR_Enco_0+(EncoNode - CAN_Node_Encoder0);
             
    blk.NodeID = EncoNode;   
    blk.CmdToSnd = TxCmd;//no command is to be send
    blk.CmdLength = 2;
    blk.ExpLengthOfRxMsg = 1;
    
   // blk.FifoNum = fifonunm ;
    blk.ResponseTimeoutmSec= 2000;//
    if(!CAN_RTR_Operation(&blk,true))
            return false;
    *(ReadValueptr) = blk.RegValue;
    return true;
    
}

bool Send_Preop_NMT(uint8_t EncoNode,uint32_t* ReadValueptr)
{
    CAN_Tx_Rx_Block blk;
    uint8_t TxCmd[2]={0x81,EncoNode};
    
    blk.FifoNum = FIFO_RTR_Enco_0+(EncoNode - CAN_Node_Encoder0);
             
    blk.NodeID = EncoNode;   
    blk.CmdToSnd = TxCmd;//no command is to be send
    blk.CmdLength = 2;
    blk.ExpLengthOfRxMsg = 1;
    
   // blk.FifoNum = fifonunm ;
    blk.ResponseTimeoutmSec= 2000;//
    if(!CAN_RTR_Operation(&blk,true))
            return false;
    *(ReadValueptr) = blk.RegValue;
    return true;
}

void Reset_CAN_Enco(uint8_t EncodeNode)
{
uint32_t Enco;

        if(!Set_Zero_For_Enco_CAN(EncodeNode))
        {
            printf("\rSetting CAN ZeroFailed..! %d\r\r",CAN_state);
            LongBeep();
        }
            
        else
        {
            //printf("\rSetting Successful..\r\r");                

            if(!Save_Parameters_To_CAN_Enco(EncodeNode))
            {
                printf("\rSaving CAN Para Failed..");                
                LongBeep();
            }
                
            else
            {
                //printf("\rSaving Successful..\r\r");                


            ///***************************************
                printf("\rWaiting for BootUp..\r\r");                
                do
                {
                if(Send_Start_NMT(EncodeNode,&Enco))    
                  printf("\r%08X",Enco);
                else
                   Enco=0xffff;

                delay_mS(1000);
                }while((Enco & 0xff)!=0x0);//Bootup Message 0x0


                ShortBeep();
              //This Process takes roughly 1.2 Sec /sometimes 4-5 seconds also
             //Giving Delay does not solve this because the next command
             //issued would get the NMT message 0x701 which leads to error in SDO operation
           ///***************************************
           }
        }    

}
