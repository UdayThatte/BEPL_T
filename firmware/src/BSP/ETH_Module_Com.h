/* 
 * File:   ETH_Module.h
 * Author: UT
 *
 * Created on April 18, 2025, 1:23 PM
 */

#ifndef ETH_MODULE_H
#define	ETH_MODULE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <string.h>    
#include "definitions.h"                // SYS function prototypes
    
//Port0 UART4 is DataPort //for UNI boards For Old Board UART1 is used
//Port1 UART3 is AT command Port
    
//returns true- if successful false-failed
//response received is available in Com_Buffer[]
//global variable IN_AT_BUF indicates no of characters received
//CmdStr - pointer to Command to be sent
//RespStr - pointer to Expected response to this command
//mSecTmout - Timeout in milliseconds before which a response is expected else error is declared    (returns false))
bool Send_AT_Cmd_To_ETH(char* CmdStr,char* RespStr,int mSecTmout);

//Sends string to the ETH port UART
//SndStr- pointer to String to Send
//NoOfChars - no of characters to send
//This is used as you can send byte data and not only Character string data.
void Send_DATA_Str_to_ETH(uint8_t* SndStr,int NoOfChars);

#ifdef	__cplusplus
}
#endif

#endif	/* ETH_MODULE_H */

