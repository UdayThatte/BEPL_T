/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes


#include "Events.h"
#include "Port_Definitions.h"
#include "CAN_Comm.h"
#include "ETH_Module_Com.h"
#include "Amplifier_Com.h"
#include "Ampli_functions.h"
#include "CAN_Enco_Com.h"
#include "Protocol.h"
#include "Ampli_functions.h"
#include "Para_Calculations.h"
#include "System_Configuration.h"
// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

extern volatile CAN_APP_STATES CAN_state;
extern volatile int TmOut;
extern char ATResponse[];
extern char ETH_AT_Buffer[];
extern uint8_t ETH_DAT_Buffer[];

extern volatile bool rcvdATResp,rcvdETHCmd,XmtProgress;
extern volatile int IN_AT_BUF;

extern volatile bool XmtATProgress  ;
extern bool SSI_encode_Fault;
extern int32_t AmplStatus;

extern Protocol_Info ETH_Proto_Ptrs;
extern Protocol_Info PNDNT_Proto_Ptrs;

extern uint8_t FC_byte_in_feedback;
extern uint8_t Status_Byte1_in_feedback;
extern bool System_Booted ;
//this will be called every 10mSec 
//While application writing no need to modify Event of timer
//User can populate his own code here
volatile int MyTimer=0;
void UserTimer10mSec()
{
    if(!System_Booted) return; //No operation untill System Booted/Initialized
    
    MyTimer++;
    if(MyTimer>10)
    {
        MyTimer = 0;
        Send_Response_ETH();
    }
        
}

void test_SSI_Enco()
{
    
     uint32_t Enco = Get_SSI_Enco_Count_ST(true);//gray code
      
      
        if(!SSI_encode_Fault)
        {
            double Angle = (double) (Enco&0xfff); // make the value floating point
            Angle = 360.0 * Angle / 4096.0; // calculate actual angle
            printf("\rSSI Hex: %3X Angle:%6.2f\r\n",Enco&0xfff,Angle);            
        }
        else
            printf("\r\n SSI Encoder ERROR %d\r\n",CAN_state);
        

}

void test_CAN_Enco()
{
       uint32_t Enco;// = Get_Enco_Count_CAN_ST(1);
       Get_Enco_Count_CAN(AZ_Encode_Node,&Enco);
        if(CAN_state == STATE_CAN_IDLE)
        {
            double Angle = (double) (Enco&0xfff); // make the value floating point
            Angle = 360.0 * Angle / 4096.0; // calculate actual angle
            int Revs = (int)(Enco/4096);
            //printf("\rCAN Hex: %3X Angle:%6.2f\r\n",Enco&0xfff,Angle);            
            printf("\rHex %08X",Enco);
            printf("\rCAN Rev: %d Angle:%6.2f\r\n",Revs,Angle);            
        }
        else
            printf("\r\n CAN ERROR %d\r\n",CAN_state);
       
//      
        uint8_t c = Read_stdin_if_ready();
        
        if(c == 'R')//remote SET Zero request
        {
            if(!Set_Zero_For_Enco_CAN(AZ_Encode_Node))
                printf("\rSetting CAN ZeroFailed..! %d\r\n",CAN_state);
            else
            {
                printf("\rSetting Successful..\r\n");                
                
                if(!Save_Parameters_To_CAN_Enco(AZ_Encode_Node))
                    printf("\rSaving CAN Para Failed..");                
                else
                {
                    printf("\rSaving Successful..\r\n");                
                
                    
                ///***************************************
                    do
                    {
                    Check_Bootup_Enco(AZ_Encode_Node,&Enco);     //This may take roughly 100mSec 
                    }while((Enco & 0x7f)!=0x0);//Bootup Message

                    do
                    {
                    Check_Bootup_Enco(AZ_Encode_Node,&Enco);     //This may take roughly 100mSec 
                    }while((Enco & 0x7f)!=0x7f);//Pre-Operational condition reached

                  //This Process takes roughly 1.2 Sec
                 //Giving Delay does not solve this because the next command
                 //issued would get the NMT message 0x701 which leads to error in SDO operation
               ///***************************************
                }
                    

            }

            
        }
         
}
void Test_VelocityMode()
{
int32_t stat;
    stat = (int32_t)Set_Operating_Mode(AZ_Amplifier,Ampl_VELOCITY_Mode) ;
    if(stat != AMPL_STATE_OK)
    {
        printf("\rMode Set returned %04X\r",stat);
        printf("\rValue received - %04X\r",AmplStatus);
    }
    printf("\rModeSet..\r");
    
    stat = (int32_t)Set_Target_Velocity(AZ_Amplifier,100) ;
    //stat = (int32_t)Set_Target_Velocity(CAN_Node_Amp0,-100) ;
    //stat = (int32_t)Set_Target_Velocity(CAN_Node_Amp0,0) ;
        if(stat != AMPL_STATE_OK)
    {
        printf("\rSpeed Set returned %04X\r",stat);
        printf("\rValue received - %04X\r",AmplStatus);
    }

}

