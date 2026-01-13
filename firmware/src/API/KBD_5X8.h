

#ifndef __KBD_6x5_H
#define __KBD_6x5_H

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <stdio.h>
#include "definitions.h"                // SYS function prototypes



//void KbdProcessInTimer();
void CheckKey ();
void Till_Key_Released();

#define DOUBLE_PRESS 0x0100
#define LONG_PRESS 0x0200
#define ONE_SEC ((int) 1000) //multiple of 1 mSec


//KeyCode Bit 5,4,3 indicates Scan lines (max5) and 2..0 indicates RL lines (Max 8) 
//Max 5x8 Keypad can be used for 40 keys
#define KEY_1 0x00		//SCAN1
#define KEY_2 0x01		//
#define KEY_3 0x02		//
#define KEY_4 0x03		//
#define KEY_5 0x4   //when a larger keyboard is used These are next keys
#define KEY_6 0x5   //
#define KEY_7 0x6   //
#define KEY_8 0x7   //

#define KEY_9 0x08		//SCAN2
#define KEY_10 0x09
#define KEY_11 0x0a
#define KEY_12 0x0b
#define KEY_13 0x0c   //
#define KEY_14 0x0d   //
#define KEY_15 0x0e   //
#define KEY_16 0x0f   //


#define KEY_17 0x10		//SCAN3
#define KEY_18 0x11		
#define KEY_19 0x12		
#define KEY_20 0x13		
#define KEY_21 0x14   //
#define KEY_22 0x15   //
#define KEY_23 0x16   //
#define KEY_24 0x17   //


#define KEY_25 0x18      //SCAN4   
#define KEY_26 0x19		
#define KEY_27 0x1a		
#define KEY_28 0x1b		
#define KEY_29 0x1c   //
#define KEY_30 0x1d   //
#define KEY_31 0x1e   //
#define KEY_32 0x1f   //


#define KEY_33 0x20		//SCAN5
#define KEY_34 0x21
#define KEY_35 0x22
#define KEY_36 0x23
#define KEY_37 0x24
#define KEY_38 0x25   //
#define KEY_39 0x26   //
#define KEY_40 0x27   //




#endif
