  /*
  ******************************************************************************
  * @file    CRC.h
  * @author  Mo'men Elhoseiny
  * @brief   Header file for STM32F103c8t6 Microcontroller - cyclic redundancy check Module
  * @Date    Created on July 26, 2023
  ******************************************************************************
  */

#ifndef MCAL_CRC_CRC_H_
#define MCAL_CRC_CRC_H_

/*=================================*/
  /*
   *  Includes section
   */
		#include <Common/Std_Types.h>
		#include "Common/Common_Macros.h"
		#include "Register_Definition/Register_Definition.h"
		#include "../RCC/RCC.h"
/*=================================*/

#define CRC_RESET_BIT		(0)

/*******************************************************************************
 *                         	         Macros                                    *
 *******************************************************************************/
#define CRC_RESET_BIT		(0)
/******************************************************************************/

/*******************************************************************************
 *                               Macro Functions                               *
 ******************************************************************************/
#define CRC_RESET_UNIT() 						(SET_BIT(CRC->CR,CRC_RESET_BIT))
/******************************************************************************/



/*******************************************************************************
 *                          User Defined Data Types                            *
 *******************************************************************************/

/*******************************************************************************/


/*******************************************************************************
 *                            Function Prototypes                              *
 *******************************************************************************/
/*
 * @Brief Function Initalizes CRC Unit by enabling clock and resetting registers.
 * @Describtion :  enables clock access to crc and resets crc registers.
 */
void CRC_Init(void);
/*
 * @brief 		  : Calculates the 32Bit CRC value of a 32-bit data buffer
 * @Description   : Calculates 32Bit CRC starting with the previously
 * 				    Calculated CRC as initialization value.
 * @param Buff    : pointer to the input data buffer.
 * @param Length  : input data buffer length.
 * @Return Ret	  : 32Bit Calculated CRC
 * @Note 		  : Don't Forget to reset the register after every accumulated CRC
 * 		   	        @Ref CRC_RESET_UNIT()
 */
uint32 CRC_Accumulate(uint32 *Buff, uint32 Length);
/*******************************************************************************/


#endif /* MCAL_CRC_CRC_H_ */
