#include "Utils.h"


extern volatile int Dlycnt;


uint32_t GetSystemMs(void)
{
   uint32_t core_timer_count = _CP0_GET_COUNT();
   uint32_t milliseconds = (core_timer_count / (CORE_TIMER_FREQUENCY/1000UL));
  return milliseconds;

}

void e_delay(uint32_t dly)//125nS
{
 volatile uint32_t k;   
    for(k=0;k<dly;k++)
        _nop();

}

void delay_mS(int Interval)
{
    Dlycnt = Interval;
    while(Dlycnt)
    {_nop();}
    
}

uint8_t Read_stdin_if_ready()
{
    uint8_t c =0x0;
    if(UART1_ReceiverIsReady())  // if char is available
        c =(uint8_t) UART1_ReadByte();    
    return c;
}


uint32_t grayToBinary(uint32_t gray) 
{
    
     uint32_t binary = gray;
    while (gray >>= 1)
    {
        binary ^= gray;
    }
    return binary;

}


char* Replace_char(char* str, char find, char replace) 
{
    char *current_pos = strchr(str, find); // Find the first occurrence
    while (current_pos != NULL) {
        *current_pos = replace; // Replace the character
        // Search for the next occurrence starting from the position after the current one
        current_pos = strchr(current_pos + 1, find);
    }
    return str;
}