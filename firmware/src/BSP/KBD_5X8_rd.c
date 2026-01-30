/*
 * KBD_6X5_Kinetis.C
 *
 *  Created on: Sep 19, 2012
 *      Author: myself
 */
#include "KBD_5X8_rd.h"
#include "System_Configuration.h"

extern void CheckKey ();
extern unsigned char KeyStatus [];
extern void e_delay (uint32_t eDel);
extern volatile uint8_t INP_IMG1; //for extended Inputs through RL lines

void KbdProcessInTimer()
{
    
#if (Keybaord_Used == true)
    EN_RL_BUF_Clear();
	//As only 4 return lines are present Oring 0xf0 
    SCAN1_Set();
	e_delay(1);
#if (Only_4_Return_Lines == true)
    KeyStatus[0] = (~(unsigned char)(GPIO_PortRead(GPIO_PORT_D)>>1)) | 0xf0;
    INP_IMG1 = (unsigned char)(GPIO_PortRead(GPIO_PORT_D)>>1) & 0xf0; //Extended inputs updated
#else    
    KeyStatus[0] = (~(unsigned char)(GPIO_PortRead(GPIO_PORT_D)>>1));
#endif    
	SCAN1_Clear();

		
	//
    SCAN2_Set();
	e_delay(1);
#if (Only_4_Return_Lines == true)    
    KeyStatus [1] = (~(unsigned char)(GPIO_PortRead(GPIO_PORT_D)>>1)) | 0xf0 ;
#else    
    KeyStatus[1] = (~(unsigned char)(GPIO_PortRead(GPIO_PORT_D)>>1));
#endif    
	SCAN2_Clear();
		
	//
    SCAN3_Set();
	e_delay(1);
#if (Only_4_Return_Lines == true)        
    KeyStatus [2] = (~(unsigned char)(GPIO_PortRead(GPIO_PORT_D)>>1)) | 0xf0 ;
#else
    KeyStatus[2] = (~(unsigned char)(GPIO_PortRead(GPIO_PORT_D)>>1));
#endif    
    SCAN3_Clear();
		
		
	//
    SCAN4_Set();
	e_delay(1);
#if (Only_4_Return_Lines == true)            
    KeyStatus [3] = (~(unsigned char)(GPIO_PortRead(GPIO_PORT_D)>>1)) | 0xf0 ;
#else    
    KeyStatus[3] = (~(unsigned char)(GPIO_PortRead(GPIO_PORT_D)>>1));
#endif    
    SCAN4_Clear();

	//
    SCAN5_Set();
	e_delay(1);
#if (Only_4_Return_Lines == true)            
    KeyStatus [4] = (~(unsigned char)(GPIO_PortRead(GPIO_PORT_D)>>1)) | 0xf0 ;
#else    
    KeyStatus[4] = (~(unsigned char)(GPIO_PortRead(GPIO_PORT_D)>>1));
#endif    
    SCAN5_Clear();
    
	EN_RL_BUF_Set();
    
	CheckKey ();
    

#else    //keyabord is not used and all RL lines are used as inputs
    EN_RL_BUF_Clear();
    e_delay(1);
    INP_IMG1 = (unsigned char)(GPIO_PortRead(GPIO_PORT_D)>>1);
    EN_RL_BUF_Set();
#endif     
}
