
#include "Amplifier_Com.h"
#include "Utils.h"

extern volatile int32_t mSecCntr;
extern uint16_t AmplStatus; 


AmplComm_Status Disable_Amplifier(uint8_t AmplNode)
{
   uint16_t StatWrd;
   int32_t strttime;
   bool novalidresp;
   
   if(! Write_CAN_Object(AmplNode,CONTROL_WORD,0x0,Data_16Bit,Amp_SHUT_DOWN,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0)))
        return AMPL_CAN_COMM_ERR;
       
             strttime = mSecCntr;
             novalidresp = false;
             do
             {
               if(!GetAmplStatus(AmplNode,&StatWrd)) 
                   return AMPL_CAN_COMM_ERR;     // Error occured in CAN comm 

               if ((mSecCntr - strttime) > Timeout_Action_By_AmpInmSec)
               {
                   novalidresp = true;
                   break;
               }

             }while((StatWrd & AmplStat_Enable_Mask)!= READY_TO_SWITCH_ON);

             if(novalidresp) 
             {
                 AmplStatus = StatWrd;
                 printf("\r Not Ready to switch on after Disable");
                 return AMPL_OPERATION_NOT_SUCCEEDED;//status indicates reason
             }
             //printf("\r after disable %04x",StatWrd);
   return AMPL_STATE_OK;
}


AmplComm_Status Enable_Amplifier(uint8_t AmplNode)
//Pg157 Switching on Procedure
{
   uint16_t StatWrd;
   int32_t strttime;
   bool novalidresp;
   AmplComm_Status retval;
   
if(!GetAmplStatus(AmplNode,&StatWrd)) 
    return AMPL_CAN_COMM_ERR;     // Error occured in CAN comm 
   
  if ( (StatWrd & AmplStat_Enable_Mask) == OPERATION_ENABLE ) 
      return AMPL_STATE_OK;
  

   retval = Disable_Amplifier(AmplNode);
   if( retval !=AMPL_STATE_OK) return retval;
  
//*******************************      
//   
   if(!Write_CAN_Object(AmplNode,CONTROL_WORD,0x0,Data_16Bit,Amp_SWITCH_ON,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0))) 
        return AMPL_CAN_COMM_ERR; //Enable
   
       
   strttime = mSecCntr;
   novalidresp = false;
   do
   {
     if(!GetAmplStatus(AmplNode,&StatWrd)) return AMPL_CAN_COMM_ERR; // Error occured in CAN comm    
     
     if ((mSecCntr - strttime) > Timeout_Action_By_AmpInmSec) //
     {
         novalidresp = true;
         break;
     }
         
   }while((StatWrd & AmplStat_Enable_Mask)!= SWITCHED_ON);

   if(novalidresp) 
   {
       AmplStatus = StatWrd;
       printf("\rswitch on failed");
       return AMPL_OPERATION_NOT_SUCCEEDED;//status indicates reason
   }
//
   
   //*******************************      
  //printf("\r after switch on %04x",StatWrd);
   
   if(!Write_CAN_Object(AmplNode,CONTROL_WORD,0x0,Data_16Bit,Amp_ENABLE_OPERATION,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0))) return AMPL_CAN_COMM_ERR; //Enable
   
       
   strttime = mSecCntr;
   novalidresp = false;
   do
   {
     if(!GetAmplStatus(AmplNode,&StatWrd)) return AMPL_CAN_COMM_ERR; // Error occured in CAN comm    
     
     if ((mSecCntr - strttime) > Timeout_Action_By_AmpInmSec) //
     {
         novalidresp = true;
         break;
     }
         
   }while((StatWrd & AmplStat_Enable_Mask)!= OPERATION_ENABLE);
//*******************************
   
   AmplStatus = StatWrd;

   if(novalidresp) 
   {
       printf("\r Enable failed");
       return AMPL_OPERATION_NOT_SUCCEEDED;//status indicates reason
   }
       
   
   return AMPL_STATE_OK;
}

bool Get_Actual_Motor_Position(uint8_t AmplNode,int32_t* Posi)
{
    uint32_t Rdval;
    if(!Read_CAN_Object(AmplNode,POSITION_ACTUAL_VALUE,0x0,Data_32Bit,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0),&Rdval))
       return false; 
    *Posi = (int32_t)Rdval;
    return true;
}

