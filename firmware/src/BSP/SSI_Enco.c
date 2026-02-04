
#include "SSI_Enco.h"
#include "Utils.h"


extern bool SSI_encode_Fault;


uint32_t Get_SSI_Enco_Count_ST(uint8_t ChNo,bool IsitGrayCode)
{
uint8_t bit_count;
uint32_t u32gray = 0,u32bin=0;
bool Dat_status;
int Bitstoread;
        Bitstoread = ST_Enc_NoofBits_ToRead_Bin;
        
        if(IsitGrayCode)
            Bitstoread = ST_Enc_NoofBits_ToRead_Gray;

       if(ChNo>MAX_NO_OF_SSI_CHS-1)
       {
           printf("\nInvalid SSI Channel Number To Read- %d\n",ChNo);
           return 0; //invalid channel numer
       }
           

       SSI_encode_Fault = false; 
       
       switch(ChNo)
       {
           case 0:
               SSI_CLK0_Set(); //make sure SSI_CLKx
               break;
           case 1:
               SSI_CLK1_Set(); //make sure SSI_CLKx
               break;
           case 2:
               SSI_CLK2_Set(); //make sure SSI_CLKx
               break;
       }
        
        
        for (bit_count=0; bit_count<Bitstoread; bit_count++)
        {
        // falling edge on clock 
        switch(ChNo)
        {
            case 0:
                SSI_CLK0_Clear(); //make sure SSI_CLKx
                break;
            case 1:
                SSI_CLK1_Clear(); //make sure SSI_CLKx
                break;
            case 2:
                SSI_CLK2_Clear(); //make sure SSI_CLKx
                break;
        }

         e_delay(PlsDly);        
        // left-shift the current result
        u32gray = (u32gray << 1);
     
        //rising edge of clock
        switch(ChNo)
        {
            case 0:
                SSI_CLK0_Set(); //make sure SSI_CLKx
                break;
            case 1:
                SSI_CLK1_Set(); //make sure SSI_CLKx
                break;
            case 2:
                SSI_CLK2_Set(); //make sure SSI_CLKx
                break;
        }

        e_delay(PlsDly);
        // evaluate the SSI_DAT line
            switch(ChNo)
            {
                case 0:
                    Dat_status =(bool)SSI_DAT0_Get();
                    break;
                case 1:   
                    Dat_status =(bool) SSI_DAT1_Get();
                    break;
                case 2:
                    Dat_status =(bool) SSI_DAT2_Get();
                    break;
            }
            if (Dat_status) //SSI_DATx
            {
            // bit is set, set LSB of result
            u32gray = u32gray | 0x01;
            } 
        } 
 //page 7 
//an additional rising clock will set the data output to LOW level. 
//This will be held low for 20 ±1 ?s (monoflop time). 
//After the time is over the encoder will start to update the position 
//value continuously and the data line is set to HIGH state        
        switch(ChNo)
        {
            case 0:
                SSI_CLK0_Clear(); //make sure SSI_CLKx
                break;
            case 1:
                SSI_CLK1_Clear(); //make sure SSI_CLKx
                break;
            case 2:
                SSI_CLK2_Clear(); //make sure SSI_CLKx
                break;
        }
        e_delay(PlsDly);
        
        switch(ChNo)
        {
            case 0:
                Dat_status =(bool) SSI_DAT0_Get();
                break;
            case 1:   
                Dat_status =(bool) SSI_DAT1_Get();
                break;
            case 2:
                Dat_status = (bool)SSI_DAT2_Get();
                break;
        }
        
                
        if(Dat_status)
            SSI_encode_Fault = true;
        
        switch(ChNo)
        {
            case 0:
                SSI_CLK0_Set(); //make sure SSI_CLKx
                break;
            case 1:
                SSI_CLK1_Set(); //make sure SSI_CLKx
                break;
            case 2:
                SSI_CLK2_Set(); //make sure SSI_CLKx
                break;
        }
        
        
        if(IsitGrayCode) //if its gray code convert
            u32bin = grayToBinary(u32gray & 0x1fff);
        else
            u32bin = u32gray & 0xfff;
        
return u32bin;
} 


