  /*
  ******************************************************************************
  * @file    CRC.c
  * @author  Mo'men Elhoseiny
  * @brief   Source file for STM32F103c8t6 Microcontroller - Cylcic redundency check module
  * @Date    Created on July 26, 2023
  ******************************************************************************
  */

#ifndef MCAL_CRC_CRC_C_
#define MCAL_CRC_CRC_C_

/*=================================*/
  /*
   *  Includes section
   */
		#include "../../../Inc/MCAL/CRC/CRC.h"
/*=================================*/

/*
 * @Brief Function Initalizes CRC Unit by enabling clock and resetting registers.
 * @Describtion :  enables clock access to crc and resets crc registers.
 */
void CRC_Init(void){
	/*Enable clock access to crc unit*/
	RCC_AHBENR_CRC_CLK_EN();
	/*Resets Data Register*/
	CRC_RESET_UNIT();
}
/*
 * @brief 		  : Calculates the 32Bit CRC value of a 32-bit data buffer
 * @Description   : Calculates 32Bit CRC starting with the previously
 * 				    Calculated CRC as initialization value.
 * @param Buff    : pointer to the input data buffer.
 * @param Length  : input data buffer length.
 * @Return Ret	  : 32Bit Calculated CRC
 */
uint32 CRC_Accumulate(uint32 *Buff, uint32 Length){
	uint32 CRC_Ret = 0;
	uint32_least Index = 0;
	for(Index = 0 ; Index < Length ; Index ++){
		CRC->DR=(uint32)Buff[Index];
	}
	CRC_Ret = CRC->DR;
	return CRC_Ret;
}


#endif /* MCAL_CRC_CRC_C_ */
