#ifndef __ETH_NETBURNER_H_
#define __ETH_NETBURNER_H_

#ifdef	__cplusplus
extern "C" {
#endif

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <stdio.h>
#include "definitions.h"                // SYS function prototypes
#include "Port_Definitions.h"
#include "Sys_Inits.h"

#include "HW_Testing.h"
#include "Beeps.h"
#include "Events.h"

void Exit_ETH_From_AT_Mode();    
void Put_ETH_In_AT_Mode();
void Get_IP_ETH(char* IpStr);

#ifdef	__cplusplus
}
#endif
#endif	/* __ETH_NETBURNER_H_ */    