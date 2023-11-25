  /*
  ******************************************************************************
  * @file    Det.c
  * @author  Mo'men Elhoseiny
  * @brief   Det stores the development errors reported by other modules.
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


/*=================================*/
  /*
   *  Includes section
   */
		#include "../../Inc/DET/Det.h"
/*=================================*/
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
                      uint8 ErrorId )
{
	while(1){

	}
    return E_OK;
}
