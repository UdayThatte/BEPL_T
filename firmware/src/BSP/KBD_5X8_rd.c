/*
 * KBD_6X5_Kinetis.C
 *
 *  Created on: Sep 19, 2012
 *      Author: myself
 */
#include "KBD_5X8_rd.h"


extern void CheckKey ();
extern unsigned char KeyStatus [];
extern void e_delay (long eDel);


void KbdProcessInTimer()
{
  
    
    EN_RL_BUF_Clear();
	//As only 4 return lines are present Oring 0xf0 
    SCAN1_Set();
	e_delay(1);
    //KeyStatus[0] = (~(unsigned char)(GPIO_PortRead(GPIO_PORT_D)>>1)) | 0xf0 ;
    KeyStatus[0] = (~(unsigned char)(GPIO_PortRead(GPIO_PORT_D)>>1));
	SCAN1_Clear();

		
	//
    SCAN2_Set();
	e_delay(1);
    //KeyStatus [1] = (~(unsigned char)(GPIO_PortRead(GPIO_PORT_D)>>1)) | 0xf0 ;
    KeyStatus[1] = (~(unsigned char)(GPIO_PortRead(GPIO_PORT_D)>>1));
	SCAN2_Clear();
		
	//
    SCAN3_Set();
	e_delay(1);
    //KeyStatus [2] = (~(unsigned char)(GPIO_PortRead(GPIO_PORT_D)>>1)) | 0xf0 ;
    KeyStatus[2] = (~(unsigned char)(GPIO_PortRead(GPIO_PORT_D)>>1));
    SCAN3_Clear();
		
		
	//
    SCAN4_Set();
	e_delay(1);
    //KeyStatus [3] = (~(unsigned char)(GPIO_PortRead(GPIO_PORT_D)>>1)) | 0xf0 ;
    KeyStatus[3] = (~(unsigned char)(GPIO_PortRead(GPIO_PORT_D)>>1));
    SCAN4_Clear();

	//
    SCAN5_Set();
	e_delay(1);
    //KeyStatus [4] = (~(unsigned char)(GPIO_PortRead(GPIO_PORT_D)>>1)) | 0xf0 ;
    KeyStatus[4] = (~(unsigned char)(GPIO_PortRead(GPIO_PORT_D)>>1));
    SCAN5_Clear();
    
	EN_RL_BUF_Set();
    
	CheckKey ();
}
