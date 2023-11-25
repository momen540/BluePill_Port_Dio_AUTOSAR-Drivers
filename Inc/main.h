  /*
  ******************************************************************************
  * @file    main.c
  * @author  Mo'men Elhoseiny
  * @brief
  * @Date    Created on July 26, 2023
  ******************************************************************************
  */

#ifndef MAIN_H_
#define MAIN_H_

/*=================================*/
  /*
   *  Includes section
   */
		#include <HAL/Button/Button.h>
#include <HAL/LED/Led.h>
#include "CortexM3/CortexM3.h"
		#include "MCAL/PORT/Port.h"
		#include "CDD/UART/UART.h"
/*=================================*/
/*=========== UART Configuration ============*/
UART_Cfg_t UART3_Cfg={
		115200,
		UART_8BIT,
		UART_3_SELCTED,
		UART_NO_PARITY,
		UART_1_STOPBIT,
		UART_MODE_RXTX,
		UART_HWCONTROL_NONE,
};
/*===========================================*/

#endif /* MAIN_H_ */
