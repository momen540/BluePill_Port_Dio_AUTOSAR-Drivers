  /*
  * @file    Port.h
  * @author  Mo'men Elhoseiny
  * @brief   Header file for AUTOSAR STM32F103c8t6 Microcontroller - Port Driver
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

#ifndef MCAL_PORT_PORT_H_
#define MCAL_PORT_PORT_H_

/*=================================*/
  /*
   *  Includes section
   */
		#include <Common/Std_Types.h>
        #include "Port_cfg.h"
		#include "../../DET/Det.h"
/*=================================*/

/*******************************************************************************
 *                             Version Definitions                             *
 *******************************************************************************/

#define PORT_VENDOR_ID_H  (2000U)

/* Port Module Id */
#define PORT_MODULE_ID    (124U)

/* PORT Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * SW Module Version is 1.0.0
 */
#define PORT_SW_MAJOR_VERSION             (1U)
#define PORT_SW_MINOR_VERSION             (0U)
#define PORT_SW_PATCH_VERSION             (0U)

/*
 * AUTOSAR Version is 4.4.0 compatible
 */
#define PORT_AR_RELEASE_MAJOR_VERSION    (4U)
#define PORT_AR_RELEASE_MINOR_VERSION    (4U)
#define PORT_AR_RELEASE_PATCH_VERSION    (0U)
/*******************************************************************************/

/*******************************************************************************
 *                                Version Check                                *
 *******************************************************************************/
/* AUTOSAR checking between Std Types and PORT Modules */

#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* AUTOSAR Version checking between PORT_Cfg.h and PORT.h files */

#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif
/*******************************************************************************/

/***************************************************************
 *                       DET Error Codes                       *
 ***************************************************************/
/* Invalid Port ID request */
#define PORT_E_PARAM_PIN                 ((uint8)0x0A)

/* Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE    ((uint8)0x0B)

/* API Port_Init service called with wrong parameters */
#define PORT_E_PARAM_CONFIG              ((uint8)0x0C)

/* API Port_SetPinMode service called with invalid mode */
#define PORT_E_PARAM_INVALID_MODE        ((uint8)0x0D)

/* API Port_SetPinMode service called, when mode is unchangeable */
#define PORT_E_MODE_UNCHANGEABLE         ((uint8)0x0E)

/* API sevice called without module initialization */
#define PORT_E_UNINIT                    ((uint8)0x0F)

/* APIs called with a NULL Pointer, Error shall be reported */
#define PORT_E_PARAM_POINTER             ((uint8)0x10)
/***************************************************************/

/******************************************************************************
 *                          API Service Id Macros                             *
 ******************************************************************************/
  /* API service ID for PORT Init function.
   */
#define PORT_INIT_ID                    ((uint8)0x00)

/*   API service ID for PORT set pin direction function.
 */
#define PORT_SETPINDIRECTION_ID         ((uint8)0x01)

/*  API service ID for PORT refresh pin direction function.
 */
#define PORT_REFRESHPINDIRECTION_ID     ((uint8)0x02)

/*
 API service ID for PORT get version info function.
 */
#define PORT_GETVERSIONINFO_ID          ((uint8)0x03)

/*
 * API service ID for PORT set pin Mode function.
 */
#define PORT_SETPINMODE_ID              ((uint8)0x04)
/******************************************************************************/

/*******************************************************************************
 *                                 Macros                                      *
 *******************************************************************************/

/**************************** Pin_Speed *********************************/
/*
 * @Brief 		: selects bin mode to be input
 * @Implements  : Port_PinSpeed Enumeration
 */
#define SPEED_MODE_INPUT					   				   ((Port_PinSpeed)0)
/*
 * @Brief 		: selects bin mode to be Output with speed 10MHZ
 * @Implements  : Port_PinSpeed Enumeration
 */
#define SPEED_10_MHZ					     				   ((Port_PinSpeed)1)
/*
 * @Brief 		: selects bin mode to be Output with speed 2MHZ
 * @Implements  : Port_PinSpeed Enumeration
 */
#define SPEED_2_MHZ											   ((Port_PinSpeed)2)
/*
 * @Brief 		: selects bin mode to be Output with speed 50MHZ
 * @Implements  : Port_PinSpeed Enumeration
 */
#define SPEED_50_MHZ										   ((Port_PinSpeed)3)
/*******************************************************************************/

/******************************* Pin_Modes *************************************/
/* Output */

/*
 * @Brief 		: selects pin mode to be Output with push-pull configuration.
 * @Implements  : Port_PinModeType Enumeration
 */
#define OUT_PUSH_PULL                                   	((Port_PinModeType)0)
/*
 * @Brief 		: selects pin mode to be Output with Open-Drain configuration.
 * @Implements  : Port_PinModeType Enumeration
 */
#define OUT_OPEN_DRAIN								        ((Port_PinModeType)1)
/*
 * @Brief 		: selects pin mode to be Alternative function with push-pull configuration.
 * @Implements  : Port_PinModeType Enumeration
 */
#define AF_PUSH_PULL										((Port_PinModeType)2)
/*
 * @Brief 		: selects pin mode to be Alternative function with Open-Drain configuration.
 * @Implements  : Port_PinModeType Enumeration
 */
#define AF_OPEN_DRAIN					   				    ((Port_PinModeType)3)
/* Input */
/*
 * @Brief 		: selects pin mode to be Analog Input
 * @Implements  : Port_PinModeType Enumeration
 * @notice      : pin speed must be set to input mode
 */
#define ANALOG_INPUT					    				((Port_PinModeType)4)
/*
 * @Brief 		: selects pin mode to be Input
 * @Implements  : Port_PinModeType Enumeration
 * @notice      : pin speed must be set to input mode
 */
