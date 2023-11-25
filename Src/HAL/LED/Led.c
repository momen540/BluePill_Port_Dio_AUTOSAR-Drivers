  /*
  ******************************************************************************
  * @file    Led.c
  * @author  Mo'men Elhoseiny
  * @brief   Source file for LEDs used in project
  * @Date    Created on July 26, 2023
  ******************************************************************************
  */

/*=================================*/
  /*
   *  Includes section
   */
		#include <HAL/LED/Led.h>
/*=================================*/
/*
 * @Brief Function used to turn LED state to High
 * @Parameter ledID Selected Led to turn on
 */
void Led_turn_on(Led_Type ledID)
{
	if(DIO_PORTC_PIN13 == ledID){
		Dio_WriteChannel(ledID,STD_OFF);
	}
	else{
		Dio_WriteChannel(ledID,STD_ON);
	}
}
/*
 * @Brief Function used to turn LED state to LOW
 * @Parameter ledID Selected Led to turn off
 */
void Led_turn_off(Led_Type ledID)
{
	if(DIO_PORTC_PIN13 == ledID){
		Dio_WriteChannel(ledID,STD_ON);
	}
	else{
		Dio_WriteChannel(ledID,STD_OFF);
	}
}
#ifdef LED_TOGGLE
/*
 * @Brief Function used to toggle LED state
 * @Parameter ledID Selected Led to toggle
 */
void Led_toggle(Led_Type ledID)
{
	Dio_FlipChannel(ledID);
}
#endif
