 /*
 * @ file    		Platform_Types.h
 * @ author  		Mo'men Elhoseiny
 * @ brief			Platform dependent data types and definitions
 * @ Description	AUTOSAR Platform Header file for storing the development errors reported by other software modules.
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

#ifndef DET_DET_H
#define DET_DET_H

/*=================================*/
  /*
   *  Includes section
   */
		#include <Common/Std_Types.h>
/*=================================*/

/*******************************************************************************
 *                             Version Definitions                             *
 *******************************************************************************/
/* Instance Id */
#define DET_INSTANCE_ID               (0U)

/*
 * Det Software Module Version 1.0.0
 */
#define DET_SW_MAJOR_VERSION          (1U)
#define DET_SW_MINOR_VERSION          (0U)
#define DET_SW_PATCH_VERSION          (0U)

/*
 * AUTOSAR Version 4.4.0
 */
#define DET_AR_MAJOR_VERSION          (4U)
#define DET_AR_MINOR_VERSION          (4U)
#define DET_AR_PATCH_VERSION          (0U)

/* AUTOSAR checking between Std Types and Det Modules */
#if ((DET_AR_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif
/*******************************************************************************/


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
/*
 * @Name Det_ReportError
 * @Service ID : 0x01.
 * @Sync/Async : Not Applicable: The function never returns.
 * @Reentrancy : Reentrant.
 * @Brief : Used to report Development errors
 * @Parameter ModuleId : Module ID of calling module.
 * @Parameter InstanceId : The identifier of the index based instance of a module
 * @Parameter ApiId : ID of API service in which error is detected (defined in SWS of calling module)
 * @Parameter ErrorId : ID of detected development error (defined in SWS of calling module).
 * @return : never returns a value, but has a return type for compatibility with services and hooks
 */
Std_ReturnType Det_ReportError( uint16 ModuleId,
                                uint8 InstanceId,
                                uint8 ApiId,
								uint8 ErrorId );
/*******************************************************************************/

#endif /* DET_DET_H */
