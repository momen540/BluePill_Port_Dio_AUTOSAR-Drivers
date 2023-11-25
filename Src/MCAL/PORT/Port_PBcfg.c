  /*
  ***********************************************************************************************
  * @file    Port_PBcfg.c																		*
  * @author  Mo'men Elhoseiny																	*
  * @brief   Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Port Driver*
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
#ifndef MCAL_PORT_PORT_PBCFG_C_
#define MCAL_PORT_PORT_PBCFG_C_

/*=================================*/
  /*
   *  Includes section
   */
		#include "../../../Inc/MCAL/PORT/Port.h"
/*=================================*/
/*******************************************************************************
 *                             Version Definitions                             *
 *******************************************************************************/
/*
* SW Module Version is 1.0.0
*/
#define PORT_PBCFG_SW_MAJOR_VERSION             (1U)
#define PORT_PBCFG_SW_MINOR_VERSION             (0U)
#define PORT_PBCFG_SW_PATCH_VERSION             (0U)

/*
* AUTOSAR Version is 4.4.0 compatible
*/
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION     (4U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION     (0U)

/* Check compatibility of Port.h AUTOSAR version with
* Port_PBcfg.c AUTOSAR version.
*/
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
	#error "The AR version of Port.h does not match the expected version"
#endif

/* Check compatibility of Port.h SW version with
* Port_PBcfg.c SW version.
*/
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
	#error "The AR version of Port.h does not match the expected version"
#endif
/*******************************************************************************/
/*
 * Variable contains all port pin configuration for the Blue Pill
 */
const Port_ConfigType Port_Configuration=
{
		/****  PORT A 	*****/
	PORTA_INDEX,PIN_INDEX_0,SPEED_2_MHZ,OUT_PUSH_PULL,Floating,STD_LOW,PORT_A_PIN_0_DIR_CHANG,
	PORTA_INDEX,PIN_INDEX_1,SPEED_2_MHZ,OUT_PUSH_PULL,Floating,STD_LOW,PORT_A_PIN_1_DIR_CHANG,
	PORTA_INDEX,PIN_INDEX_2,SPEED_2_MHZ,OUT_PUSH_PULL,Floating,STD_LOW,PORT_A_PIN_2_DIR_CHANG,
    PORTA_INDEX,PIN_INDEX_3,SPEED_2_MHZ,OUT_PUSH_PULL,Floating,STD_LOW,PORT_A_PIN_3_DIR_CHANG,
	PORTA_INDEX,PIN_INDEX_4,SPEED_MODE_INPUT,INPUT,Pull_UP,STD_HIGH,PORT_A_PIN_4_DIR_CHANG,
	PORTA_INDEX,PIN_INDEX_5,SPEED_MODE_INPUT,INPUT,Pull_UP,STD_HIGH,PORT_A_PIN_5_DIR_CHANG,
	PORTA_INDEX,PIN_INDEX_6,SPEED_MODE_INPUT,INPUT,Pull_UP,STD_HIGH,PORT_A_PIN_6_DIR_CHANG,
	PORTA_INDEX,PIN_INDEX_7,SPEED_MODE_INPUT,INPUT,Pull_UP,STD_HIGH,PORT_A_PIN_7_DIR_CHANG,
	PORTA_INDEX,PIN_INDEX_8,SPEED_2_MHZ,OUT_PUSH_PULL,Floating,STD_LOW,PORT_A_PIN_8_DIR_CHANG,
	PORTA_INDEX,PIN_INDEX_9,SPEED_2_MHZ,OUT_PUSH_PULL,Floating,STD_LOW,PORT_A_PIN_9_DIR_CHANG,
	PORTA_INDEX,PIN_INDEX_10,SPEED_2_MHZ,OUT_PUSH_PULL,Floating,STD_LOW,PORT_A_PIN_10_DIR_CHANG,
    PORTA_INDEX,PIN_INDEX_11,SPEED_2_MHZ,OUT_PUSH_PULL,Floating,STD_LOW,PORT_A_PIN_11_DIR_CHANG,
	PORTA_INDEX,PIN_INDEX_12,SPEED_2_MHZ,OUT_PUSH_PULL,Floating,STD_LOW,PORT_A_PIN_12_DIR_CHANG,
	PORTA_INDEX,PIN_INDEX_15,SPEED_2_MHZ,OUT_PUSH_PULL,Floating,STD_LOW,PORT_A_PIN_15_DIR_CHANG,
	/****  PORT B 	*****/
	PORTB_INDEX,PIN_INDEX_0,SPEED_2_MHZ,OUT_PUSH_PULL,Floating,STD_LOW,PORT_B_PIN_0_DIR_CHANG,
	PORTB_INDEX,PIN_INDEX_1,SPEED_2_MHZ,OUT_PUSH_PULL,Floating,STD_LOW,PORT_B_PIN_1_DIR_CHANG,
	PORTB_INDEX,PIN_INDEX_3,SPEED_2_MHZ,OUT_PUSH_PULL,Floating,STD_LOW,PORT_B_PIN_3_DIR_CHANG,
	PORTB_INDEX,PIN_INDEX_4,SPEED_2_MHZ,OUT_PUSH_PULL,Floating,STD_LOW,PORT_B_PIN_4_DIR_CHANG,
	PORTB_INDEX,PIN_INDEX_5,SPEED_2_MHZ,OUT_PUSH_PULL,Floating,STD_LOW,PORT_B_PIN_5_DIR_CHANG,
	PORTB_INDEX,PIN_INDEX_6,SPEED_2_MHZ,OUT_PUSH_PULL,Floating,STD_LOW,PORT_B_PIN_6_DIR_CHANG,
	PORTB_INDEX,PIN_INDEX_7,SPEED_2_MHZ,OUT_PUSH_PULL,Floating,STD_LOW,PORT_B_PIN_7_DIR_CHANG,
	PORTB_INDEX,PIN_INDEX_8,SPEED_2_MHZ,OUT_PUSH_PULL,Floating,STD_LOW,PORT_B_PIN_8_DIR_CHANG,
	PORTB_INDEX,PIN_INDEX_9,SPEED_2_MHZ,OUT_PUSH_PULL,Floating,STD_LOW,PORT_B_PIN_9_DIR_CHANG,
	PORTB_INDEX,PIN_INDEX_10,SPEED_50_MHZ,AF_PUSH_PULL,Floating,STD_LOW,PORT_B_PIN_10_DIR_CHANG,//UART3_TX
	PORTB_INDEX,PIN_INDEX_11,SPEED_MODE_INPUT,INPUT,Pull_UP,STD_HIGH,PORT_B_PIN_11_DIR_CHANG,//UART3_RX
	PORTB_INDEX,PIN_INDEX_12,SPEED_2_MHZ,OUT_PUSH_PULL,Floating,STD_LOW,PORT_B_PIN_12_DIR_CHANG,
	PORTB_INDEX,PIN_INDEX_13,SPEED_2_MHZ,OUT_PUSH_PULL,Floating,STD_LOW,PORT_B_PIN_13_DIR_CHANG,
	PORTB_INDEX,PIN_INDEX_14,SPEED_2_MHZ,OUT_PUSH_PULL,Floating,STD_LOW,PORT_B_PIN_14_DIR_CHANG,
	PORTB_INDEX,PIN_INDEX_15,SPEED_2_MHZ,OUT_PUSH_PULL,Floating,STD_LOW,PORT_B_PIN_15_DIR_CHANG,
	/****  PORT C 	*****/
	PORTC_INDEX,PIN_INDEX_13,SPEED_2_MHZ,OUT_PUSH_PULL,Floating,STD_HIGH,PORT_C_PIN_13_DIR_CHANG,
	PORTC_INDEX,PIN_INDEX_14,SPEED_MODE_INPUT,INPUT,Pull_UP,STD_HIGH,PORT_C_PIN_14_DIR_CHANG,
	PORTC_INDEX,PIN_INDEX_15,SPEED_MODE_INPUT,INPUT,Pull_UP,STD_HIGH,PORT_C_PIN_15_DIR_CHANG,
};

#endif /* MCAL_PORT_PORT_PBCFG_C_ */
