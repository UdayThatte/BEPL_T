
#include "ETH_Module_Com.h"
#include "System_Configuration.h"
#include "Utils.h"

extern volatile int TmOut;
extern volatile int IN_AT_BUF ;
extern volatile bool XmtATProgress;
extern volatile bool rcvdATResp,rcvdETHCmd,XmtETHProgress;
extern char ATResponse[];
extern char ETH_AT_Buffer[];
extern char Com_Buffer1[];

void Reset_ETH_Module()
{
    RST_ETH_Clear();
    delay_mS(10);
    RST_ETH_Set();
    delay_mS(5000);
}
bool Send_AT_Cmd_To_ETH(char* CmdStr,char* RespStr,int mSecTmout)
{
 volatile uint32_t starttime,lapsedtime;

    while(XmtATProgress)_nop();//wait till previouis transfer is over may be of no use
    XmtATProgress=true;
 
    memset(ETH_AT_Buffer,0x0,128);
    rcvdATResp = false;
    ETH_AT_PORT_ReadAbort();
    IN_AT_BUF = 0;
    ETH_AT_PORT_Read(&ETH_AT_Buffer[IN_AT_BUF],1);  //prepare for reception
    strcpy(ATResponse,RespStr);
    
    ETH_AT_PORT_Write(CmdStr,strlen(CmdStr));   //No ECHO for +++ But echos all commands  
    
    
    starttime = GetSystemMs();
    do
    {
      if(rcvdATResp)
      {
           return true;
      }
          
        lapsedtime = GetSystemMs() - starttime;
        
    }while(lapsedtime < mSecTmout );
 

        
    return false;
}

void Send_DATA_Str_to_ETH(uint8_t* SndStr,int NoOfChars)
{
        while(XmtETHProgress)
        { _nop();}    //wait if previous data transfer is not complete  
        XmtETHProgress = true;
        ETH_DAT_PORT_Write(SndStr,NoOfChars);

}