  /*
  ******************************************************************************
  * @file    Led_cfg.h
  * @author  Mo'men Elhoseiny
  * @brief   Header file for pre compile configurations for LED module
  * @Date    Created on July 26, 2023
  ******************************************************************************
  */

/*=================================*/
  /*
   *  Includes section
   */
		#include "../../MCAL/DIO/Dio.h"
/*=================================*/

#ifndef LED_CFG_H
#define LED_CFG_H


/*IF Flip channel API is active active or disaple Toggle led api*/
#if DIO_FLIP_CHANNEL_API == STD_ON
#define LED_TOGGLE
#endif

#endif /* EUCAL_LED_LED_CFG_H_ */