#define INPUT												((Port_PinModeType)5)
/*******************************************************************************/

/*Port_Module_status*/
/*
 * The API Port_Init has not been called.
 */
#define PORT_NOT_INITIALIZED ((uint8)0)
/*
 * The API Port_Init has been called.
 */
#define PORT_INITIALIZED 	 ((uint8)1)


/*******************************************************************************/


/*******************************************************************************
 *                          User Defined Data Types                            *
 *******************************************************************************/

/*
 * Data type for the symbolic name of a port pin.
 */
typedef uint8 Port_PinType;
/*
 * Different port pin modes.
 */
typedef uint8 Port_PinModeType;
/*
 * Output pin speed
 */
typedef uint8 Port_PinSpeed;

/*
 * Data type for the symbolic name of a port pin.
 */
typedef enum{
	PORT_PIN_IN = 0x00, //Sets port pin as input.
	PORT_PIN_OUT= 0x01  //Sets port pin as input.
}Port_PinDirectionType;

/*
 * Description: Enum to hold internal/External resistor connection for PIN
 */
typedef enum
{
	Floating,
	Pull_UP,
	Pull_DOWN
}Port_InternalResistor;

/*
 * structure to configure a single pin
 */
typedef struct{
	uint8                 Port      	 :2;/*
											 *@Brief : used to select port at which the pin resides
											 *@Ref   : PORT_INDEXS In Port_cfg.h
											 */
	uint8                 Pin_index		 :4;/*
											 *@Brief : used to select Pin index
											 *@Ref   : PIN_Index In Port_cfg.h
											 */
	Port_PinSpeed         Speed    		 :3;/*
											 *@Brief : used to Configure port pin speed
											 *@Ref   : Pin_Speed
											 */
	Port_PinModeType      Mode     		 :3;/*
											 *@Brief : used to Configure port pin Mood
											 *@Ref   : Pin_Modes
											 */

	Port_InternalResistor Pull     		 :2;/*
											 *@Brief : used to Configure port pin pull up/down status
											 *@Ref   : Port_PinDirectionType
											 */
	uint8                 Initial_Logic	 :1;/*
											 *@Brief : used to Configure port pin Initial state
											 *@Description
											 *            STD_HIGH : Initial state of the pin is High
											 *            STD_LOW  : Initial state of the pin is Low
											 */
	uint8			      DirectionChange:1;/*
											 *@Brief : used to Configure if the pin direction is changable during run-time
											 *@Ref   : Pins_runtime_behaviour_configuration in Port_cfg.h
											 *@Description
											 *            STD_ON   : Run Time Direction is changable and pins are unlocked
											 *            STD_LOW  : Run Time Direction is un-changable and pins are locked
											 */
}Port_ConfigPins;

/*
 * Type of the external data structure containing the initialization data for this module.
 */
typedef struct{
	Port_ConfigPins Pins[NUMBER_OF_PORT_PINS];
}Port_ConfigType;

/*******************************************************************************/

/*******************************************************************************
 *                            External Variables                               *
 *******************************************************************************/
extern const Port_ConfigType Port_Configuration;
/*******************************************************************************/

/*******************************************************************************
 *                              Function Prototypes                            *
 *******************************************************************************/
/*
 * @Name Port_Init
 * @Service ID : 0x00.
 * @Sync/Async : Synchronous.
 * @Reentrancy : Non Reentrant.
 * @Brief : Initializes the Port Driver module.
 * @Parameter ConfigPtr : Pointer to configuration set.
 * @return : no return.
 */
void Port_Init (
const Port_ConfigType* ConfigPtr
);

#if PORT_SET_PIN_DIRECTION_API == STD_ON
/*
 * @Name Port_SetPinDirection
 * @Service ID : 0x01.
 * @Sync/Async : Synchronous.
 * @Reentrancy : Reentrant.
 * @Brief : Sets the port pin direction
 * @Parameter Pin : Pin ID to configure.
 * @Parameter Direction : Direction of pin.
 * @return : no return.
 */
void Port_SetPinDirection (
Port_PinType Pin,
Port_PinDirectionType Direction
);
#endif
#if PORT_SET_PIN_MODE_API == STD_ON

/*
 * @Name Port_SetPinMode
 * @Service ID : 0x04.
 * @Sync/Async : Synchronous.
 * @Reentrancy : Reentrant.
 * @Brief : Sets Port Pin Mode.
 * @Parameter Pin : Pin ID to configure.
 * @Parameter Direction : Mode of pin.
 * @return: no return.
 */
void Port_SetPinMode (
Port_PinType Pin,
Port_PinModeType Mode
);
#endif

/*
 * @Name Port_RefreshPortDirection
 * @Service ID : 0x02.
 * @Sync/Async : Synchronous.
 * @Reentrancy : Reentrant.
 * @Brief : Refreshes port direction.
 * @Parameter: no Parameters
 * @return: no return.
 */
void Port_RefreshPortDirection (
void
);

#if PORT_DEV_ERROR_DETECT == STD_ON
/* @Name : Port_GetVersionInfo
 * @Service ID : 0x03.
 * @Sync/Async : Synchronous.
 * @Reentrancy : Reentrant.
 * @Brief :Returns the version information of this module.
 * @Parameter : Pointer to where to store the version information of this module.
 * @Return : No Return.
 */
void Port_GetVersionInfo (
Std_VersionInfoType* versioninfo
);
#endif
/*******************************************************************************/



#endif /* MCAL_PORT_PORT_H_ */