uint32_t Get_SSI_Enco_Count_MT(uint8_t ChNo,bool IsitGrayCode)
{
uint8_t bit_count;
uint32_t u32gray = 0,u32bin=0;
bool Dat_status;

       if(ChNo>MAX_NO_OF_SSI_CHS-1)
       {
           printf("\nInvalid SSI Channel Number To Read- %d\n",ChNo);
           return 0; //invalid channel numer
       }
           

       SSI_encode_Fault = false; 
       
       switch(ChNo)
       {
           case 0:
               SSI_CLK0_Set(); //make sure SSI_CLKx
               break;
           case 1:
               SSI_CLK1_Set(); //make sure SSI_CLKx
               break;
           case 2:
               SSI_CLK2_Set(); //make sure SSI_CLKx
               break;
       }
        
        
        for (bit_count=0; bit_count<MT_Enc_NoofBits_ToRead; bit_count++)
        {
        // falling edge on clock 
        switch(ChNo)
        {
            case 0:
                SSI_CLK0_Clear(); //make sure SSI_CLKx
                break;
            case 1:
                SSI_CLK1_Clear(); //make sure SSI_CLKx
                break;
            case 2:
                SSI_CLK2_Clear(); //make sure SSI_CLKx
                break;
        }

         e_delay(PlsDly);        
        // left-shift the current result
        u32gray = (u32gray << 1);
     
        //rising edge of clock
        switch(ChNo)
        {
            case 0:
                SSI_CLK0_Set(); //make sure SSI_CLKx
                break;
            case 1:
                SSI_CLK1_Set(); //make sure SSI_CLKx
                break;
            case 2:
                SSI_CLK2_Set(); //make sure SSI_CLKx
                break;
        }

        e_delay(PlsDly);
        // evaluate the SSI_DAT line
            switch(ChNo)
            {
                case 0:
                    Dat_status =(bool)SSI_DAT0_Get();
                    break;
                case 1:   
                    Dat_status =(bool) SSI_DAT1_Get();
                    break;
                case 2:
                    Dat_status =(bool) SSI_DAT2_Get();
                    break;
            }
            if (Dat_status) //SSI_DATx
            {
            // bit is set, set LSB of result
            u32gray = u32gray | 0x01;
            } 
        } 
 //page 7 
//an additional rising clock will set the data output to LOW level. 
//This will be held low for 20 ±1 ?s (monoflop time). 
//After the time is over the encoder will start to update the position 
//value continuously and the data line is set to HIGH state        
        switch(ChNo)
        {
            case 0:
                SSI_CLK0_Clear(); //make sure SSI_CLKx
                break;
            case 1:
                SSI_CLK1_Clear(); //make sure SSI_CLKx
                break;
            case 2:
                SSI_CLK2_Clear(); //make sure SSI_CLKx
                break;
        }
        e_delay(PlsDly);
        
        switch(ChNo)
        {
            case 0:
                Dat_status =(bool) SSI_DAT0_Get();
                break;
            case 1:   
                Dat_status =(bool) SSI_DAT1_Get();
                break;
            case 2:
                Dat_status = (bool)SSI_DAT2_Get();
                break;
        }
        
                
        if(Dat_status)
            SSI_encode_Fault = true;
        
        switch(ChNo)
        {
            case 0:
                SSI_CLK0_Set(); //make sure SSI_CLKx
                break;
            case 1:
                SSI_CLK1_Set(); //make sure SSI_CLKx
                break;
            case 2:
                SSI_CLK2_Set(); //make sure SSI_CLKx
                break;
        }
        
        
        if(IsitGrayCode) //if its gray code convert
            u32bin = grayToBinary(u32gray & 0x1ffffff);
        else
            u32bin = u32gray & 0xffffff;
        
return u32bin;
} 

void Reset_SSI_Enco(uint8_t ChNo)
{
       if(ChNo>MAX_NO_OF_SSI_CHS-1)
       {
           printf("\nInvalid SSI Channel Number to RESET- %d\n",ChNo);
           return ; //invalid channel numer
       }
       switch(ChNo)
       {
           case 0:
                Clear_Enco0_RST;
                delay_mS(250);//OCD-S101G-0012-C100-PRL manual
                Set_Enco0_RST;
                break;
           case 1:
                Clear_Enco1_RST;
                delay_mS(250);
                Set_Enco1_RST;
                break;
           case 2:
                Clear_Enco2_RST;
                delay_mS(250);
                Set_Enco2_RST;
                break;

       }

}

