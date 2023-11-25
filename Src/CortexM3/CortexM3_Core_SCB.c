/*
  ******************************************************************************
  * @file    CortexM3_Core_SCB.c
  * @author  Mo'men Elhoseiny
  * @brief   Control System Block source file
  * @Date    Created on July 26, 2023
  ******************************************************************************
  */
/*=================================*/
  /*
   *  Includes section
   */
		#include <CortexM3/CortexM3_Core_SCB.h>
/*=================================*/
#ifndef __STM32F103xB_H
/*
 *@brief 	    : Set priority grouping
 *@Description  : Sets the priority grouping using the required unlock sequence
 *@Param PriorityGroup : Priority grouping field
 */
void SCB_SetPriorityGrouping(uint32 PriorityGroup)
{
	uint32 RegisterVal = 0;
	uint32 TempPriorityGroup = (PriorityGroup & ((uint32)0x07));
	RegisterVal = (SCB->AIRCR & 0x0000f8ff);
	RegisterVal |= (((uint32)0x5FA)<<SCB_AIRCR_VECTKEYSTAT)|(TempPriorityGroup << SCB_AIRCR_PRI_GROUP);
	SCB->AIRCR = RegisterVal;
}

/*
 *@brief 	    : get priority grouping
 *@Description  : returns the priority grouping
 *@return 		: Priority Grouping (SCB->AIRCR [10:8])
 */
uint32 SCB_GetPriorityGrouping(void)
{
	return ((SCB->AIRCR & (0x00000700))>>SCB_AIRCR_PRI_GROUP);
}
#endif
