
#include "Beeps.h"
#include "Utils.h"


void __WEAK LongBeep()
{
    BUZZER_Clear();
	delay_mS(500);
    BUZZER_Set();
}
void __WEAK ShortBeep()
{
    BUZZER_Clear();
	delay_mS(50);
    BUZZER_Set();
}
