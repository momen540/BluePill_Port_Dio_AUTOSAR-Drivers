  /*
  ******************************************************************************
  * @file    Dio.h
  * @author  Mo'men Elhoseiny
  * @brief   Header file for STM32F103c8t6 Microcontroller - Dio Driver
  * @Date    Created on July 26, 2023
  ******************************************************************************
  */
  /*===============================================================================
  *  Project			: AUTOSAR 4.4.0 MCAL
  *  Platform			: ARM
  *  Peripheral			: STM32F103c8t6
  *  Autosar vesion  	: 4.4.0
  *  Autosar Revesion	: ASR_REL_4_0_REV_0000
  *  SW Version			: 1.0.0
  *===============================================================================*/

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_
/*=================================*/
  /*
   *  Includes section
   */
		#include <Common/Std_Types.h>
		#include "../../DET/Det.h"
		#include "Dio_cfg.h"
/*=================================*/

/*******************************************************************************
 *                             Version Definitions                             *
 *******************************************************************************/

/*
 * Id for the company in the AUTOSAR
 */
#define DIO_VENDOR_ID    (1000U)

/* Dio Instance Id */
#define DIO_INSTANCE_ID  (0U)

/* Dio Module Id from BSW document*/
#define DIO_MODULE_ID    (120U)
/*
 * Module Version 1.0.0
 */
#define DIO_SW_MAJOR_VERSION           (1U)
#define DIO_SW_MINOR_VERSION           (0U)
#define DIO_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.4.0
 */
#define DIO_AR_RELEASE_MAJOR_VERSION   (4U)
#define DIO_AR_RELEASE_MINOR_VERSION   (4U)
#define DIO_AR_RELEASE_PATCH_VERSION   (0U)
/*******************************************************************************/

/*******************************************************************************
 *                                Version Check                                *
 *******************************************************************************/
/* AUTOSAR checking between Std Types and Dio Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* AUTOSAR Version checking between Det and Dio Modules */
#if ((DET_AR_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#if ((DIO_CFG_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (DIO_CFG_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (DIO_CFG_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Dio_Cfg.h does not match the expected version"
#endif
/*******************************************************************************/

/*******************************************************************************
 *                             Development Errors	                           *
 *******************************************************************************/
/*Invalid channel requested*/
#define DIO_E_PARAM_INVALID_CHANNEL_ID 							     ((uint8)0x0A)
/*Invalid port requested*/
#define DIO_E_PARAM_INVALID_PORT_ID									 ((uint8)0x14)
/*Invalid channel group requested*/
#define DIO_E_PARAM_INVALID_GROUP									 ((uint8)0x1F)
/*API service called with a NULL pointer*/
#define DIO_E_PARAM_POINTER											 ((uint8)0x20)
/*******************************************************************************/

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for DIO read Channel  from DIO SWS doc.*/
#define DIO_READ_CHANNEL_SID           ((uint8)0x00)

/* Service ID for DIO write Channel */
#define DIO_WRITE_CHANNEL_SID          ((uint8)0x01)

/* Service ID for DIO read Port */
#define DIO_READ_PORT_SID              ((uint8)0x02)

/* Service ID for DIO write Port */
#define DIO_WRITE_PORT_SID             ((uint8)0x03)

/* Service ID for DIO read Channel Group */
#define DIO_READ_CHANNEL_GROUP_SID     ((uint8)0x04)

/* Service ID for DIO write Channel Group */
#define DIO_WRITE_CHANNEL_GROUP_SID    ((uint8)0x05)

/* Service ID for DIO GetVersionInfo */
#define DIO_GET_VERSION_INFO_SID       ((uint8)0x12)

/* Service ID for DIO Masked Write Port */
#define DIO_MASKED_WRITE_PORT_SID      ((uint8)0x13)

/* Service ID for DIO flip Channel */
#define DIO_FLIP_CHANNEL_SID           ((uint8)0x11)
/*******************************************************************************/


/*******************************************************************************
 *                         		       Macros                                  *
 *******************************************************************************/
/*DIO_CHANNEL_MODE*/
/*
 * @Brief      : indication that the DIO channel is used as an input
 * @implements : DIO_Mode Enumeration
 */
#define DIO_INPUT		((DIO_Mode)0)
/*
 * @Brief      : indication that the DIO channel is used as an An oputput
 * @implements : DIO_Mode Enumeration
 */
#define DIO_OUTPUT		((DIO_Mode)1)
/*
 * @Brief      : indication that the Channel is not DIO
 * @implements : DIO_Mode Enumeration
 */
#define DIO_AF		    ((DIO_Mode)2)
/*******************************************************************************/

/*******************************************************************************
 *                          User Defined Data Types                            *
 *******************************************************************************/


/*
 * Type definition for Dio_ChannelType used by the DIO APIs
 */
typedef uint8 Dio_ChannelType;


/*
 *  Type definition for Dio_PortType used by the DIO APIs
 */
typedef uint8 Dio_PortType;


/*
 * Type definition for Possiple level of DIO channel
 * 0 = STD_LEVEL_LOW
 * 1 = STD_LEVEL_HIGH
 */
typedef uint8 Dio_LevelType;


/*
 * Type definition for Dio_PortLevelType used by the DIO APIs
 */
typedef uint16 Dio_PortLevelType;

/*
 *Typedef for channel mode input/output
 */
typedef uint8 DIO_Mode;

/*
 * Structure for Dio_ChannelGroup
 */
typedef struct
{
  /* Mask which defines the positions of the channel group */
  uint16 mask;
  /* Position of the group from LSB */
  uint16 offset;
  /* This shall be the port ID which the Channel group is defined. */
  Dio_PortType PortIndex;
} Dio_ChannelGroupType;

/*
 * Structure for single channel configuration
 */
