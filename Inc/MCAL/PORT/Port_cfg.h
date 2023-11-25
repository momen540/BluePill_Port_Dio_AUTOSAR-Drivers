  /*
  * @file    Port_cfg.h
  * @author  Mo'men Elhoseiny
  * @brief   Pre-Compile Configuration Header file for AUTOSAR STM32F103c8t6 Microcontroller - Port Driver
  * @Date    Created on July 26, 2023
  */
  /*===============================================================================
  *  Project			: AUTOSAR 4.4.0 MCAL
  *  Platform			: ARM
  *  Peripheral			: STM32F103c8t6
  *  Autosar vesion  	: 4.4.0
  *  Autosar Revesion	: ASR_REL_4_0_REV_0000
  *  SW Version			: 1.0.0
  *===============================================================================*/

#ifndef MCAL_PORT_PORT_CFG_H_
#define MCAL_PORT_PORT_CFG_H_
/*=================================*/
  /*
   *  Includes section
   */
		#include <Common/Std_Types.h>
/*=================================*/

/*******************************************************************************
 *                             Version Definitions                             *
 *******************************************************************************/
/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.4.0
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (0U)
/********************************************************************************/
/*********************************************************************************
 *                          Pre compile switches                              *
 ********************************************************************************/
/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                (STD_ON)


/* Precompile option for setting Pin direction API */
#define PORT_SET_PIN_DIRECTION_API            (STD_ON)

/* Precompile option to set pin mode API */
#define PORT_SET_PIN_MODE_API                 (STD_ON)

/* Precompile and Post Build option for Port pin mode changeability */
#define PORT_PIN_MODE_CHANGEABLE              (STD_ON)

/* Precompile and Post Build option for Port pin Direction changeability */
#define PORT_PIN_DIRECTION_CHANGEABLE         (STD_ON)
/********************************************************************************/

/*******************************************************************************
 *                                   Macros                                    *
 *******************************************************************************/
/*PORT_INDEXS*/
#define PORTA_INDEX    ((uint8)0x00)
#define PORTB_INDEX    ((uint8)0x01)
#define PORTC_INDEX    ((uint8)0x02)

/*Number of Port Pins*/
#define NUMBER_OF_PORT_PINS ((uint8)32)

/*PIN_Index*/
#define PIN_INDEX_0     (0)
#define PIN_INDEX_1     (1)
#define PIN_INDEX_2     (2)
#define PIN_INDEX_3     (3)
#define PIN_INDEX_4     (4)
#define PIN_INDEX_5     (5)
#define PIN_INDEX_6     (6)
#define PIN_INDEX_7     (7)
#define PIN_INDEX_8     (8)
#define PIN_INDEX_9     (9)
#define PIN_INDEX_10    (10)
#define PIN_INDEX_11    (11)
#define PIN_INDEX_12    (12)
#define PIN_INDEX_13    (13)
#define PIN_INDEX_14    (14)
#define PIN_INDEX_15    (15)

/*********Port Pins IDs***********/
/*PORTA*/
#define PORTA_PIN0     ((Port_PinType)0)
#define PORTA_PIN1     ((Port_PinType)1)
#define PORTA_PIN2     ((Port_PinType)2)
#define PORTA_PIN3     ((Port_PinType)3)
#define PORTA_PIN4     ((Port_PinType)4)
#define PORTA_PIN5     ((Port_PinType)5)
#define PORTA_PIN6     ((Port_PinType)6)
#define PORTA_PIN7     ((Port_PinType)7)
#define PORTA_PIN8     ((Port_PinType)8)
#define PORTA_PIN9     ((Port_PinType)9)
#define PORTA_PIN10    ((Port_PinType)10)
#define PORTA_PIN11    ((Port_PinType)11)
#define PORTA_PIN12    ((Port_PinType)12)
#define PORTA_PIN15    ((Port_PinType)13)
/*PORTB*/
#define PORTB_PIN0     ((Port_PinType)14)
#define PORTB_PIN1     ((Port_PinType)15)
#define PORTB_PIN3     ((Port_PinType)16)
#define PORTB_PIN4     ((Port_PinType)17)
#define PORTB_PIN5     ((Port_PinType)18)
#define PORTB_PIN6     ((Port_PinType)19)
#define PORTB_PIN7     ((Port_PinType)20)
#define PORTB_PIN8     ((Port_PinType)21)
#define PORTB_PIN9     ((Port_PinType)22)
#define PORTB_PIN10    ((Port_PinType)23)
#define PORTB_PIN11    ((Port_PinType)24)
#define PORTB_PIN12    ((Port_PinType)25)
#define PORTB_PIN13    ((Port_PinType)26)
#define PORTB_PIN14    ((Port_PinType)27)
#define PORTB_PIN15    ((Port_PinType)28)
/*PORTC*/
#define PORTC_PIN13    ((Port_PinType)29)//on board led
#define PORTC_PIN14    ((Port_PinType)30)
#define PORTC_PIN15    ((Port_PinType)31)

