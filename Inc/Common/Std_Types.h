 /*
 * @ file    		Platform_Types.h
 * @ author  		Mo'men Elhoseiny
 * @ brief			AUTOSAR Base - Standard data types definition
 * @ Description	AUTOSAR Standard data types definitions
 * 					Contains all types used acros several modules of basic software thar are platform and compiler Independent
 * @ Date    		Created on July 26, 2023
 */

 /*===============================================================================
 *  Project				: AUTOSAR 4.4.0 MCAL
 *  Platform			: ARM
 *  Peripheral			: STM32F103c8t6
 *  Autosar vesion  	: 4.4.0
 *  Autosar Revesion	: ASR_REL_4_0_REV_0000
 *  SW Version			: 1.0.0
 *===============================================================================*/
#ifndef STD_TYPES_H
#define	STD_TYPES_H

/*=================================*/
/* Includes section */

/*
 * @breif : include compiler abstraction
 */
#include <Common/Compiler.h>

/*
 * @breif : include platform types abstraction
 */
#include <Common/Platform_Types.h>
/*=================================*/

/*******************************************************************************
 *                             Version Definitions                             *
 *******************************************************************************/

/*
 * Id for the company in the AUTOSAR
 */
#define STD_TYPES_VENDOR_ID                                  (1000U)

/*
 * Module Version 1.0.0
 */
#define STD_TYPES_SW_MAJOR_VERSION                           (1U)
#define STD_TYPES_SW_MINOR_VERSION                           (0U)
#define STD_TYPES_SW_PATCH_VERSION                           (0U)

/*
 * AUTOSAR Version 4.4.0
 */
#define STD_TYPES_AR_RELEASE_MAJOR_VERSION                   (4U)
#define STD_TYPES_AR_RELEASE_MINOR_VERSION                   (4U)
#define STD_TYPES_AR_RELEASE_PATCH_VERSION                   (0U)
/*******************************************************************************/

/*******************************************************************************
 *                                Version Check                                *
 *******************************************************************************/
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PLATFORM_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PLATFORM_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != COMPILER_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != COMPILER_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != COMPILER_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif
 /*******************************************************************************/

/*******************************************************************************
 *                                 Macros                                      *
 *******************************************************************************/


/*
 * @ Brief : 	Describes the standard Return Type Definitions used in the project
 */
typedef uint8 Std_ReturnType;

/*Macro Declarations */

/*
 * @ Brief 		:	Physical state High 3.3v
 * @ implements :	Enumeration
 */
#define STD_HIGH   (0X01)

/*
 * @ Brief 		:	Physical state Low 0v
 * @ implements :	Enumeration
 */
#define STD_LOW    (0X00)

/*
 * @ Brief 		:	On State
 * @ implements :	Enumeration
 */
#define STD_ON     (0X01)

/*
 * @ Brief 		:	Off State
 * @ implements :	Enumeration
 */
#define STD_OFF    (0X00)

/*
 * @ Brief 		:	Signal State Active
 * @ implements :	Enumeration
 */
#define STD_ACTIVE (0X01)

/*
 * @ Brief 		:	Signal State Idle
 * @ implements :	Enumeration
 */
#define STD_IDLE   (0X00)


/*
 * @ Brief 		:	Return Code for failure/error
 * @ implements :	Enumeration
 */
#define E_NOT_OK   ((Std_ReturnType)0X00)

#ifndef STATUSTYPEDEFINED
	#define STATUSTYPEDEFINED
	/*
	 * @ Brief 		:	Return Code for success
	 * @ implements :	Enumeration
	 */
	#define E_OK       ((Std_ReturnType)0X01)
	/*
	 * @ Note	:	This Type is defined in OSEK
	 */
#endif
/*End of Macro Declarations*/

/*
 * Structure for the Version of the module.
 * This is requested by calling <Module name>_GetVersionInfo()
 */
/*******************************************************************************/

/*******************************************************************************
 *                          User Defined Data Types                            *
 *******************************************************************************/
typedef struct
{
  uint16  vendorID;
  uint16  moduleID;
  uint8   sw_major_version;
  uint8   sw_minor_version;
  uint8   sw_patch_version;
} Std_VersionInfoType;
/*******************************************************************************/

/*********************************** End of User Defined Data types Section ************************************/
#endif	/* STD_TYPES_H */
