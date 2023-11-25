  /*
  ***********************************************************************************************
  * @file    Port_PBcfg.c																		*
  * @author  Mo'men Elhoseiny																	*
  * @brief   Post Build Configuration Source file for TM4C123GH6PM Microcontroller - DIO Driver*
  * @Date    Created on July 26, 2023															*
  ***********************************************************************************************
  */
  /*===============================================================================
  *  Project			: AUTOSAR 4.4.0 MCAL
  *  Platform			: ARM
  *  Peripheral			: STM32F103c8t6
  *  Autosar vesion  	: 4.4.0
  *  Autosar Revesion	: ASR_REL_4_0_REV_0000
  *  SW Version			: 1.0.0
  *===============================================================================*/

#ifndef MCAL_DIO_DIO_PBCFG_C_
#define MCAL_DIO_DIO_PBCFG_C_

/*=================================*/
  /*
   *  Includes section
   */
		#include "../../../Inc/MCAL/DIO/Dio.h"
/*=================================*/

/*
 * Module Version 1.0.0
 */
#define DIO_PBCFG_SW_MAJOR_VERSION              (1U)
#define DIO_PBCFG_SW_MINOR_VERSION              (0U)
#define DIO_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.4.0
 */
#define DIO_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define DIO_PBCFG_AR_RELEASE_MINOR_VERSION     (4U)
#define DIO_PBCFG_AR_RELEASE_PATCH_VERSION     (0U)

/* AUTOSAR Version checking between Dio_PBcfg.c and Dio.h files */
#if ((DIO_PBCFG_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (DIO_PBCFG_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (DIO_PBCFG_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Dio_PBcfg.c and Dio.h files */
#if ((DIO_PBCFG_SW_MAJOR_VERSION != DIO_SW_MAJOR_VERSION)\
 ||  (DIO_PBCFG_SW_MINOR_VERSION != DIO_SW_MINOR_VERSION)\
 ||  (DIO_PBCFG_SW_PATCH_VERSION != DIO_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif

/*
 * PreCompile configuration for DIO modes in BluePill Board
 */
const Dio_ConfigChannel Dio_Configuration = {
		/****  PORT A 	*****/
		DIO_PORTA,DIO_INDEX_0,DIO_OUTPUT,
		DIO_PORTA,DIO_INDEX_1,DIO_OUTPUT,
		DIO_PORTA,DIO_INDEX_2,DIO_OUTPUT,
		DIO_PORTA,DIO_INDEX_3,DIO_OUTPUT,
		DIO_PORTA,DIO_INDEX_4,DIO_INPUT,
		DIO_PORTA,DIO_INDEX_5,DIO_INPUT,
		DIO_PORTA,DIO_INDEX_6,DIO_INPUT,
		DIO_PORTA,DIO_INDEX_7,DIO_INPUT,
		DIO_PORTA,DIO_INDEX_8,DIO_OUTPUT,
		DIO_PORTA,DIO_INDEX_9,DIO_AF,
		DIO_PORTA,DIO_INDEX_10,DIO_AF,
		DIO_PORTA,DIO_INDEX_11,DIO_OUTPUT,
		DIO_PORTA,DIO_INDEX_12,DIO_OUTPUT,
		DIO_PORTA,DIO_INDEX_15,DIO_OUTPUT,

		/****  PORT B 	*****/
		DIO_PORTB,DIO_INDEX_0,DIO_OUTPUT,
		DIO_PORTB,DIO_INDEX_1,DIO_OUTPUT,
		DIO_PORTB,DIO_INDEX_3,DIO_OUTPUT,
		DIO_PORTB,DIO_INDEX_4,DIO_OUTPUT,
		DIO_PORTB,DIO_INDEX_5,DIO_OUTPUT,
		DIO_PORTB,DIO_INDEX_6,DIO_OUTPUT,
		DIO_PORTB,DIO_INDEX_7,DIO_OUTPUT,
		DIO_PORTB,DIO_INDEX_8,DIO_OUTPUT,
		DIO_PORTB,DIO_INDEX_9,DIO_OUTPUT,
		DIO_PORTB,DIO_INDEX_10,DIO_OUTPUT,
		DIO_PORTB,DIO_INDEX_11,DIO_OUTPUT,
		DIO_PORTB,DIO_INDEX_12,DIO_OUTPUT,
		DIO_PORTB,DIO_INDEX_13,DIO_OUTPUT,
		DIO_PORTB,DIO_INDEX_14,DIO_OUTPUT,
		DIO_PORTB,DIO_INDEX_15,DIO_OUTPUT,

		/****  PORT C 	*****/
		DIO_PORTC,DIO_INDEX_13,DIO_OUTPUT,
		DIO_PORTC,DIO_INDEX_14,DIO_INPUT,
		DIO_PORTC,DIO_INDEX_15,DIO_OUTPUT,
};

#endif /* MCAL_DIO_DIO_PBCFG_C_ */
