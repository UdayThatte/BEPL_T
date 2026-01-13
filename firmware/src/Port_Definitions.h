/* 
 * File:   Ampli_functions.h
 * Author: UT
 *
 * Created on June 9, 2025, 4:37 PM
 */

#ifndef PORT_DEFINITIONS_H
#define	PORT_DEFINITIONS_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <p32xxxx.h>
#include <sys/kmem.h>
#include "definitions.h"                // SYS function prototypes

#define EN_RL_BUF_Clear() _nop() //dummy for this hw of BEPL
#define EN_RL_BUF_Set() _nop() //dummy for this hw  of BEPL
    
#define ETH_AT_PORT_ErrorGet UART3_ErrorGet
#define ETH_AT_PORT_Read UART3_Read
#define ETH_AT_PORT_Write UART3_Write
#define ETH_AT_PORT_ReadAbort UART3_ReadAbort
#define ETH_AT_PORT_ReadCallbackRegister UART3_ReadCallbackRegister
#define ETH_AT_PORT_WriteCallbackRegister UART3_WriteCallbackRegister
    
#define ETH_DAT_PORT_ErrorGet UART1_ErrorGet
#define ETH_DAT_PORT_Read UART1_Read
#define ETH_DAT_PORT_Write UART1_Write
#define ETH_DAT_PORT_ReadAbort UART1_ReadAbort    
#define ETH_DAT_PORT_ReadCallbackRegister UART1_ReadCallbackRegister
#define ETH_DAT_PORT_WriteCallbackRegister UART1_WriteCallbackRegister


#ifdef	__cplusplus
}
#endif

#endif	/* PORT_DEFINITIONS_H */