void Test_Positioning(uint8_t AmplNode)
{
    AmplComm_Status stat;
    bool Reached;
    uint32_t timeConsumed = GetSystemMs();
    
    stat = Set_Operating_Mode(AmplNode,Ampl_POSITION_Mode) ;
    if(stat != AMPL_STATE_OK)
    {
        printf("\rMode Set returned %04X\r",stat);
        printf("\rValue received - %04X\r",AmplStatus);
    }
    printf("\rModeSet..\r");

    stat = Set_Target_Position(AmplNode,0x7fffff,true) ;//ffff is one revolution
    if(stat != AMPL_STATE_OK)
    {
        printf("\rTarget Position Set returned %04X\r",stat);
        printf("\rValue received - %04X\r",AmplStatus);
    }
    printf("\rPosition Set..\r");
    stat = Issue_GO_Command(AmplNode,true);
    if(stat != AMPL_STATE_OK)
    {
        printf("\rGO Command returned %04X\r",stat);
        printf("\rValue received - %04X\r",AmplStatus);
    }
    printf("\rGO Issued..%d mSec\r",(GetSystemMs()-timeConsumed));

    Reached = false;
    
    printf("\rWait till target is reached..");
    do
    {
        stat = Check_if_Target_Reached(AmplNode,&Reached);
        if(stat!= AMPL_STATE_OK)
        {
            printf("\rTarget Reached Checking returned %04X\r",stat);
            printf("\rValue received - %04X\r",AmplStatus);
        }
      //printf("\rMoving..");
    }while(!Reached);
    
    printf("\rTaget Reached..");
    
}

void Check_Amplifier()
{
    Init_Amplifier_old(AZ_Amplifier,Ampl_POSITION_Mode);
    Test_Positioning(AZ_Amplifier);
}

int main ( void )
{
    char disp[32];
    int32_t stat;
    //PROTO_STATUS ProtoStat;
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
 
    
    //-- AT Command Port Initialization
    ETH_AT_PORT_ReadCallbackRegister(ETH_Port1_OnBlockReceived,(uintptr_t)NULL);
    ETH_AT_PORT_WriteCallbackRegister(ETH_Port1_OnBlockSent,(uintptr_t)NULL);
    IN_AT_BUF = 0;
    ETH_AT_PORT_Read(&ETH_AT_Buffer[IN_AT_BUF],1);  //Prepare to receive data
    
    //TCP Data Port initialization
    ETH_DAT_PORT_ReadCallbackRegister(ETH_Port0_OnBlockReceived,(uintptr_t)NULL);
    ETH_DAT_PORT_WriteCallbackRegister(ETH_Port0_OnBlockSent,(uintptr_t)NULL);
    ETH_DAT_PORT_Read(&ETH_DAT_Buffer[0],1);   //Prepare to receive data

    //General Purpose Timer Init
    CORETIMER_CallbackSet (Intr1Msec, (uintptr_t)NULL );
    CORETIMER_Start();
    
    
    printf("\rPON wait..");
//ETH module takes time to reset    
    delay_mS(5000);
//ETH module takes time to reset    
    //other wise it does not respond to "+++" but gives response to socket bytes
    printf("\rWait Over..");
    
 
    Send_AT_Cmd_To_ETH("+++","OK>",1200);   //Put ETH in AT mode
    printf(ETH_AT_Buffer); //response received

   
   Init_Protocol_stack_On_ETH();
   Init_Protocol_stack_On_PNDNT();
   
 /////////////////////////////////////////////////////   START   OPERATION
   System_Booted = true;
   printf("\rSystem Initialized");
   Check_Amplifier();
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        //SYS_Tasks ( );
        
        //stat = GetAmplStatus(CAN_Node_Amp0);
        //printf("\rStatus returned %04X\r",stat);
        //printf(disp);
        //test_CAN_Enco();
        //test_SSI_Enco();

        GPIO_RD10_Toggle(); //SPI1_CLK
        if (ETH_Proto_Ptrs.Protocol_State == PROTO_FRAME_RCVD) 
        {
            Protocol_Chk(&ETH_Proto_Ptrs);  
           
           if ( (ETH_Proto_Ptrs.Protocol_State==PROTO_CMD_RCVD) ||
                (ETH_Proto_Ptrs.Protocol_State == PROTO_CHKSM_ERROR)  //in case of Chksm error also response is to be sent!! 
               )    
           {
              //process Cmd and send Response
               if(ETH_Proto_Ptrs.Protocol_State == PROTO_CHKSM_ERROR) //FC byte to be updated
                   FC_byte_in_feedback &= ~CMD_CHKSMOK_MASK;
               else
                   FC_byte_in_feedback |=  CMD_CHKSMOK_MASK;
        
               printf("\r");
               for(int n=0;n<10;n++)
                   printf("%02X ",ETH_DAT_Buffer[n]);
               printf("\r");
               //TODO Process the command for action and Send response or send response and process command??
               //Send_Response_ETH();
               printf("\rCmd Received..") ;
           }
              
           else
              printf("\rProto Returned %d",ETH_Proto_Ptrs.Protocol_State) ; 
            
        }
        
//        if(rcvdETHCmd)
//        {
//          rcvdETHCmd = false;  
//          Send_DATA_Str_to_ETH((uint8_t*)"HelloWorld",10);  
//        }
        //printf("done..");
        delay_mS(500);            
        
        if(rcvdATResp)
        {
            rcvdATResp = false;
            Send_AT_Cmd_To_ETH("AT#CURIP?\r","OK>",100);
            delay_mS(10);//Allow to complete response string
            printf(ETH_AT_Buffer);
            rcvdATResp = false;
            Send_AT_Cmd_To_ETH("ATO\r","Returning",100); 
            delay_mS(10);//Allow to complete response string
            printf(ETH_AT_Buffer);
            rcvdATResp = false;
        }
        
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

