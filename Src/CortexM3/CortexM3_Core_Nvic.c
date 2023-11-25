  /*
  ******************************************************************************
  * @file    CortexM3_Core_Nvic.c
  * @author  Mo'men Elhoseiny
  * @brief
  * @Date    Created on July 26, 2023
  ******************************************************************************
  */

/*=====================================*/
  /*
   *  Includes section
   */
		#include <CortexM3/CortexM3_Core_Nvic.h>
/*=====================================*/
#ifndef __STM32F103xB_H

/**
  * @brief   Enable Interrupt
  * @details Enables a device specific interrupt in the NVIC interrupt controller.
  * @param [in]      IRQn  Device specific interrupt number.
  * @note    IRQn must not be negative.
 */
void NVIC_EnableIRQ(IRQn_Type IRQn)
{
	if((uint32)IRQn >= 0)
	{
		NVIC->ISER[((uint32)IRQn/32)] = (1ul<<((uint32)IRQn & 0x1F));
	}
	else{/*Nothing*/}
}




/**
  * @brief   Disable Interrupt
  * @details Disables a device specific interrupt in the NVIC interrupt controller.
  * @param [in]      IRQn  Device specific interrupt number.
  * @note    IRQn must not be negative.
 */
void NVIC_DisableIRQ(IRQn_Type IRQn)
{
	if((uint32)IRQn >= 0)
	{
		NVIC->ICER[((uint32)IRQn/32)] = (1ul<<((uint32)IRQn & 0x1F));
	}
	else{/*Nothing*/}
}



/**
  * @brief   Set Pending Interrupt
  * @details Sets the pending bit of a device specific interrupt in the NVIC pending register.
  * @param [in]      IRQn  Device specific interrupt number.
  * @note    IRQn must not be negative.
 */
void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
	if((uint32)IRQn >= 0)
	{
		NVIC->ISPR[((uint32)IRQn/32)] = (1ul<<((uint32)IRQn & 0x1F));
	}
	else{/*Nothing*/}
}




/**
  * @brief   clear Pending Interrupt
  * @details Clears the pending bit of a device specific interrupt in the NVIC pending register.
  * @param [in]      IRQn  Device specific interrupt number.
  * @note    IRQn must not be negative.
 */
void NVIC_ClearPenindIRQ(IRQn_Type IRQn)
{
	if((uint32)IRQn >= 0)
	{
		NVIC->ICPR[((uint32)IRQn/32)] = (1ul<<((uint32)IRQn & 0x1F));
	}
	else{/*Nothing*/}
}


/**
  * @brief   Get Active Interrupt
  * @details Reads the active register in the NVIC and returns the active bit for the device specific interrupt.
  * @param [in]      IRQn  Device specific interrupt number.
  * @return             0  Interrupt status is not active.
  * @return             1  Interrupt status is active.
  * @note    IRQn must not be negative.
 */
uint32 NVIC_GetActive(IRQn_Type IRQn)
{
	if((uint32)IRQn >= 0)
	{
		return ((NVIC->IABR[((uint32)IRQn/32)] & (1ul<<((uint32)IRQn & 0x1F))) !=0 ? 1ul : 0ul );
	}
	else
	{
		return 0;
	}
}
/**
  * @brief   set interrupt priority
  * @details sets the priority of an external interrupt or exception
  * @param [in]      IRQn  Device specific interrupt number.
  * @param Priority  Interrupt priority.
  * @note    priority cannot be set for every processor exception.
 */
void NVIC_SetPriority(IRQn_Type IRQn,uint32 priority)
{
	if((uint32)IRQn >= 0)
	{
		NVIC->IP[(uint32)IRQn] = (uint8)(priority << (( 8 - NVIC_PRIO_BITS )&0xff) );
	}
	else
	{

	}
}
/**
  * @brief   Get interrupt priority
  * @details Reads the priority of an external interrupt or exception
  * @param [in]      IRQn  Device specific interrupt number.
  * @return          Interrupt priority
  * 				 Value is aligned automatically to the implemented priority bits.
 */
uint32 NVIC_GetPriority(IRQn_Type IRQn)
{
	if((uint32)IRQn >= 0)
	{
		return (NVIC->IP[(uint32)IRQn] >> ( 8 - NVIC_PRIO_BITS ));
	}
	else
	{

	}
	return 0;
}

#endif
