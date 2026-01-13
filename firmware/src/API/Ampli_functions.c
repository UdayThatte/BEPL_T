
#include "Ampli_functions.h"
#include "CAN_Enco_Com.h"
#include "Utils.h"
#include "Para_Calculations.h"

extern uint16_t AmplStatus; 
extern volatile CAN_APP_STATES CAN_state;

bool Init_Amplifier(uint8_t AmplNode,AmplOprMode mode)
{
  uint32_t send_cnt;
  AmplComm_Status stat = Enable_Amplifier(AmplNode);
 
    if(stat != AMPL_STATE_OK) 
        return false;
  //printf("\rAmp Enabled in Init_Amplifier()");
  stat = Set_Operating_Mode(AmplNode,mode);
      if(stat != AMPL_STATE_OK) 
        return false;
  //printf("\rOp Mode Set in Init_Amplifier()");
  
  switch (AmplNode)
  {
      case AZ_Amplifier:
            //TODO calculations for the velocity to be performed here
              if(AZ_motor_rotation_direction==1)
              {
                stat = Set_Polarity_Of_Rotation(AmplNode,NORMAL_POLARITY);
                if(stat != AMPL_STATE_OK) 
                  return false;  
              }  
              else
              {
                stat = Set_Polarity_Of_Rotation(AmplNode,REVERSE_POLARITY);
                if(stat != AMPL_STATE_OK) 
                  return false;  
              }
              
              send_cnt= Get_AZ_Count_Velocity(AZ_default_Velocity);
              stat = Set_Target_Velocity_Count(AmplNode,send_cnt);
                if(stat != AMPL_STATE_OK) 
                  return false;

              send_cnt=Get_AZ_Count_Accl_Deccl(AZ_default_acc);
              stat = Set_Target_Acceleration_Count(AmplNode,send_cnt);
                    if(stat != AMPL_STATE_OK) 
                          return false;

          break;
      case EL_Amplifier:
                    if(EL_motor_rotation_direction==1)
                    {
                      stat = Set_Polarity_Of_Rotation(AmplNode,NORMAL_POLARITY);
                      if(stat != AMPL_STATE_OK) 
                        return false;  
                    }  
                    else
                    {
                      stat = Set_Polarity_Of_Rotation(AmplNode,REVERSE_POLARITY);
                      if(stat != AMPL_STATE_OK) 
                        return false;  
                    }          
                    
                  send_cnt=Get_EL_Count_Velocity(EL_default_Velocity);
                  stat = Set_Target_Velocity_Count(AmplNode,send_cnt);
                      if(stat != AMPL_STATE_OK) 
                            return false;

                  
                  send_cnt = Get_EL_Count_Accl_Deccl(EL_default_acc);
                  stat = Set_Target_Acceleration_Count(AmplNode,send_cnt);
                              if(stat != AMPL_STATE_OK) 
                                return false;
          break;
  }
   
  if(stat != AMPL_STATE_OK) 
        return false;
  
  return true;
}


void Get_and_Display_Ampl_Error(uint8_t AmplNode)
{
    uint32_t ErrCode;
    if(!Get_Amp_Error_if_Any(AmplNode,&ErrCode))
    {
        printf("\nCould Not Get Error Code CAN Err- %d",CAN_state);
        return;
    }
    
    DisplayAmplifier_Error(AmplNode,ErrCode);
   
}

void DisplayAmplifier_Error(uint8_t AmplNode,uint32_t ErrCode)
{
    char Prefix[48],ErrorDescr[32];
    
    strcpy(Prefix,"\rAZ Ampl.");
    if(AmplNode == EL_Amplifier) strcpy(Prefix,"\rEL Ampl.");
    
    switch(ErrCode)
    {
        case OVER_TEMP_ELEX:
            strcpy(ErrorDescr," Over Temp.Electronics\n");
            break;
        case OVER_TEMP_GENERAL:
            strcpy(ErrorDescr," General Over Temp\r");
            break;
        case POWER_BREAKDOWN:
            strcpy(ErrorDescr," power break error\r");
            break;
        case OVER_TEMP_MOTOR:
            strcpy(ErrorDescr," over temp error\r");
            break;
        case IIT_MOTOR:
            strcpy(ErrorDescr," IIT motor error\r");
            break;
        case IIT_SERVO_DRIVE:
            strcpy(ErrorDescr," IIT servo drive error\r");
            break;
        case HOMING_RUN:
            strcpy(ErrorDescr," HOMING RUN error\r");
            break;
        case CAN_RX_COMM_ERROR:
            strcpy(ErrorDescr," CAN RX Communication error\r");
            break;
        case ENCO_RESOLVER_ERROR:
            strcpy(ErrorDescr,"  Angle Encoder Resolver error\r");
            break;
        case LIMIT_SW_ERROR:
            strcpy(ErrorDescr,"  LIMIT_SW_ERROR\r");
            break;
        default:  
            sprintf(ErrorDescr," Error code: %04x",ErrCode);
            break;
    }
    
    strcat(Prefix,ErrorDescr);
    printf(Prefix);
    //send it to display also
    
}

bool Set_Motor_Home_Position(uint8_t AmplNode)
{
  AmplComm_Status retval;  
  uint8_t CrntMode;
    if(!GetOperationMode(AmplNode,&CrntMode))
    {
        printf("\rGetting current Motor Position Failed..");
        printf("\rErr:%08X  CAN-%2d",AmplStatus,CAN_state);
        return false;
    }
    retval = Set_Operating_Mode(AmplNode,Ampl_HOMING_Mode);
    if(AMPL_STATE_OK != retval)
    {
        printf("\rSetting Home Mode Failed..");
        printf("\rRet: %d Err:%08X  CAN-%2d",retval,AmplStatus,CAN_state);
        return false;
        
    }
    if(!Set_Homing_Method_To_NORUN(AmplNode))
    {
        printf("\rSetting Homing Method Failed..");
        printf("\rErr:%08X  CAN-%2d",AmplStatus,CAN_state);
        return false;
    }        
    retval= Command_For_Homing(AmplNode);
    if( AMPL_STATE_OK != retval)
    {
        printf("\rIssuing Home Command Failed..");
        printf("\rRet: %d Err:%08X  CAN-%2d",retval,AmplStatus,CAN_state);
        return false;
    }
    retval=Set_Operating_Mode(AmplNode,CrntMode);
    if( AMPL_STATE_OK != retval)
    {
        printf("\rRestoring Mode Failed..");
        printf("\rRet: %d Err:%08X  CAN-%2d",retval,AmplStatus,CAN_state);
        return false;
    }
    
    return true;
}