typedef struct{

	uint8 Port:2;/*
				  * @Brief : Port ID for the channel
				  * @Ref   : Port_ID in Dio_cfg.h
				  */

	uint8 Pin:4; /*
				  * @Brief : Pin ID for the channel
				  * @Ref   : DIO_Channel_Index in Dio_cfg.h
				  */

	DIO_Mode Mode;/*
				   * @Brief : Pin Mode for the channel
				   * @Ref   : DIO_CHANNEL_MODE
				   */
}Dio_ChannelConfig;

/*
 * Structure for all channels configurations
 */
typedef struct{
	Dio_ChannelConfig Channel[NUMBER_OF_DIO_CHANNELS];
}Dio_ConfigChannel;
/*******************************************************************************/

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
extern const Dio_ConfigChannel Dio_Configuration;
/*******************************************************************************/

/*******************************************************************************
 *                              Function Prototypes                            *
 *******************************************************************************/

/*
 * @Name  : Dio_ReadChannel.
 * @Service ID : 0x00
 * @Sync/Async : Synchronous.
 * @Reentrancy : Reentrant.
 * @Brief : Function receives a channel and returns it's state.
 * @Parameter ChannelId : ID Of DIO Channel.
 * @return :  Returns the value of specified DIO Channel :
 *			  STD_LEVEL_HIGH : Physical level of the pin  is HIGH.
 *			  STD_LEVEL_LOW : Physical level of the pin  is LOW.
 */
Dio_LevelType Dio_ReadChannel (
		Dio_ChannelType ChannelId
		);
/*
 * @Name  : Dio_WriteChannel.
 * @Service ID : 0x01
 * @Sync/Async : Synchronous.
 * @Reentrancy : Reentrant.
 * @Brief : Function writes value on given channel.
 * @Parameter ChannelId : ID Of DIO Channel.
 * @Parameter Level : Value to be written on channel
 * @return : No return
 */
void Dio_WriteChannel (
		Dio_ChannelType ChannelId,
		Dio_LevelType Level
		);
/*
 * @Name  : Dio_ReadPort
 * @Service ID : 0x02
 * @Sync/Async : Synchronous.
 * @Reentrancy : Reentrant.
 * @Brief : Returns the level of all channels of that port.
 * @Parameter PortId : ID of DIO Port
 * @return Dio_PortLevelType : Returns the level of all channels of that port.
 */
Dio_PortLevelType Dio_ReadPort (
		Dio_PortType PortId
		);

/*
 * @Name  : Dio_WritePort.
 * @Service ID : 0x03
 * @Sync/Async : Synchronous.
 * @Reentrancy : Reentrant.
 * @Brief : Function writes value on given port.
 * @Parameter PortId : ID Of DIO Port.
 * @Parameter Level : Value to be written on Port.
 * @return : No return
 */
void Dio_WritePort (
		Dio_PortType PortId,
		Dio_PortLevelType Level
		);

/*
 * @Name  : Dio_ReadChannelGroup
 * @Service ID : 0x04
 * @Sync/Async : Synchronous.
 * @Reentrancy : Reentrant.
 * @Brief : This Service reads a subset of the adjoining bits of a port.
 * @Parameter ChannelGroupIdPtr : Pointer to ChannelGroup
 * @return Dio_PortLevelType : Level of a subset of the adjoining bits of a port
 *
 */
Dio_PortLevelType Dio_ReadChannelGroup (
		const Dio_ChannelGroupType* ChannelGroupIdPtr
		);

/*
 * @Name  : Dio_WriteChannelGroup
 * @Service ID : 0x05
 * @Sync/Async : Synchronous.
 * @Reentrancy : Reentrant.
 * @Brief : Service to set a subset of the adjoining bits of a port to a specified level.
 * @Parameter ChannelGroupIdPtr : Pointer to ChannelGroup
 * @Parameter Level : Value to be written ChannelGroup
 * @return : No return
 */
void Dio_WriteChannelGroup (
		const Dio_ChannelGroupType* ChannelGroupIdPtr,
		Dio_PortLevelType Level );

#if DIO_VERSION_INFO_API == STD_ON
/*
 * @Name  : Dio_GetVersionInfo
 * @Service ID : 0x12
 * @Brief : Service to get the version information of this module.
 * @Parameter : Pointer to store version info for the module.
 * @return : No return
 */
void Dio_GetVersionInfo (
		Std_VersionInfoType* VersionInfo
		);
#endif
#if DIO_FLIP_CHANNEL_API == STD_ON
/*
 * @Name  : Dio_FlipChannel
 * @Service ID : 0x11
 * @Sync/Async : Synchronous.
 * @Reentrancy : Reentrant.
 * @Brief : Service to toggle channel
 * @Parameter ChannelId : ID Of DIO Channel.
 * @return :  Returns the value of specified DIO Channel :
 *			  STD_LEVEL_HIGH : Physical level of the pin  is HIGH.
 *			  STD_LEVEL_LOW : Physical level of the pin  is LOW.
 */
Dio_LevelType Dio_FlipChannel (
		Dio_ChannelType ChannelId
		);
#endif
/*
 * @Name  : Dio_MaskedWritePort
 * @Service ID : 0x13
 * @Sync/Async : Synchronous.
 * @Reentrancy : Reentrant.
 * @Brief : Service to set the value of a given port with required mask.
 * @Parameter PortId : ID of DIO Port.
 * @Parameter Level : Value to be written.
 * @Parameter Mask : Channels to be masked in the port.
 * @return : No return
 */
void Dio_MaskedWritePort (
		Dio_PortType PortId,
		Dio_PortLevelType Level,
		Dio_PortLevelType Mask
		);

/*******************************************************************************/


#endif /* MCAL_DIO_DIO_H_ */
