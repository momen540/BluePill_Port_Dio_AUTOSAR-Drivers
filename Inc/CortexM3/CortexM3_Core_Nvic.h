  /*
  ******************************************************************************
  * @file    CortexM3_Core_Nvic.h
  * @author  Mo'men Elhoseiny
  * @brief
  * @Date    Created on July 26, 2023
  ******************************************************************************
  */

#ifndef CORTEXM3_CORTEXM3_CORE_NVIC_H_
#define CORTEXM3_CORTEXM3_CORE_NVIC_H_


/*=================================*/
  /*
   *  Includes section
   */
		#include <Common/Std_Types.h>
		#include "Register_Definition/Register_Definition.h"
/*=================================*/

/*NVIC Definitions are in core m3 file*/
#ifndef __STM32F103xB_H

/*******************************************************************************
 *                         	   Macro Declaration                               *
 *******************************************************************************/
#define NVIC_BASE (0xE000E100ul)
#define NVIC      ((NVIC_Type*)NVIC_BASE)

#define NVIC_PRIO_BITS 4u //STM32F1xx uses 4 bits for priority
/*******************************************************************************/



/*******************************************************************************
 *                              Macro Functions                                *
 *******************************************************************************/



/*******************************************************************************/



/*******************************************************************************
 *                          User Defined Data Types                            *
 *******************************************************************************/
typedef struct{
	volatile uint32 ISER[8U];
	uint32 RESERVED0[24U];
	volatile uint32 ICER[8U];
	uint32 RESERVED1[24U];
	volatile uint32 ISPR[8U];
	uint32 RESERVED2[24U];
	volatile uint32 ICPR[8U];
	uint32 RESERVED3[24U];
	volatile uint32 IABR[8U];
	uint32 RESERVED4[56U];
	volatile uint8 IP[240U];
	uint32 RESERVED5[644U];
	volatile uint32 STIR;
}NVIC_Type;

typedef enum
{
/******  Cortex-M3 Processor Exceptions Numbers ***************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                             */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M3 Hard Fault Interrupt                     */
  MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M3 Memory Management Interrupt              */
  BusFault_IRQn               = -11,    /*!< 5 Cortex-M3 Bus Fault Interrupt                      */
  UsageFault_IRQn             = -10,    /*!< 6 Cortex-M3 Usage Fault Interrupt                    */
  SVCall_IRQn                 = -5,     /*!< 11 Cortex-M3 SV Call Interrupt                       */
  DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M3 Debug Monitor Interrupt                 */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M3 Pend SV Interrupt                       */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M3 System Tick Interrupt                   */

/******  STM32 specific Interrupt Numbers *********************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                            */
  PVD_IRQn                    = 1,      /*!< PVD through EXTI Line detection Interrupt            */
  TAMPER_IRQn                 = 2,      /*!< Tamper Interrupt                                     */
  RTC_IRQn                    = 3,      /*!< RTC global Interrupt                                 */
  FLASH_IRQn                  = 4,      /*!< FLASH global Interrupt                               */
  RCC_IRQn                    = 5,      /*!< RCC global Interrupt                                 */
  EXTI0_IRQn                  = 6,      /*!< EXTI Line0 Interrupt                                 */
  EXTI1_IRQn                  = 7,      /*!< EXTI Line1 Interrupt                                 */
  EXTI2_IRQn                  = 8,      /*!< EXTI Line2 Interrupt                                 */
  EXTI3_IRQn                  = 9,      /*!< EXTI Line3 Interrupt                                 */
  EXTI4_IRQn                  = 10,     /*!< EXTI Line4 Interrupt                                 */
  DMA1_Channel1_IRQn          = 11,     /*!< DMA1 Channel 1 global Interrupt                      */
  DMA1_Channel2_IRQn          = 12,     /*!< DMA1 Channel 2 global Interrupt                      */
  DMA1_Channel3_IRQn          = 13,     /*!< DMA1 Channel 3 global Interrupt                      */
  DMA1_Channel4_IRQn          = 14,     /*!< DMA1 Channel 4 global Interrupt                      */
  DMA1_Channel5_IRQn          = 15,     /*!< DMA1 Channel 5 global Interrupt                      */
  DMA1_Channel6_IRQn          = 16,     /*!< DMA1 Channel 6 global Interrupt                      */
  DMA1_Channel7_IRQn          = 17,     /*!< DMA1 Channel 7 global Interrupt                      */
  ADC1_2_IRQn                 = 18,     /*!< ADC1 and ADC2 global Interrupt                       */
  USB_HP_CAN1_TX_IRQn         = 19,     /*!< USB Device High Priority or CAN1 TX Interrupts       */
  USB_LP_CAN1_RX0_IRQn        = 20,     /*!< USB Device Low Priority or CAN1 RX0 Interrupts       */
  CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1 Interrupt                                   */
  CAN1_SCE_IRQn               = 22,     /*!< CAN1 SCE Interrupt                                   */
  EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                        */
  TIM1_BRK_IRQn               = 24,     /*!< TIM1 Break Interrupt                                 */
  TIM1_UP_IRQn                = 25,     /*!< TIM1 Update Interrupt                                */
  TIM1_TRG_COM_IRQn           = 26,     /*!< TIM1 Trigger and Commutation Interrupt               */
  TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                       */
  TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                */
  TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                */
  TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                */
  I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                 */
  I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                 */
  I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                 */
  I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                 */
  SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                */
  SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                */
  USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                              */
  USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                              */
  USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                              */
  EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                      */
  RTC_Alarm_IRQn              = 41,     /*!< RTC Alarm through EXTI Line Interrupt                */
  USBWakeUp_IRQn              = 42,     /*!< USB Device WakeUp from suspend through EXTI Line Interrupt */
} IRQn_Type;

