#include "Gyro_Process.h"
#define FRAME_LEN 11 //change length for different protocol


/* circular moving window */
static uint8_t win[FRAME_LEN];
static uint8_t widx = 0;
static uint8_t filled = 0;

/* ping-pong frame buffers */
static uint8_t frameBuf[2][FRAME_LEN];

volatile uint8_t wrBuf = 0;     // parser writes here
volatile uint8_t rdBuf = 0;     // main reads here
volatile uint8_t frameReady = 0;



void CommitFrame(uint8_t start)
{
    for(uint8_t i=0;i<FRAME_LEN;i++)
        frameBuf[wrBuf][i] = win[(start+i)%FRAME_LEN];

    rdBuf = wrBuf;          // latest frame
    frameReady = 1;

    wrBuf ^= 1;             // toggle ping-pong buffer
}

void GyroParserPush(uint8_t ByteRcvd)
{
    win[widx] = ByteRcvd;
    widx = (widx + 1) % FRAME_LEN;

    /* wait until first full window */
    if(!filled)
    {
        if(widx == 0) filled = 1;
        else return;
    }

    uint8_t start = widx;   // oldest byte in window
//Here change SOF and EOF if different protocol is to be handled
    if(win[start] == 0x5A &&
       win[(start+1)%FRAME_LEN] == 0xA5 &&
       win[(start+9)%FRAME_LEN] == 0x0D &&
       win[(start+10)%FRAME_LEN] == 0x0A)
    {
        CommitFrame(start);
    }
    
    
}

bool Get_Gyro_Data(uint8_t* RcvdData)
{
    if(frameReady)
    {
        __builtin_disable_interrupts();
        frameReady = 0;
        uint8_t buf = rdBuf;
        __builtin_enable_interrupts();

        memcpy(RcvdData, frameBuf[buf], FRAME_LEN);

        return true;
    }
    else
        return false;
}

void Gyro_ParserReset()
{
    widx   = 0;
    filled = 0;
    memset(win, 0, FRAME_LEN);
}