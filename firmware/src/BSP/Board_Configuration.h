/* 
 * File:   Ampli_functions.h
 * Author: UT
 *
 * Created on June 9, 2025, 4:37 PM
 */

#ifndef BOARD_CONFIGURATION_H
#define	BOARD_CONFIGURATION_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "Project_configuration.h"

//UART1 is used for Debug across all models
//For this Hardware UNI02 U6 is not used 

#ifndef UNI02 
    #ifndef UNI03
        #error "BASE BOARD MUST BE DEFINED IN Project_configuration.h"
    #endif     
#endif
    
//DO NOT MODIFY FOLLOWING DEFINITIONS 
//AS THESE ARE DEPENDANT ON HW UNI02  PCB  
    
#define ETH_AT_PORT_ErrorGet UART3_ErrorGet
#define ETH_AT_PORT_Read UART3_Read
#define ETH_AT_PORT_Write UART3_Write
#define ETH_AT_PORT_ReadAbort UART3_ReadAbort
#define ETH_AT_PORT_ReadCallbackRegister UART3_ReadCallbackRegister
#define ETH_AT_PORT_WriteCallbackRegister UART3_WriteCallbackRegister
    
#define ETH_DAT_PORT_ErrorGet UART4_ErrorGet
#define ETH_DAT_PORT_Read UART4_Read
#define ETH_DAT_PORT_Write UART4_Write
#define ETH_DAT_PORT_ReadAbort UART4_ReadAbort    
#define ETH_DAT_PORT_ReadCallbackRegister UART4_ReadCallbackRegister
#define ETH_DAT_PORT_WriteCallbackRegister UART4_WriteCallbackRegister

#define RS232_0_PORT_ErrorGet UART1_ErrorGet
#define RS232_0_PORT_Read UART1_Read
#define RS232_0_PORT_Write UART1_Write
#define RS232_0_PORT_ReadAbort UART1_ReadAbort    
#define RS232_0_PORT_ReadCallbackRegister UART1_ReadCallbackRegister
#define RS232_0_PORT_WriteCallbackRegister UART1_WriteCallbackRegister

    
#ifdef UNI02    

 #if (PNDNT_Proto_Implemented == true)    
#define PENDANT_PORT_ErrorGet UART5_ErrorGet
#define PENDANT_PORT_Read UART5_Read
#define PENDANT_PORT_Write UART5_Write
#define PENDANT_PORT_ReadAbort UART5_ReadAbort    
#define PENDANT_PORT_ReadCallbackRegister UART5_ReadCallbackRegister
#define PENDANT_PORT_WriteCallbackRegister UART5_WriteCallbackRegister
#else    
#define RS422_0_PORT_ErrorGet UART5_ErrorGet
#define RS422_0_PORT_Read UART5_Read
#define RS422_0_PORT_Write UART5_Write
#define RS422_0_PORT_ReadAbort UART5_ReadAbort    
#define RS422_0_PORT_ReadCallbackRegister UART5_ReadCallbackRegister
#define RS422_0_PORT_WriteCallbackRegister UART5_WriteCallbackRegister
    
#endif

    

#endif

    
/////////////////////////////////////////////////////////////////////////
#ifdef UNI03    

#if (PNDNT_Proto_Implemented == true)
    

#if (PNDNT_PORT == RS422_0)    
    #define PENDANT_PORT_ErrorGet UART5_ErrorGet
    #define PENDANT_PORT_Read UART5_Read
    #define PENDANT_PORT_Write UART5_Write
    #define PENDANT_PORT_ReadAbort UART5_ReadAbort    
    #define PENDANT_PORT_ReadCallbackRegister UART5_ReadCallbackRegister
    #define PENDANT_PORT_WriteCallbackRegister UART5_WriteCallbackRegister
    #define RS422_1_PORT_ErrorGet UART6_ErrorGet
    #define RS422_1_PORT_Read UART6_Read
    #define RS422_1_PORT_Write UART6_Write
    #define RS422_1_PORT_ReadAbort UART6_ReadAbort    
    #define RS422_1_PORT_ReadCallbackRegister UART6_ReadCallbackRegister
    #define RS422_1_PORT_WriteCallbackRegister UART6_WriteCallbackRegister    

#else    
    #define RS422_0_PORT_ErrorGet UART5_ErrorGet
    #define RS422_0_PORT_Read UART5_Read
    #define RS422_0_PORT_Write UART5_Write
    #define RS422_0_PORT_ReadAbort UART5_ReadAbort    
    #define RS422_0_PORT_ReadCallbackRegister UART5_ReadCallbackRegister
    #define RS422_0_PORT_WriteCallbackRegister UART5_WriteCallbackRegister

    #define PENDANT_PORT_ErrorGet UART6_ErrorGet
    #define PENDANT_PORT_Read UART6_Read
    #define PENDANT_PORT_Write UART6_Write
    #define PENDANT_PORT_ReadAbort UART6_ReadAbort    
    #define PENDANT_PORT_ReadCallbackRegister UART6_ReadCallbackRegister
    #define PENDANT_PORT_WriteCallbackRegister UART6_WriteCallbackRegister

#endif //PNDNT_PORT 0
    
    

    
#else //if  PNDNT_Proto_Implemented not implemented   
    
#define RS422_0_PORT_ErrorGet UART5_ErrorGet
#define RS422_0_PORT_Read UART5_Read
#define RS422_0_PORT_Write UART5_Write
#define RS422_0_PORT_ReadAbort UART5_ReadAbort    
#define RS422_0_PORT_ReadCallbackRegister UART5_ReadCallbackRegister
#define RS422_0_PORT_WriteCallbackRegister UART5_WriteCallbackRegister


#define RS422_1_PORT_ErrorGet UART6_ErrorGet
#define RS422_1_PORT_Read UART6_Read
#define RS422_1_PORT_Write UART6_Write
#define RS422_1_PORT_ReadAbort UART6_ReadAbort    
#define RS422_1_PORT_ReadCallbackRegister UART6_ReadCallbackRegister
#define RS422_1_PORT_WriteCallbackRegister UART6_WriteCallbackRegister
    
#endif //  PNDNT_Proto_Implemented      
    
#endif //if uni03
    
#ifdef	__cplusplus
}
#endif

#endif	/* PORT_DEFINITIONS_H */

