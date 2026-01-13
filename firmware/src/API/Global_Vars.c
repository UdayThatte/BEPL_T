#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

#include "I2C_comm.h"
#include "CAN_Comm.h"
#include "Protocol.h"

//* Following are the current Positions of the Encoders
uint32_t EL_Enco_Position; //CAN now
double EL_Enco_Angle; 

uint32_t AZ_Enco_Position; //SSI now
double AZ_Enco_Angle;

uint32_t EL_Motor_Position;
uint32_t AZ_Motor_Position; //Currently connected Hex value
//*******************************************

volatile bool KeyPressed;
volatile bool KeyBoardEnable;
unsigned char KeyStatus [8];
unsigned char LastStatus [8];
unsigned char CheckStatus [8];

volatile int KeyCounter;
unsigned int KeyCode;
unsigned int kCode;
volatile uint32_t NoKeyTimeOut;


volatile uint8_t RTC_Stat;

volatile bool InputReadEnable;
volatile uint16_t INP_IMG=0;
volatile uint8_t OUT_IMG=0;//Bit7 - OUT7 Bit0-OUT0 
volatile uint8_t BRK_IMG =0;//Bit2..0 for Brake3..1
uint8_t I2C_Addrs[8]={0,0,0,0,0,0,0,0};
unsigned int FlashSize=0,FlashCap=0;
//flash cap 1011-0x0b (2M) 1101-0x0d DB321 (4M) , 1111-0x0f DB624 (8M)

uint8_t FlashInpData[2048];
uint8_t FlashOutData[256];
unsigned int AutoPageCnt;

volatile I2C_TRANSFER_STATUS transferStatus = I2C_TRANSFER_STATUS_IDLE;

//After successful Initialization and poweron wait is done This bit should be set
bool System_Booted = false;
//Timer related
volatile int32_t mSecCntr=0,Countfor1Sec=0,Cnt1Sec=0,Countfor10mSec=0,Count10mSec=0;
volatile int32_t TmOut=0,Dlycnt=0;//TmOut Not to be used in User Programm
//mSecCnt indicates no of interrupts occured
//Countfor1Sec incremented per millisec and reset at 1000
//Cnt1Sec = indicates no of seconds lapsed
//Countfor10mSec incremented every msec
//Count10mSec- indcates no of 10mSec elapsed

//TmOut - intialized for getting response timeout in various functions
//pay attension that it is not nested
//eg it is used on CAN_SDO communication  so any can related calling fucntion should not use this 

//ETH related
char ATResponse[20];//expected  response string to check if response is received got ST command to ETH
volatile int IN_AT_BUF = 0;//No of Characters received through AT port of ETH Module
char ETH_AT_Buffer[128];//ETH AT port received response data stored in this buffer
volatile int IN_DAT_BUF = 0;//No of Characters received through Data port of ETH Module
uint8_t ETH_DAT_Buffer[64];//ETH Data port received response data stored in this buffer
uint8_t ETH_OUT_Buffer[32];
volatile int IN_PNDNT_BUF = 0;//No of Characters received through RS422 port (pendent))
uint8_t PNDNT_DAT_Buffer[128];//RS422 Port connected to pendent.
uint8_t PNDNT_OUT_Buffer[32];
volatile bool Start_ETH_fb = false;
volatile bool rcvdATResp=false,rcvdETHCmd=false,XmtETHProgress=false;
//rcvdATResp  true Received Complete response to AT command
//rcvdETHCmd true Received Command on ETH port
//this should be switched on after complete Protocol is received and Action should be taken based on this flag
//XmtETHProgress - true Transmission to Data port of ETH module is in progress Cleared by interrupt
volatile bool XmtATProgress = false;;//true - AT Command string to ETH is in progress  Cleared by interrupt




//CAN related
volatile CAN_APP_STATES CAN_state = STATE_CAN_IDLE;
uint32_t CAN_SDO_RESP_ERROR;//contain the Error code in case CAN_state is CAN_RCV_ERROR_TOKEN
//Error is recvied as 4 byte array it is converted to uint32_t

//SSI Encoder related
bool SSI_encode_Fault;

//Amplifier related
uint16_t AmplStatus; //Status received from ampl if it is requested by any function
//this is to be checked by the calling function for exact nature of problem
//to determine the cause Amplifier Status Word Definitions masks are to be used

//** This may contain Control Word or any word which is read to take decision in some cases(Contextual))

//Protocol
volatile uint8_t ETH_ByteRcvTimeOutCntr = 0;  
volatile uint8_t PNDNT_ByteRcvTimeOutCntr = 0;  
Protocol_Info ETH_Proto_Ptrs;
Protocol_Info PNDNT_Proto_Ptrs;

uint8_t FC_byte_in_feedback=0x0;
uint8_t Status_Byte1_in_feedback = 0x0;
uint8_t BIT_TX_BYTE=0x0; //used in response to Pendent


uint16_t ADC_Spr1,ADC_Spr2;
volatile bool ADC_result_ready;

