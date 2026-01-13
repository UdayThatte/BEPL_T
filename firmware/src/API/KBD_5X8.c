
#include "KBD_5X8.h"
//#include "Checks.h"

extern void LongBeep();
extern volatile bool KeyPressed;
extern volatile bool KeyBoardEnable;

extern unsigned char KeyStatus [];
extern unsigned char LastStatus [];
extern unsigned char CheckStatus [];

extern volatile int KeyCounter;
extern unsigned int KeyCode;
extern unsigned int kCode;
extern volatile uint32_t NoKeyTimeOut;

extern char disp_str[];
extern volatile int32_t TmOut;

void Till_Key_Released()
{
	TmOut = ONE_SEC;
	
	while(KeyCounter > 0)
	{

		if (!TmOut)
		{
            printf("\rKeyPressed..");
			LongBeep();
			TmOut = ONE_SEC;
		}
	}
	KeyPressed = false;
}


void CheckKey ()
{
    unsigned char ki, kj, nKeysPressed;

    for (ki = 0; ki < 5; ki++)    
    CheckStatus [ki] = (unsigned char) (KeyStatus [ki] | LastStatus [ki]);
    
	for (ki = 0; ki < 5; ki++)
    LastStatus [ki] = KeyStatus [ki];
    
	kCode = 0;
	nKeysPressed = 0;
	for (ki = 0; ki < 5; ki++)
	{
	    for (kj = 0; kj < 8; kj++)
	    {
    		if (!(CheckStatus [ki] & (1 << kj)))
    		{
    			kCode = (ki * 8) + kj; 
    			nKeysPressed++;
    		}
	    }
	}
	if (nKeysPressed == 1)
	{
	    KeyCounter++;
		if ((KeyCounter % 5) == 1)
		{
			KeyPressed = true;
			NoKeyTimeOut = 0;
			KeyCode = kCode;
			if (KeyCounter > 100)
			    kCode |= LONG_PRESS;
			else
			    if (KeyCounter >= 40)
			        kCode |= DOUBLE_PRESS;
			KeyCode = kCode;
		}
		

	}
	else
		if (nKeysPressed == 0)
	    {
			KeyCounter = 0;
		}
}


