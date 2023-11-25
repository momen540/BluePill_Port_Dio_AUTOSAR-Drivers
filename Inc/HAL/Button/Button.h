  /*
  * @file    Button.h
  * @author  Mo'men Elhoseiny
  * @brief   Header file for Button hardware driver
  * @Date    Created on August 26, 2023
  */

#ifndef HAL_BUTTON_BUTTON_H_
#define HAL_BUTTON_BUTTON_H_

/*=================================*/
  /*
   *  Includes section
   */
		#include "../../MCAL/DIO/Dio.h"
		#include "../../CortexM3/CortexM3_Core_Systick.h"
		#include "../../MCAL/PORT/Port.h"
/*=================================*/


/*******************************************************************************
 *                        	   Macro Definitions 	                           *
 *******************************************************************************/
/*
 * @Brief 		: 	Switch for Green led State defined in Led.h connected to Port C pin 14
 * @implements	:	Button_Type Enumeration
 */
#define GREEN_LED_BUTTON      ((Button_Type)DIO_PORTC_PIN14)
/*
 * @Brief 		: 	Switch for Blue led State defined in Led.h connected to Port C pin 15
 * @implements	:	Button_Type Enumeration
 */
#define BLUE_LED_BUTTON	  	  ((Button_Type)DIO_PORTC_PIN15)
/*
 * @Brief 		: 	Switch for Red led State defined in Led.h connected to Port A pin 4
 * @implements	:	Button_Type Enumeration
 */
#define RED_LED_BUTTON	  	  ((Button_Type)DIO_PORTA_PIN4)
/*
 * @Brief 		: 	Switch for Yellow led State defined in Led.h connected to port A pin 5
 * @implements	:	Button_Type Enumeration
 */
#define YELLOW_LED_BUTTON 	  ((Button_Type)DIO_PORTA_PIN5)
/*
 * @Brief 		: 	Switch for OnBoardLed State defined in Led.h connected to port A pin 6
 * @implements	:	Button_Type Enumeration
 */
#define ON_BOARD_LED_BUTTON	  ((Button_Type)DIO_PORTA_PIN6)

/*
 * @Brief 		:	Button is pressed state
 * @implements	:	Button_State Enumeration
 */
#define BUTTON_SET 		((Button_State)1)
/*
 * @Brief 		:	Button is Released state
 * @implements	:	Button_State Enumeration
 */
#define BUTTON_RESET	((Button_State)0)
/*******************************************************************************
 *                        	    Macro Functions 	                           *
 *******************************************************************************/

/*******************************************************************************/

/*******************************************************************************
 *                          User Defined Data Types                            *
 *******************************************************************************/
typedef uint8 Button_Type  ;
typedef uint8 Button_State ;
/*******************************************************************************/

/*******************************************************************************
 *                             Function Prototypes                             *
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
Std_ReturnType Read_Button(Button_Type Button,Button_State * State);

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
Std_ReturnType Read_Button_Debounced(Button_Type Button,Button_State * State);

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
Std_ReturnType Read_Button_Debounced_Blocking(Button_Type Button,Button_State * State);
/*******************************************************************************/


#endif /* HAL_BUTTON_BUTTON_H_ */
