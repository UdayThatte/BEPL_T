/* 
 * File:   LCD_Comm.h
 * Author: UT
 *
 * Created on November 12, 2025, 3:31 PM
 */

#ifndef LCD_COMM_H
#define	LCD_COMM_H

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <stdio.h>
#include "definitions.h"                // SYS function prototypes

#ifdef	__cplusplus
extern "C" {
#endif

#define  Clear_LCD1_ChipSelect 	EN_DIS_Clear()
#define  Set_LCD1_ChipSelect 	EN_DIS_Set()
#define  Clear_LCD2_ChipSelect 	EN_DIS1_Clear()
#define  Set_LCD2_ChipSelect 	EN_DIS1_Set()
    
#define  CommandRegi_Select     RS_DIS_Clear() //RS 0  Command 1 Data
#define  DataRegi_Select         RS_DIS_Set()
#define  Clear_LCD_RW           R_W_Clear()
#define  Set_LCD_RW             R_W_Set()
#define	 Write_LCD_Port(lData)  GPIO_PortWrite(GPIO_PORT_D,(uint32_t)0x1fe,(lData<<1)& 0x1fe)
#define  Read_LCD_Port          (uint8_t)((GPIO_PortRead(GPIO_PORT_D)>>1)&0x0ff)
#define  Make_Data_Port_Output  GPIO_PortOutputEnable(GPIO_PORT_D,(uint32_t)0x1fe)
#define  Make_Data_Port_Input   GPIO_PortInputEnable(GPIO_PORT_D,(uint32_t)0x1fe)    

    
//0 - regular display Non zero is addon LCD
//data- data to write
void Write_LCDCommand(uint8_t DispNo,uint8_t data);
void Write_LCDData(uint8_t DispNo,uint8_t data);
//reads and returns control reg of LCD indicated by DispNo
uint8_t Read_Control_Reg(uint8_t DispNo);
//returns true is LCD is busy indicated by DispNo
bool Is_LCD_Busy(uint8_t DispNo);

#ifdef	__cplusplus
}
#endif

#endif	/* LCD_COMM_H */