/************** Pins_runtime_behaviour_configuration ****************/
#define PORT_A_PIN_0_DIR_CHANG          (STD_OFF)
#define PORT_A_PIN_1_DIR_CHANG          (STD_OFF)
#define PORT_A_PIN_2_DIR_CHANG          (STD_OFF)
#define PORT_A_PIN_3_DIR_CHANG          (STD_OFF)
#define PORT_A_PIN_4_DIR_CHANG          (STD_OFF)
#define PORT_A_PIN_5_DIR_CHANG          (STD_OFF)
#define PORT_A_PIN_6_DIR_CHANG          (STD_OFF)
#define PORT_A_PIN_7_DIR_CHANG          (STD_OFF)
#define PORT_A_PIN_8_DIR_CHANG          (STD_OFF)
#define PORT_A_PIN_9_DIR_CHANG          (STD_OFF)
#define PORT_A_PIN_10_DIR_CHANG         (STD_OFF)
#define PORT_A_PIN_11_DIR_CHANG         (STD_OFF)
#define PORT_A_PIN_12_DIR_CHANG         (STD_OFF)
#define PORT_A_PIN_13_DIR_CHANG         (STD_OFF)
#define PORT_A_PIN_14_DIR_CHANG         (STD_OFF)
#define PORT_A_PIN_15_DIR_CHANG         (STD_OFF)

#define PORT_B_PIN_0_DIR_CHANG          (STD_OFF)
#define PORT_B_PIN_1_DIR_CHANG          (STD_OFF)
#define PORT_B_PIN_2_DIR_CHANG          (STD_OFF)
#define PORT_B_PIN_3_DIR_CHANG          (STD_OFF)
#define PORT_B_PIN_4_DIR_CHANG          (STD_OFF)
#define PORT_B_PIN_5_DIR_CHANG          (STD_OFF)
#define PORT_B_PIN_6_DIR_CHANG          (STD_OFF)
#define PORT_B_PIN_7_DIR_CHANG          (STD_OFF)
#define PORT_B_PIN_8_DIR_CHANG          (STD_OFF)
#define PORT_B_PIN_9_DIR_CHANG          (STD_OFF)
#define PORT_B_PIN_10_DIR_CHANG         (STD_OFF)
#define PORT_B_PIN_11_DIR_CHANG         (STD_OFF)
#define PORT_B_PIN_12_DIR_CHANG         (STD_OFF)
#define PORT_B_PIN_13_DIR_CHANG         (STD_OFF)
#define PORT_B_PIN_14_DIR_CHANG         (STD_OFF)
#define PORT_B_PIN_15_DIR_CHANG         (STD_OFF)

#define PORT_C_PIN_0_DIR_CHANG          (STD_OFF)
#define PORT_C_PIN_1_DIR_CHANG          (STD_OFF)
#define PORT_C_PIN_2_DIR_CHANG          (STD_OFF)
#define PORT_C_PIN_3_DIR_CHANG          (STD_OFF)
#define PORT_C_PIN_4_DIR_CHANG          (STD_OFF)
#define PORT_C_PIN_5_DIR_CHANG          (STD_OFF)
#define PORT_C_PIN_6_DIR_CHANG          (STD_OFF)
#define PORT_C_PIN_7_DIR_CHANG          (STD_OFF)
#define PORT_C_PIN_8_DIR_CHANG          (STD_OFF)
#define PORT_C_PIN_9_DIR_CHANG          (STD_OFF)
#define PORT_C_PIN_10_DIR_CHANG         (STD_OFF)
#define PORT_C_PIN_11_DIR_CHANG         (STD_OFF)
#define PORT_C_PIN_12_DIR_CHANG         (STD_OFF)
#define PORT_C_PIN_13_DIR_CHANG         (STD_OFF)
#define PORT_C_PIN_14_DIR_CHANG         (STD_OFF)
#define PORT_C_PIN_15_DIR_CHANG         (STD_OFF)
/*******************************************************************/

/********************************************************************************/
#endif /* MCAL_PORT_PORT_CFG_H_ */
