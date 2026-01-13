#include "LCD_Comm.h"
#include "Utils.h"


extern volatile bool InputReadEnable;
extern volatile bool KeyBoardEnable;
extern volatile int32_t TmOut;

bool Is_LCD_Busy(uint8_t DispNo)
{
   uint8_t regi; 
    //while( regi & 0x80 ) //check BusyFlag of control register 
    //{
    regi = Read_Control_Reg(DispNo);
    return (regi&0x80)? true:false;
}

uint8_t Read_Control_Reg(uint8_t DispNo)
{
    uint8_t Cntrl_RegVal;
    
    CommandRegi_Select;
    Set_LCD_RW;
    KeyBoardEnable = false;
    InputReadEnable = false; //blocking max 3uS
    Make_Data_Port_Input;
    EN_DIS_BUF_Clear();
    if(DispNo)
    {
        Set_LCD2_ChipSelect;
        e_delay(20);
        Cntrl_RegVal = Read_LCD_Port;
        Clear_LCD2_ChipSelect;
    }
    else
    {
        Set_LCD1_ChipSelect;
        e_delay(20);
        Cntrl_RegVal = Read_LCD_Port;
        Clear_LCD1_ChipSelect;
    }
    
    EN_DIS_BUF_Set();
    InputReadEnable = true;
    KeyBoardEnable = true;

    return Cntrl_RegVal;
}

void Write_LCDData(uint8_t DispNo,uint8_t data) //0 - tegular display 1-alternate
{
    TmOut = 100;
    while(Is_LCD_Busy(DispNo))
    {
        if(!TmOut)
        {
            printf("\rLCD Module %d Busy Error..",DispNo);
            return;
        }
    }
        
    
    DataRegi_Select;
    Clear_LCD_RW;
    
    KeyBoardEnable = false;
    InputReadEnable = false; //blocking max 3uS
    Make_Data_Port_Output;
    Write_LCD_Port(data);
    EN_DIS_BUF_Clear();
    if(DispNo)
    {
        Set_LCD2_ChipSelect;
        e_delay(20);
        Clear_LCD2_ChipSelect;
    }
    else
    {
        Set_LCD1_ChipSelect;
        e_delay(20);
        Clear_LCD1_ChipSelect;
    }
    Make_Data_Port_Input;
    EN_DIS_BUF_Set();
    InputReadEnable = true;
    KeyBoardEnable = true;

}

void Write_LCDCommand(uint8_t DispNo,uint8_t data) 
{
    TmOut = 100;
    while(Is_LCD_Busy(DispNo))
    {
        if(!TmOut)
        {
            printf("\rLCD Module %d Busy Error..",DispNo);
            return;
        }
    }

    
    CommandRegi_Select;
    Clear_LCD_RW;
    
    KeyBoardEnable = false;
    InputReadEnable = false; //blocking max 3uS
    Make_Data_Port_Output;
    Write_LCD_Port(data);
    EN_DIS_BUF_Clear();
    if(DispNo)
    {
        Set_LCD2_ChipSelect;
        e_delay(20);
        Clear_LCD2_ChipSelect;
    }
    else
    {
        Set_LCD1_ChipSelect;
        e_delay(20);
        Clear_LCD1_ChipSelect;
    }
    Make_Data_Port_Input;
    EN_DIS_BUF_Set();
    InputReadEnable = true;
    KeyBoardEnable = true;
}
