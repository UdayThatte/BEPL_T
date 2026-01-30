#include "App_Protocol.h"
#include "Protocol.h"

extern uint8_t PNDNT_OUT_Buffer[];
extern uint8_t ETH_OUT_Buffer[];

extern double EL_Enco_Angle; 
extern double AZ_Enco_Angle;


void Prepare_fb_string()
{
   uint8_t Chksm=0;
   int n;
   uint16_t Position;
   double ELAngle;
   ETH_OUT_Buffer[0] =  Proto_SOF;//'H';
   ETH_OUT_Buffer[1] = 0x06;//'e';//
   ETH_OUT_Buffer[2] = 0xff;//'l';// this is healthy to simulate  //FC_byte_in_feedback;
   
   Position = (uint16_t)((AZ_Enco_Angle*0xffff)/359.99);
   ETH_OUT_Buffer[3] = (uint8_t)(Position>>8);    //0x7f;//'l';// for now SSI encoder
   ETH_OUT_Buffer[4] = (uint8_t)(Position&0xff);   //0x00;//'0';//  //TODO Dummy value of 0x7f7f AZ feeddback
   
   if((EL_Enco_Angle>90)&&(EL_Enco_Angle<270)) ELAngle = 0;
   if(EL_Enco_Angle<90) ELAngle = EL_Enco_Angle;
   if(EL_Enco_Angle>270)ELAngle = EL_Enco_Angle-EL_Enco_Angle;;
   
   if(ELAngle <0 ) //negative
   {
    Position = (uint16_t)(((EL_Enco_Angle*-1)*0x7fff)/90); 
    Position |= 0x8000;
   }
   else
    Position = (uint16_t)((EL_Enco_Angle*0x7fff)/90);    
   
   ETH_OUT_Buffer[5] = (uint8_t)(Position>>8);//0x7f;//'B';//
   ETH_OUT_Buffer[6] = (uint8_t)(Position&0xff); //0x00;//'E';// //TODO Dummy value of 0x7f7f EL feeddback
   
   ETH_OUT_Buffer[7] = 0xff;//'P';// this is healthy to simulate Status_Byte1_in_feedback;
   ETH_OUT_Buffer[9] = Proto_EOF;//'\r';//
   
   for(n=1;n<8;n++)
        Chksm ^= ETH_OUT_Buffer[n];
   
   ETH_OUT_Buffer[8] = Chksm;//'L';//
      
}