/*******************************************************************************/


/*******************************************************************************
 *                            Function Prototypes                              *
 *******************************************************************************/

/**
  * @brief   Enable Interrupt
  * @details Enables a device specific interrupt in the NVIC interrupt controller.
  * @param [in]      IRQn  Device specific interrupt number.
  * @note    IRQn must not be negative.
 */
void NVIC_EnableIRQ(IRQn_Type IRQn);

/**
  * @brief   Disable Interrupt
  * @details Disables a device specific interrupt in the NVIC interrupt controller.
  * @param [in]      IRQn  Device specific interrupt number.
  * @note    IRQn must not be negative.
 */
void NVIC_DisableIRQ(IRQn_Type IRQn);
/**
  * @brief   Set Pending Interrupt
  * @details Sets the pending bit of a device specific interrupt in the NVIC pending register.
  * @param [in]      IRQn  Device specific interrupt number.
  * @note    IRQn must not be negative.
 */
void NVIC_SetPendingIRQ(IRQn_Type IRQn);
/**
  * @brief   clear Pending Interrupt
  * @details Clears the pending bit of a device specific interrupt in the NVIC pending register.
  * @param [in]      IRQn  Device specific interrupt number.
  * @note    IRQn must not be negative.
 */
void NVIC_ClearPenindIRQ(IRQn_Type IRQn);
/**
  * @brief   Get Active Interrupt
  * @details Reads the active register in the NVIC and returns the active bit for the device specific interrupt.
  * @param [in]      IRQn  Device specific interrupt number.
  * @return             0  Interrupt status is not active.
  * @return             1  Interrupt status is active.
  * @note    IRQn must not be negative.
 */
uint32 NVIC_GetActive(IRQn_Type IRQn);
/**
  * @brief   set interrupt priority
  * @details sets the priority of an external interrupt or exception
  * @param [in]      IRQn  Device specific interrupt number.
  * @param Priority  Interrupt priority.
  * @note    priority cannot be set for every processor exception.
 */
void NVIC_SetPriority(IRQn_Type IRQn,uint32 priority);
/**
  * @brief   Get interrupt priority
  * @details Reads the priority of an external interrupt or exception
  * @param [in]      IRQn  Device specific interrupt number.
  * @return          Interrupt priority
  * 				 Value is aligned automatically to the implemented priority bits.
 */
uint32 NVIC_GetPriority(IRQn_Type IRQn);

/*******************************************************************************/
#endif
#endif /* CORTEXM3_CORTEXM3_CORE_NVIC_H_ */
