  /*
  ******************************************************************************
  * @file    CortexM3_Core_SCB.h
  * @author  Mo'men Elhoseiny
  * @brief   Control System Block declarations
  * @Date    Created on July 26, 2023
  ******************************************************************************
  */
#ifndef CORTEXM3_CORTEXM3_CORE_SCB_H_
#define CORTEXM3_CORTEXM3_CORE_SCB_H_

/*=================================*/
  /*
   *  Includes section
   */
		#include <Common/Std_Types.h>
		#include "Register_Definition/Register_Definition.h"
/*=================================*/
#ifndef __STM32F103xB_H
/*******************************************************************************
 *                         	   Macro Declaration                               *
 *******************************************************************************/
/*Memory mapping of Core Hardware*/
#define SCB_BASE (0xE000ED00ul)    // System Control Block start address

#define SCB      ((SCB_Tybe*)SCB_BASE)

/*Cortex Preemtion priority groups*/
#define SCB_PRIORITY_GROUP_0 (0x00000007)/*0 - BITs for Group priority
 	 	 	 	 	 	 	 	 	       4 - BITs for Subgroup priority*/
#define SCB_PRIORITY_GROUP_1 (0x00000006)/*1 - BITs for Group priority
 	 	 	 	 	 	 	 	 	       3 - BITs for Subgroup priority*/
#define SCB_PRIORITY_GROUP_2 (0x00000005)/*2 - BITs for Group priority
 	 	 	 	 	 	 	 	 	       2 - BITs for Subgroup priority*/
#define SCB_PRIORITY_GROUP_3 (0x00000004)/*3 - BITs for Group priority
 	 	 	 	 	 	 	 	 	       1 - BITs for Subgroup priority*/
#define SCB_PRIORITY_GROUP_4 (0x00000003)/*4 - BITs for Group priority
 	 	 	 	 	 	 	 	 	       0 - BITs for Subgroup priority*/

#define SCB_AIRCR_PRI_GROUP (8u)   /*SCB AIRCR priority group position in register*/
#define SCB_AIRCR_VECTKEYSTAT (16u)  /*SCB AIRCR VECTKEYSTAT position in register*/
/*******************************************************************************/



/*******************************************************************************
 *                              Macro Functions                                *
 *******************************************************************************/



/*******************************************************************************/



/*******************************************************************************
 *                          User Defined Data Types                            *
 *******************************************************************************/
typedef struct{
	volatile uint32 CPUID;
	volatile uint32 ICSR;
	volatile uint32 VTOR;
	volatile uint32 AIRCR;
	volatile uint32 SCR;
	volatile uint32 CCR;
	volatile uint32 SHPR1;
	volatile uint32 SHPR2;
	volatile uint32 SHPR3;
	volatile uint32 SHCRS;
	volatile uint32 CFSR;
	volatile uint32 HFSR;
	volatile uint32 MMAR;
	volatile uint32 BFAR;
}SCB_Tybe;
/*******************************************************************************/


/*******************************************************************************
 *                            Function Prototypes                              *
 *******************************************************************************/

/*
 *@brief 	    : Set priority grouping
 *@Description  : Sets the priority grouping using the required unlock sequence
 *@Param PriorityGroup : Priority grouping field
 */
void SCB_SetPriorityGrouping(uint32 PriorityGroup);

/*
 *@brief 	    : get priority grouping
 *@Description  : returns the priority grouping
 *@return 		: Priority Grouping (SCB->AIRCR [10:8])
 */
uint32 SCB_GetPriorityGrouping(void);
/*******************************************************************************/
#endif
#endif /* CORTEXM3_CORTEXM3_CORE_SCB_H_ */