bool GetAmplStatus(uint8_t AmplNode,uint16_t* Stat)
{
    uint32_t Rdval;
    if(!Read_CAN_Object(AmplNode,STATUS_WORD,0x0,Data_16Bit,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0),&Rdval))
       return false; 
    *Stat = (uint16_t)Rdval;
    return true;
}

bool GetOperationMode(uint8_t AmplNode,uint8_t* Stat)
{
    uint32_t Rdval;
    if(!Read_CAN_Object(AmplNode,MODE_OF_OPERATION,0x0,Data_8Bit,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0),&Rdval))
       return false; 
    *Stat = (uint8_t)Rdval;
    return true;
}


//Pg170 - 171
//Setting of operating mode should be checked with 0x6061
//It may take time to take effect
AmplComm_Status Set_Operating_Mode(uint8_t AmplNode,AmplOprMode mode)
{
   int32_t strttime;
   bool novalidresp;
   uint32_t ret;
   
    if(!Write_CAN_Object(AmplNode,MODE_OF_OPERATION,0x0,Data_8Bit,(uint32_t)mode,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0)))
       return AMPL_CAN_COMM_ERR;
  //Now check with Mode_Of_Operation_display to confirm
   
   strttime = mSecCntr;
   novalidresp = false;
   do
   {
     if(!Read_CAN_Object(AmplNode,MODE_OF_OPERATION_DISPL,0x0,Data_8Bit,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0),&ret))
           return AMPL_CAN_COMM_ERR; // Error occured in CAN comm
     
     if ((mSecCntr - strttime) > Timeout_Action_By_AmpInmSec) //
     {
         novalidresp = true;
         break;
     }
         
   }while(ret!= mode);

   AmplStatus = (uint16_t)ret;
   
   if(novalidresp) 
       return AMPL_OPERATION_NOT_SUCCEEDED;//status indicates reason
 
   return AMPL_STATE_OK;
    
}

//returns Error code if it is present (only 16 bits valid)
//in case of CAN communication error CAN_state would be updated
//Returns Zero in case of No error
bool Get_Amp_Error_if_Any(uint8_t AmplNode,uint32_t* ErrCode)
{
    bool ret;
    uint16_t StatWrd;
    if(!GetAmplStatus(AmplNode,&StatWrd)) return false;
    
    if(( StatWrd & AMPL_FAULT) != AMPL_FAULT) 
    {
        *(ErrCode) = 0; //no Error
        return true;//function successful bit 3 is not set means no fault 
    }
       
//in case Bit is set read the Latest Error code     
    
    ret = Read_CAN_Object(AmplNode,PRE_DEFINED_ERROR_FIELD,0x0,Data_8Bit,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0),ErrCode);
    if(!ret) return false; //if comm error //return in communication 
    if(*(ErrCode)== 0 ) return true;//Error code Not stored !! (this will not happen)
 //read first code at sub index 1  
    ret = Read_CAN_Object(AmplNode,PRE_DEFINED_ERROR_FIELD,0x1,Data_32Bit,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0),ErrCode); 
    return ret;
}

AmplComm_Status Set_Target_Velocity_Count(uint8_t AmplNode,uint32_t Vel)
{
    if(! Write_CAN_Object(AmplNode,TARGET_VELOCITY,0x0,Data_32Bit,Vel,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0)))
        return AMPL_CAN_COMM_ERR;
    
    return AMPL_STATE_OK;
}

AmplComm_Status Set_Target_Position_Count(uint8_t AmplNode,int32_t Pos,bool IsRelative)
{
    uint32_t Ctlwrd;
    uint32_t StatWrd,timelapsed;
    bool ret;
    
    if(! Write_CAN_Object(AmplNode,TARGET_POSITION,0x0,Data_32Bit,(uint32_t)Pos,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0)))
         return AMPL_CAN_COMM_ERR;
    //first read control word and set the Relative / absolute accordingly
     ret = Read_CAN_Object(AmplNode,CONTROL_WORD,0x0,Data_16Bit,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0),&Ctlwrd);
     if(!ret) return AMPL_CAN_COMM_ERR; //if comm error //return in communication 
     
     if(IsRelative)
         Ctlwrd |= Amp_Relative_Set_Point; //set to 1 for relative move
     else
         Ctlwrd &= ~(Amp_Relative_Set_Point);
     //write back control word
     
      if(! Write_CAN_Object(AmplNode,CONTROL_WORD,0x0,Data_16Bit,Ctlwrd,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0)))
         return AMPL_CAN_COMM_ERR;
 //Check Status word  If Target is accepted (within limit)
    timelapsed = GetSystemMs();
    do
    {
        ret = Read_CAN_Object(AmplNode,STATUS_WORD,0x0,Data_16Bit,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0),&StatWrd);
          if(!ret) return AMPL_CAN_COMM_ERR; //if comm error //return in communication 
        AmplStatus = (uint16_t)StatWrd ;  
        
        if((GetSystemMs() - timelapsed)>Timeout_Action_By_AmpInmSec)
            return AMPL_OPERATION_NOT_SUCCEEDED;
            
    }while(!(StatWrd & Target_Reached_Mask)); //
    
        
    return AMPL_STATE_OK;
    
}

