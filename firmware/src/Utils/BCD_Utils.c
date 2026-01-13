#include "BCD_Utils.h"


void Asc_To_PackHex_String(char Inp[],unsigned char Out[],int NoOfAscii)
//'3' '5' '2' '0' four bytes should return 0x35, 0x20
//0x33 0x35 0x32 0x30 --> 0x35 0x20
//assumed valid 0-9 and A-F is produced
// say 0x0 0x0 is not passed as input to this route
//also assumed noofascii is even only
{
int n,m;
	
	for(n = 0,m =0; n < NoOfAscii; n +=2,m++)
	{
		if ((Inp[n] > '/') && (Inp[n] < ':') )
			Out[m] = Inp[n] << 4 ;
		else
			{
			if(Inp[n] == ' ')
				Out[m] = 0x0;
			else
				Out[m] = (Inp[n] - '7') << 4;
			}
		
		
		if ((Inp[n+1] > '/') && (Inp[n+1] < ':') )
			Out[m] |= Inp[n+1] & 0x0f;
		else
			{
			if(Inp[n+1] == ' ')
				Out[m] = 0x0;
			else
				Out[m] |= (Inp[n+1] - '7') & 0x0f;
			}
	//if(Out[m] == 0x0) Out[m]= '0';//for invalid converted make zero for print	
	}
//	Out[m] = 0x0; // this was disturbing character beyond limit of array passes
	//detected bug on 29.07.2015 so modified for CCT_9_5S and others are compiled
	//using RFID mainly CCT and RAIPUR
}
void CharToBCD(unsigned char inp,unsigned char BCDStr[])
{
	if (inp>99)
	{
		BCDStr[0]=0x0;
        inp = 99;
	}
	 
	 BCDStr[0] = ((unsigned char)(inp / 10) << 4) + (unsigned char)(inp % 10); 
	
}

void LongToBCDStr3(unsigned long inp,unsigned char BCDStr[] )
{
	if (inp > 999999)
	{
	  BCDStr[0]=0x0;
	  BCDStr[1]=0x0;
	  BCDStr[2]=0x0;
	  return; //can not be converted to BCD
	}
	
 
 BCDStr[0] = (unsigned char)(inp / 10000);		
 BCDStr[0] = ((BCDStr[0]/ 10) << 4) + (BCDStr[0] % 10);
  inp %= 10000;
  
 BCDStr[1] = (unsigned char)(inp / 100);		
 BCDStr[1] = ((BCDStr[1]/ 10) << 4) + (BCDStr[1] % 10);
 
 BCDStr[2] = (unsigned char)(inp % 100);		
 BCDStr[2] = ((BCDStr[2]/ 10) << 4) + (BCDStr[2] % 10);
	
}

void LongToBCDStr(unsigned long inp,unsigned char BCDStr[] )
{
	if (inp > 99999999)
	{
	  BCDStr[0]=0x0;
	  BCDStr[1]=0x0;
	  BCDStr[2]=0x0;
	  BCDStr[3]=0x0;
	  return; //can not be converted to BCD
	}
	
 BCDStr[0] = (unsigned char)(inp / 1000000);
 BCDStr[0] = ((BCDStr[0]/ 10) << 4) + (BCDStr[0] % 10);
 
  inp %= 1000000;
 
 BCDStr[1] = (unsigned char)(inp / 10000);		
 BCDStr[1] = ((BCDStr[1]/ 10) << 4) + (BCDStr[1] % 10);
  inp %= 10000;
  
 BCDStr[2] = (unsigned char)(inp / 100);		
 BCDStr[2] = ((BCDStr[2]/ 10) << 4) + (BCDStr[2] % 10);
 
 BCDStr[3] = (unsigned char)(inp % 100);		
 BCDStr[3] = ((BCDStr[3]/ 10) << 4) + (BCDStr[3] % 10);
	
}
void IntToBCDStr(unsigned short int inp,unsigned char BCDStr[] )
{
//only result upto 9999 are returned
//two bytes are returned	
	if (inp > 9999)
	{
	  BCDStr[0]=0x0;
	  BCDStr[1]=0x0;
	  return; //can not be converted to BCD
	}
	
 BCDStr[0] = (unsigned char)(inp / 100);
 BCDStr[0] = ((BCDStr[0]/ 10) << 4) + (BCDStr[0] % 10); 
 BCDStr[1] = (unsigned char)(inp % 100);		
 BCDStr[1] = ((BCDStr[1]/ 10) << 4) + (BCDStr[1] % 10);
}


unsigned char BCDtoChar(unsigned char inp)
{
	return (unsigned char) (((inp >> 4) & 0x0f) * 10 ) + (inp & 0x0f);   
}


unsigned long BCD3StrToLong(unsigned char BCDStr[])
//max 9999 assumed
{
	if ( (BCDStr[0] > 0x99) || (BCDStr[1] > 0x99) || (BCDStr[2] > 0x99)) return(0);
	 return (  (BCDtoChar(BCDStr[0])* (unsigned  long)10000) + (BCDtoChar(BCDStr[1]) * (unsigned long)100 ) + BCDtoChar(BCDStr[2]) ); 
	
}
unsigned short int BCD2StrToShortInt(unsigned char BCDStr[])
//max 9999 assumed
{
	if ( (BCDStr[0] > 0x99) || (BCDStr[1] > 0x99)) return(0);
	 return (  (BCDtoChar(BCDStr[0])* (unsigned short int)100) + (BCDtoChar(BCDStr[1])) ); 
	
}
unsigned long BCDStrToUnsignedLong(unsigned char BCDStr[])
//max 99999999 assumed
{
unsigned long retval;	
	if ( (BCDStr[0] > 0x99) || (BCDStr[1] > 0x99)|| (BCDStr[2] > 0x99)|| (BCDStr[3] > 0x99) ) return(0);
	retval = (BCDtoChar(BCDStr[0])* (unsigned long) 1000000);
	retval += (BCDtoChar(BCDStr[1])* (unsigned long)10000);
	retval += (BCDtoChar(BCDStr[2])* (unsigned long)100);
	retval += BCDtoChar(BCDStr[3]);
	return (retval);
}
