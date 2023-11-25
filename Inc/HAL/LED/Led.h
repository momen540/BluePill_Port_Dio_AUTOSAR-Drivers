  /*
  ******************************************************************************
  * @file    Led.h
  * @author  Mo'men Elhoseiny
  * @brief   Header file for LEDs used in project
  * @Date    Created on July 26, 2023
  ******************************************************************************
  */

#ifndef LED_H
#define LED_H

/*=================================*/
  /*
   *  Includes section
   */
		#include <HAL/LED/Led_cfg.h>
/*=================================*/

/*******************************************************************************
 *                          		MACROS		                               *
 *******************************************************************************/
/*
 * @Brief 		:On Board Led connected to Port C pin 13
 * @Implements  : Led_Type Enumeration
 */
#define ON_BOARD_LED  ((Led_Type)DIO_PORTC_PIN13)
/*
 * @Brief 		: Green Led Connected to port A pin 0
 * @Implements  : Led_Type Enumeration
 */
#define	GREEN_LED  	  ((Led_Type)DIO_PORTA_PIN0)
/*
 * @Brief 		: Blue Led Connected to port A pin 1
 * @Implements  : Led_Type Enumeration
 */
#define BLUE_LED	  ((Led_Type)DIO_PORTA_PIN1)
/*
 * @Brief 		: Red Led Connected to port A pin 2
 * @Implements  : Led_Type Enumeration
 */
#define RED_LED		  ((Led_Type)DIO_PORTA_PIN2)
/*
 * @Brief 		: Yellow Led Connected to port A pin 3
 * @Implements  : Led_Type Enumeration
 */
#define YELLOW_LED	  ((Led_Type)DIO_PORTA_PIN3)
/*******************************************************************************/

/*******************************************************************************
 *                          User Defined Data Types                            *
 *******************************************************************************/
/*
 * Enumeration for leds in system
 */
typedef uint8 Led_Type;
/*******************************************************************************/


/*Function Declarations*/
/*
 * @Brief Function used to turn LED state to High
 * @Parameter ledID Selected Led to turn on
 */
void Led_turn_on(Led_Type ledID);
/*
 * @Brief Function used to turn LED state to LOW
 * @Parameter ledID Selected Led to turn off
 */
void Led_turn_off(Led_Type ledID);

#ifdef LED_TOGGLE
/*
 * @Brief Function used to toggle LED state
 * @Parameter ledID Selected Led to toggle
 */
void Led_toggle(Led_Type LedID);
#endif
#endif /* LED_H */