AmplComm_Status Issue_GO_Command(uint8_t AmplNode,bool ActImmediate )
{
    uint32_t Ctlwrd;
    uint32_t StatWrd,timelapsed;
    bool ret;
    bool Moving =false;
    AmplComm_Status stat;

    
    
    //first read control word and set the Relative / absolute accordingly
     ret = Read_CAN_Object(AmplNode,CONTROL_WORD,0x0,Data_16Bit,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0),&Ctlwrd);
     if(!ret) 
         return AMPL_CAN_COMM_ERR; //if comm error //return in communication 
          
    //Rising edge is required on New_Set_Point bit 4
     Ctlwrd &= ~(Amp_New_Set_Point_Mask);
      if(! Write_CAN_Object(AmplNode,CONTROL_WORD,0x0,Data_16Bit,Ctlwrd,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0)))
         return AMPL_CAN_COMM_ERR;
     //if this command to be executed immediately or after finishing
     if(ActImmediate)
         Ctlwrd |= Amp_Change_Position_Immediate;
     else
         Ctlwrd &= ~(Amp_Change_Position_Immediate);
// set all bits properly
      if(! Write_CAN_Object(AmplNode,CONTROL_WORD,0x0,Data_16Bit,Ctlwrd,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0)))
         return AMPL_CAN_COMM_ERR;
     
     //now set the bit for rising edge
        Ctlwrd |= Amp_New_Set_Point_Mask;
        
      if(! Write_CAN_Object(AmplNode,CONTROL_WORD,0x0,Data_16Bit,Ctlwrd,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0)))
         return AMPL_CAN_COMM_ERR;

        timelapsed = GetSystemMs();
        do
        {
            ret = Read_CAN_Object(AmplNode,STATUS_WORD,0x0,Data_16Bit,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0),&StatWrd);
              if(!ret) return AMPL_CAN_COMM_ERR; //if comm error //return in communication 
            AmplStatus = (uint16_t)StatWrd ;  

            if((GetSystemMs() - timelapsed)>Timeout_Action_GO_AmpInmSec)
                return AMPL_OPERATION_NOT_SUCCEEDED;

        }while(!(StatWrd & SetPoint_Acknowledge_Mask)); //

    //printf("\rMotor Started Moving..");    
    
    return AMPL_STATE_OK;    
}

AmplComm_Status Check_if_Target_Reached(uint8_t AmplNode,bool* Reached)
{
    bool ret;
    uint32_t RdVal;
    ret = Read_CAN_Object(AmplNode,STATUS_WORD,0x0,Data_16Bit,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0),&RdVal);  

     AmplStatus = (uint16_t)RdVal;    
     
     if(!ret) 
         return AMPL_CAN_COMM_ERR;
    
    if(RdVal & Target_Reached_Mask) 
        *Reached = true;
    else
        *Reached = false;
    
    return AMPL_STATE_OK;
}

AmplComm_Status Set_Target_Deceleration_Count(uint8_t AmplNode,uint32_t Decl)
{
    if(! Write_CAN_Object(AmplNode,TARGET_DECELERATION,0x0,Data_32Bit,Decl,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0)))
         return AMPL_CAN_COMM_ERR;
    
    AmplStatus = AMPL_STATE_OK;
    return AmplStatus;
}

AmplComm_Status Set_Target_Acceleration_Count(uint8_t AmplNode,uint32_t Accl)
{
    if(! Write_CAN_Object(AmplNode,TARGET_ACCELERATION,0x0,Data_32Bit,Accl,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0)))
         return AMPL_CAN_COMM_ERR;
    
    AmplStatus = AMPL_STATE_OK;
    return AmplStatus;
}

