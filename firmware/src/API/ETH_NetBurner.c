#include "ETH_NetBurner.h"
extern char ATResponse[];
extern char ETH_AT_Buffer[];
extern uint8_t ETH_DAT_Buffer[];
extern volatile int IN_DAT_BUF;
extern volatile int IN_PNDNT_BUF;
extern volatile bool rcvdATResp,rcvdETHCmd,XmtProgress;
extern volatile int IN_AT_BUF;


void Exit_ETH_From_AT_Mode()
{
    Send_AT_Cmd_To_ETH("ATO\n","Returning",2500); //manual says 2sec
    delay_mS(50);
    strcat(ETH_AT_Buffer,"\r");    
    printf(ETH_AT_Buffer); 
    delay_mS(200);//Allow to complete response string print
    
}

void Put_ETH_In_AT_Mode()
{
    rcvdATResp = false;
    
        if(!Send_AT_Cmd_To_ETH("+++","OK>",2500))   //manual mentions 2Sec wait
        printf("\rNo Response to AT port..");
    else
        printf(ETH_AT_Buffer); //response received
    delay_mS(200);//Allow to complete response string print
}

void Get_IP_ETH(char* IpStr)
{
   char *posi,*posi1;
   
   if(Send_AT_Cmd_To_ETH("AT#CURIP?\r","OK>",1000)) //Current IP
    {
        posi = strchr(ETH_AT_Buffer,'?');
        posi++;
        posi1 = strchr(ETH_AT_Buffer,'\r');
        strncpy(IpStr,posi,(posi1-posi));
        *(IpStr+(posi1-posi)) = 0x0;
        
        strcat(ETH_AT_Buffer,"\r");
        printf(ETH_AT_Buffer); //to console
    }
    else
    {
     printf("\rNo Response to CURIP");
     *(IpStr) = 0x0;
    }
    
}