  /*
  * @file    Dio_cfg.h
  * @author  Mo'men Elhoseiny
  * @brief   Pre-Compile Configuration Header file for STM32F103c8t6 Microcontroller - Dio Driver
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
#ifndef DIO_CFG_H
#define DIO_CFG_H

/*=================================*/
  /*
   *  Includes section
   */

/*=================================*/
/*
 * Module Version 1.0.0
 */

#define DIO_CFG_SW_MAJOR_VERSION              (1U)
#define DIO_CFG_SW_MINOR_VERSION              (0U)
#define DIO_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.4.0
 */
#define DIO_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define DIO_CFG_AR_RELEASE_MINOR_VERSION     (4U)
#define DIO_CFG_AR_RELEASE_PATCH_VERSION     (0U)
/******************************************************************************
 *                          Pre compile switches                              *
 ******************************************************************************/
/* Pre-compile option for Development Error Detect */
#define DIO_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define DIO_VERSION_INFO_API                (STD_ON)

/* Pre-compile option for presence of Dio_FlipChannel API */
#define DIO_FLIP_CHANNEL_API                (STD_ON)
/******************************************************************************/
/*********DIO Pins IDs***********/
/*Number of used channels*/
#define NUMBER_OF_DIO_CHANNELS				((uint8)32)
/*Channels index*/
/*PORTA*/
#define DIO_PORTA_PIN0     ((Dio_ChannelType)0)
#define DIO_PORTA_PIN1     ((Dio_ChannelType)1)
#define DIO_PORTA_PIN2     ((Dio_ChannelType)2)
#define DIO_PORTA_PIN3     ((Dio_ChannelType)3)
#define DIO_PORTA_PIN4     ((Dio_ChannelType)4)
#define DIO_PORTA_PIN5     ((Dio_ChannelType)5)
#define DIO_PORTA_PIN6     ((Dio_ChannelType)6)
#define DIO_PORTA_PIN7     ((Dio_ChannelType)7)
#define DIO_PORTA_PIN8     ((Dio_ChannelType)8)
#define DIO_PORTA_PIN9     ((Dio_ChannelType)9)
#define DIO_PORTA_PIN10    ((Dio_ChannelType)10)
#define DIO_PORTA_PIN11    ((Dio_ChannelType)11)
#define DIO_PORTA_PIN12    ((Dio_ChannelType)12)
#define DIO_PORTA_PIN15    ((Dio_ChannelType)13)
/*PORTB*/
#define DIO_PORTB_PIN0     ((Dio_ChannelType)14)
#define DIO_PORTB_PIN1     ((Dio_ChannelType)15)
#define DIO_PORTB_PIN3     ((Dio_ChannelType)16)
#define DIO_PORTB_PIN4     ((Dio_ChannelType)17)
#define DIO_PORTB_PIN5     ((Dio_ChannelType)18)
#define DIO_PORTB_PIN6     ((Dio_ChannelType)19)
#define DIO_PORTB_PIN7     ((Dio_ChannelType)20)
#define DIO_PORTB_PIN8     ((Dio_ChannelType)21)
#define DIO_PORTB_PIN9     ((Dio_ChannelType)22)
#define DIO_PORTB_PIN10    ((Dio_ChannelType)23)
#define DIO_PORTB_PIN11    ((Dio_ChannelType)24)
#define DIO_PORTB_PIN12    ((Dio_ChannelType)25)
#define DIO_PORTB_PIN13    ((Dio_ChannelType)26)
#define DIO_PORTB_PIN14    ((Dio_ChannelType)27)
#define DIO_PORTB_PIN15    ((Dio_ChannelType)28)
/*PORTC*/
#define DIO_PORTC_PIN13    ((Dio_ChannelType)29)//on board led
#define DIO_PORTC_PIN14    ((Dio_ChannelType)30)
#define DIO_PORTC_PIN15    ((Dio_ChannelType)31)

/*Port_ID*/
#define DIO_PORTA					((uint8)1)
#define DIO_PORTB					((uint8)2)
#define DIO_PORTC					((uint8)3)

/*Number of DIO ports in the blue pill*/
#define DIO_NUMBER_OF_PORTS         ((uint8)3)

/*DIO_Channel_Index */
#define DIO_INDEX_0     (0)
#define DIO_INDEX_1     (1)
#define DIO_INDEX_2     (2)
#define DIO_INDEX_3     (3)
#define DIO_INDEX_4     (4)
#define DIO_INDEX_5     (5)
#define DIO_INDEX_6     (6)
#define DIO_INDEX_7     (7)
#define DIO_INDEX_8     (8)
#define DIO_INDEX_9     (9)
#define DIO_INDEX_10    (10)
#define DIO_INDEX_11    (11)
#define DIO_INDEX_12    (12)
#define DIO_INDEX_13    (13)
#define DIO_INDEX_14    (14)
#define DIO_INDEX_15    (15)

#endif /* DIO_CFG_H */