AmplComm_Status Get_ActualSpeed_Count_of_Motor(uint8_t AmplNode,uint32_t* speed)
{
   bool ret;
   uint32_t Spd;
   
    ret = Read_CAN_Object(AmplNode,VELOCITY_ACTUAL_VALUE,0x0,Data_32Bit,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0),speed);
     if(!ret) 
     {
         AmplStatus = AMPL_CAN_COMM_ERR;
         return AmplStatus; 
     }
    
    AmplStatus = AMPL_STATE_OK;
    return AmplStatus;  
}

bool Issue_Quick_Stop(uint8_t AmplNode)
{
    
   int32_t rdval;
   return Write_CAN_Object(AmplNode,CONTROL_WORD,0x0,Data_16Bit,Amp_QUICKSTOP,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0));
    
}


bool Set_Homing_Method_To_NORUN(uint8_t AmplNode)
{
   int32_t rdval;
   return Write_CAN_Object(AmplNode,HOMING_METHOD,0x0,Data_8Bit,HOMING_NORUN,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0));

}
//Gives bit4 of Control word a rising edge to start homing
AmplComm_Status Command_For_Homing(uint8_t AmplNode)
{
uint32_t Ctlwrd;
uint32_t StatWrd,timelapsed;
bool ret;
bool Moving =false;
AmplComm_Status stat;
    
     ret = Read_CAN_Object(AmplNode,CONTROL_WORD,0x0,Data_16Bit,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0),&Ctlwrd);
       if(!ret) 
         return AMPL_CAN_COMM_ERR; //if comm error //return in communication 
          
    //Rising edge is required on New_Set_Point bit 4
     Ctlwrd &= ~(Amp_New_Set_Point_Mask);
      if(! Write_CAN_Object(AmplNode,CONTROL_WORD,0x0,Data_16Bit,Ctlwrd,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0)))
         return AMPL_CAN_COMM_ERR;
 //now set the bit for rising edge
        Ctlwrd |= Amp_New_Set_Point_Mask;
        
      if(! Write_CAN_Object(AmplNode,CONTROL_WORD,0x0,Data_16Bit,Ctlwrd,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0)))
         return AMPL_CAN_COMM_ERR;    
        
//confirm if homing successfull
        timelapsed = GetSystemMs();
        do
        {
            ret = Read_CAN_Object(AmplNode,STATUS_WORD,0x0,Data_16Bit,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0),&StatWrd);
              if(!ret) return AMPL_CAN_COMM_ERR; //if comm error //return in communication 
            
            AmplStatus = (uint16_t)StatWrd ;  

            if((GetSystemMs() - timelapsed)>Timeout_Action_GO_AmpInmSec)
                return AMPL_OPERATION_NOT_SUCCEEDED;

        }while(!(StatWrd & SetPoint_Acknowledge_Mask)); //
    
        
    return AMPL_STATE_OK;  
}

AmplComm_Status Set_Polarity_Of_Rotation(uint8_t AmplNode,bool IsReverse)
{
 uint32_t Pola = NORMAL_POLARITY;
    
    if(IsReverse) Pola = REVERSE_POLARITY;
 
    if(! Write_CAN_Object(AmplNode,POLARITY,0x0,Data_8Bit,Pola,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0)))
    {
        AmplStatus = AMPL_CAN_COMM_ERR;
         return AMPL_CAN_COMM_ERR;
    }
        
    
    AmplStatus = AMPL_STATE_OK;
    return AmplStatus;
}


AmplComm_Status Reset_Fault(uint8_t AmplNode)
{
 uint32_t Ctlwrd;
 bool ret;
 
    ret = Read_CAN_Object(AmplNode,CONTROL_WORD,0x0,Data_16Bit,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0),&Ctlwrd);
     if(!ret) return AMPL_CAN_COMM_ERR; //if comm error //return in communication 

    Ctlwrd &= ~Amp_FAULT_BIT_Mask;
    if(! Write_CAN_Object(AmplNode,CONTROL_WORD,0x0,Data_16Bit,Amp_SHUT_DOWN,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0)))
        return AMPL_CAN_COMM_ERR;
    
    delay_mS(10);
    
    Ctlwrd |= ~Amp_FAULT_BIT_Mask;
    if(! Write_CAN_Object(AmplNode,CONTROL_WORD,0x0,Data_16Bit,Amp_SHUT_DOWN,FIFO_Ampl_0+(AmplNode - CAN_Node_Amp0)))
        return AMPL_CAN_COMM_ERR;
    
    return AmplStatus;
}