uint32_t Get_SSI_Encoder_Count(uint8_t ChNo,EncoderParas_t* Paras)
{
uint8_t bit_count;
uint32_t u32gray = 0,u32bin=0,graymask,binmask;
bool Dat_status;
uint32_t TotalBits;

        TotalBits = Paras->revBits + Paras->angBits;

        //if(Paras->IsitGrayCode) TotalBits++;
        
        binmask = (1U << TotalBits) -1 ;
        graymask = binmask | (1U << TotalBits);
        
        TotalBits++; //extra MSB is always '1' as per maunal
        
       if(ChNo>MAX_NO_OF_SSI_CHS-1)
       {
           printf("\nInvalid SSI Channel Number To Read- %d\n",ChNo);
           return 0; //invalid channel numer
       }
           

       SSI_encode_Fault = false; 
       
       switch(ChNo)
       {
           case 0:
               SSI_CLK0_Set(); //make sure SSI_CLKx
               e_delay(1);
               Dat_status =(bool)SSI_DAT0_Get();
               break;
           case 1:
               SSI_CLK1_Set(); //make sure SSI_CLKx
               e_delay(1);
               Dat_status =(bool) SSI_DAT1_Get();
               break;
           case 2:
               SSI_CLK2_Set(); //make sure SSI_CLKx
               e_delay(1);
               Dat_status =(bool) SSI_DAT2_Get();
               break;
       }
//At start Data line should be '1'        
            if (!Dat_status) //SSI_DATx
            {
                SSI_encode_Fault = true;
                return 0;
            }
//                
        
        for (bit_count=0; bit_count<TotalBits; bit_count++) //Pg16 shows ST+MT+1 bits
        {
        // falling edge on clock 
        switch(ChNo)
        {
            case 0:
                SSI_CLK0_Clear(); //make sure SSI_CLKx
                break;
            case 1:
                SSI_CLK1_Clear(); //make sure SSI_CLKx
                break;
            case 2:
                SSI_CLK2_Clear(); //make sure SSI_CLKx
                break;
        }

         e_delay(PlsDly);        
        // left-shift the current result
        u32gray = (u32gray << 1);
     
        //rising edge of clock
        switch(ChNo)
        {
            case 0:
                SSI_CLK0_Set(); //make sure SSI_CLKx
                break;
            case 1:
                SSI_CLK1_Set(); //make sure SSI_CLKx
                break;
            case 2:
                SSI_CLK2_Set(); //make sure SSI_CLKx
                break;
        }

        e_delay(PlsDly);
        // evaluate the SSI_DAT line
            switch(ChNo)
            {
                case 0:
                    Dat_status =(bool)SSI_DAT0_Get();
                    break;
                case 1:   
                    Dat_status =(bool) SSI_DAT1_Get();
                    break;
                case 2:
                    Dat_status =(bool) SSI_DAT2_Get();
                    break;
            }
            if (Dat_status) //SSI_DATx
            {
            // bit is set, set LSB of result
            u32gray = u32gray | 0x01;
            } 
        } 
 //page 7 
//an additional rising clock will set the data output to LOW level. 
//This will be held low for 20 ±1 ?s (monoflop time). 
//After the time is over the encoder will start to update the position 
//value continuously and the data line is set to HIGH state        
        switch(ChNo)
        {
            case 0:
                SSI_CLK0_Clear(); //make sure SSI_CLKx
                break;
            case 1:
                SSI_CLK1_Clear(); //make sure SSI_CLKx
                break;
            case 2:
                SSI_CLK2_Clear(); //make sure SSI_CLKx
                break;
        }
        e_delay(PlsDly);
        switch(ChNo)
        {
            case 0:
                Dat_status =(bool) SSI_DAT0_Get();
                break;
            case 1:   
                Dat_status =(bool) SSI_DAT1_Get();
                break;
            case 2:
                Dat_status = (bool)SSI_DAT2_Get();
                break;
        }
        
                
        if(Dat_status)
            SSI_encode_Fault = true;
        
        switch(ChNo)
        {
            case 0:
                SSI_CLK0_Set(); //make sure SSI_CLKx
                break;
            case 1:
                SSI_CLK1_Set(); //make sure SSI_CLKx
                break;
            case 2:
                SSI_CLK2_Set(); //make sure SSI_CLKx
                break;
        }
        
        
        if(Paras->IsitGrayCode) //if its gray code convert
            u32bin = grayToBinary(u32gray & graymask);//0x1ffffff);
        else
            u32bin = u32gray & binmask;//0xffffff;
        
return u32bin;
    
}


