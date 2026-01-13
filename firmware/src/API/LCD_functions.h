/* 
 * File:   LCD_functions.h
 * Author: UT
 *
 * Created on November 13, 2025, 2:02 PM
 */

#ifndef LCD_FUNCTIONS_H
#define	LCD_FUNCTIONS_H

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <stdio.h>
#include "definitions.h"                // SYS function prototypes

#ifdef	__cplusplus
extern "C" {
#endif
#define FSET 0b00111000 //Function set 0x38 makes character dim
#define DON  0b00001100 //Disp On
#define DCON 0b00001110   //Disp&Cursor On
#define DBON 0b00001101  //Disp & Blink on
#define DBCON 0b00001111	 //Disp&Curs&Blink on
#define EMOD  0b00000110 //entry mode
#define CDIS  0b00000001 //clear disp
    
#define DRAMAD1 0x80
#define DRAMAD2 0xc0
#define DRAMAD3 0x94
#define DRAMAD4 0xd4
    
#define CDSHT 0b00010100    //cursor/shift

//Disp no 0 is default display any other number is secondary LCD
void Init_LCD(uint8_t Disp_no);    

//Assumed that dispStr is 20 char wide max ,characters beyond that would be ignored
//row is Line on display 1,4 and col is horizontal position 1-20 within line
//row 4 would be capped to 4 and <1 would be 1 Similar for Col also <1 or >20 would be cappped
void LCDWritechar(uint8_t Disp_no,uint8_t row,uint8_t col,char dispchr);
void LCDWriteString(uint8_t Disp_no,uint8_t row,uint8_t col,char* dispStr);
void LCD_Set_Blinking_Cursor_ON(uint8_t Disp_no);
void LCD_Set_Blinking_Cursor_OFF(uint8_t Disp_no);
void ClearDisp(uint8_t Disp_no);

#ifdef	__cplusplus
}
#endif

#endif	/* LCD_FUNCTIONS_H */

