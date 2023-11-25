  /*
  * @file    Button.h
  * @author  Mo'men Elhoseiny
  * @brief   Header file for Button hardware driver
  * @Date    Created on August 26, 2023
  */

/*=================================*/
  /*
   *  Includes section
   */
		#include <HAL/Button/Button.h>
/*=================================*/
/*******************************************************************************
 *                          Static Function Prototypes                         *
 *******************************************************************************/
/*
 * @Brief Function used to get the Resistor pull state
 * @Parameter ChannelId : Channel to get resisitor state of from Port cfg
 * @Return Port_InternalResistor @Ref Port_InternalResistor in Port.h
 */
static inline Port_InternalResistor ButtonPullState(Dio_ChannelType ChannelId);
/*******************************************************************************/


/*******************************************************************************
 *                             Function Definitions                            *
 *******************************************************************************/
/*
 * @Brief : Function Reads Buttons State
 * @Descriptiom : Function Reads Button State and return it in parameter state.
 * @Parameter Button : Button ID.
 * @Parameter State  : Button State
 * 					   BUTTON_RESET : Button is not pressed.
 * 					   BUTTON_SET   : Button is pressed.
 * @Return : Returns error status in case of wrong Butoon ID.
 * 					   E_NOT_OK : ID Is incorrect function failed to excute.
 * 					   E_OK     : ID Was Correct function excuted sucessfully.
 * @ Important Note : This API Does Not Handle Software Debouncing.
 */
Std_ReturnType Read_Button(Button_Type Button,Button_State * State)
{
	Std_ReturnType Error_Status = E_OK;
	if((State == NULL_PTR) || (Button > NUMBER_OF_DIO_CHANNELS)){
		Error_Status = E_NOT_OK;
	}
	else{
			/*Get pin state*/
			*State = Dio_ReadChannel(Button);
			/*Get Pull State*/
			Port_InternalResistor Resistor_Mode = ButtonPullState(Button);
			if(Pull_UP == Resistor_Mode){
				*State = !(*State);
			}
	}
	return Error_Status;
}

/*
 * @Brief : Function Reads Buttons State and handels bounce effect
 * @Descriptiom : Function Reads Button State and return it in parameter state.
 * @Parameter Button : Button ID.
 * @Parameter State  : Button State
 * 					   BUTTON_RESET : Button is not pressed.
 * 					   BUTTON_SET   : Button is pressed.
 * @Return : Returns error status in case of wrong Butoon ID.
 * 					   E_NOT_OK : ID Is incorrect function failed to excute.
 * 					   E_OK     : ID Was Correct function excuted sucessfully.
 * @Note Function uses SysTick_delay_ms API Which is a blocking function.
 */
Std_ReturnType Read_Button_Debounced(Button_Type Button,Button_State * State)
{
	/*Function error status*/
	Std_ReturnType Error_Status = E_OK;
	/*Tracks the current state of button*/
	Button_State Current_state = BUTTON_RESET;

	/*Tracks stable state duration*/
	uint8_least Debounced_Counter_1 = 0;
	uint8_least Debounced_Counter_2 = 0;
	/*Debounce Threshold (adjustable if needed)*/
	uint32 debounce_max = 20;

	while((Debounced_Counter_1 < debounce_max)&&(Debounced_Counter_2 < debounce_max))
	{
		/*Read current button state*/
		Error_Status = Read_Button(Button,&Current_state);
		if(Current_state == BUTTON_SET){
			Debounced_Counter_1 ++;
			Debounced_Counter_2 = 0;
		}
		else{
			Debounced_Counter_2++;
			Debounced_Counter_1 = 0;
		}
		SysTick_delay_ms(1);
	}
	*State = Current_state;
	return Error_Status;
}

/*
 * @Brief : Function Reads Buttons State and handels bounce effect and waits for user to leave button
 * @Descriptiom : Function Reads Button State and return it in parameter state.
 * @Parameter Button : Button ID.
 * @Parameter State  : Button State
 * 					   BUTTON_RESET : Button is not pressed.
 * 					   BUTTON_SET   : Button is pressed.
 * @Return : Returns error status in case of wrong Butoon ID.
 * 					   E_NOT_OK : ID Is incorrect function failed to excute.
 * 					   E_OK     : ID Was Correct function excuted sucessfully.
 * @Note Function uses SysTick_delay_ms API Which is a blocking function.
 * @Note Function waits for user to lift finger of button so it is a Blocking function.
 */
Std_ReturnType Read_Button_Debounced_Blocking(Button_Type Button,Button_State * State)
{
	/*Function error status*/
	Std_ReturnType Error_Status = E_OK;
	/*Tracks the current state of button*/
	Button_State Current_state = BUTTON_RESET;
	Error_Status = Read_Button_Debounced(Button,&Current_state);
	*State = Current_state;
	/*Wait for button to be released*/
	while(Current_state == BUTTON_SET){Error_Status = Read_Button(Button,&Current_state);}
	return Error_Status;
}
/*******************************************************************************/

/*******************************************************************************
 *                          Static Function Definitions                        *
 *******************************************************************************/
/*
 * @Brief Function used to get the Resistor pull state
 * @Parameter ChannelId : Channel to get resisitor state of from Port cfg
 * @Return Port_InternalResistor @Ref Port_InternalResistor in Port.h
 */
static inline Port_InternalResistor ButtonPullState(Dio_ChannelType ChannelId){
	Port_InternalResistor Resistor_Mode = Floating;
	Resistor_Mode = Port_Configuration.Pins[ChannelId].Pull;
	return Resistor_Mode;
}
/*******************************************************************************/
