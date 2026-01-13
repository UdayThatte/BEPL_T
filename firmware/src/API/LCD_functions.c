#include "LCD_functions.h"
#include "Utils.h"
#include "LCD_Comm.h"

void Init_LCD(uint8_t Disp_no)
{
    delay_mS(20);    
    Write_LCDCommand(Disp_no,(uint8_t)FSET);
    delay_mS(20);
    Write_LCDCommand(Disp_no,(uint8_t)DON);
    delay_mS(20);
    Write_LCDCommand(Disp_no,(uint8_t)EMOD);
    delay_mS(20);
    Write_LCDCommand(Disp_no,(uint8_t)CDSHT);
    delay_mS(20);
    Write_LCDCommand(Disp_no,(uint8_t)CDIS);
    delay_mS(20);
    
}

void Set_Cursor(uint8_t Disp_no,uint8_t row,uint8_t col)
{
 uint8_t AdrCmd;   
    switch(row)
    {
        case 1:
          AdrCmd = (uint8_t)DRAMAD1;
          break;
        case 2:
          AdrCmd = (uint8_t)DRAMAD2;
          break;
        case 3:
          AdrCmd = (uint8_t)DRAMAD3;
          break;
        case 4:
          AdrCmd = (uint8_t)DRAMAD4;
          break;          
    }
    AdrCmd += (col-1);
    Write_LCDCommand(Disp_no,AdrCmd);
}

void LCDWritechar(uint8_t Disp_no,uint8_t row,uint8_t col,char dispchr)
{
    if(row<1) row = 1;
    if(row>4) row = 4;
    if(col<1) col=1;
    if(col>20) col =20;
    
    Set_Cursor(Disp_no,row,col);
    Write_LCDData(Disp_no,dispchr);
    
}

void LCDWriteString(uint8_t Disp_no,uint8_t row,uint8_t col,char* dispStr)
{
    uint8_t Count=0;
    //set cursor position
    if(row<1) row = 1;
    if(row>4) row = 4;
    if(col<1) col=1;
    if(col>20) col =20;
    
    Set_Cursor(Disp_no,row,col);
    
    while((*dispStr != '\0' ) && (Count<20))
    {
        Write_LCDData(Disp_no,*dispStr);
        dispStr++;
        Count++;
    }

}

void LCD_Set_Blinking_Cursor_ON(uint8_t Disp_no)
{
    Write_LCDCommand(Disp_no,(uint8_t)DBCON);
    
}

void LCD_Set_Blinking_Cursor_OFF(uint8_t Disp_no)
{
    Write_LCDCommand(Disp_no,(uint8_t)DON);
}

void ClearDisp(uint8_t Disp_no)
{
   for(int n=1;n<5;n++) 
    LCDWriteString(Disp_no,n,1,"                    ");
}