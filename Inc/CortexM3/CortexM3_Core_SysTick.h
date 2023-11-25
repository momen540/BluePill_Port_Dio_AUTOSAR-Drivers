  /*
  ******************************************************************************
  * @file    CortexM3_Core_SysTick.h
  * @author  Mo'men Elhoseiny
  * @brief   Cortex M3 SystickTimer Declarations
  * @Date    Created on July 26, 2023
  ******************************************************************************
  */

#ifndef CORTEXM3_CORTEXM3_CORE_SYSTICK_H_
#define CORTEXM3_CORTEXM3_CORE_SYSTICK_H_


/*=================================*/
  /*
   *  Includes section
   */
		#include <Common/Std_Types.h>
		#include <Common/Common_Macros.h>
		#include <MCAL/RCC/RCC.h>
		#include "Register_Definition/Register_Definition.h"
/*=================================*/

/*******************************************************************************
 *                         	   Macro Declaration                               *
 *******************************************************************************/
#ifndef __STM32F103xB_H
#define SCS_BASE            (0xE000E000UL)                  /*!< System Control Space Base Address */
#define SysTick_BASE        (SCS_BASE +  0x0010UL)          /*!< SysTick Base Address */
#define SysTick             ((SysTick_Type*)SysTick_BASE)   /*!< SysTick configuration struct */

/* SysTick Control / Status Register Definitions */
#define SysTick_CTRL_COUNTFLAG_Pos         16U                                            /*!< SysTick CTRL: COUNTFLAG Position */
#define SysTick_CTRL_COUNTFLAG_Msk         (1UL << SysTick_CTRL_COUNTFLAG_Pos)            /*!< SysTick CTRL: COUNTFLAG Mask */

#define SysTick_CTRL_CLKSOURCE_Pos          2U                                            /*!< SysTick CTRL: CLKSOURCE Position */
#define SysTick_CTRL_CLKSOURCE_Msk         (1UL << SysTick_CTRL_CLKSOURCE_Pos)            /*!< SysTick CTRL: CLKSOURCE Mask */

#define SysTick_CTRL_TICKINT_Pos            1U                                            /*!< SysTick CTRL: TICKINT Position */
#define SysTick_CTRL_TICKINT_Msk           (1UL << SysTick_CTRL_TICKINT_Pos)              /*!< SysTick CTRL: TICKINT Mask */

#define SysTick_CTRL_ENABLE_Pos             0U                                            /*!< SysTick CTRL: ENABLE Position */
#define SysTick_CTRL_ENABLE_Msk            (1UL /*<< SysTick_CTRL_ENABLE_Pos*/)           /*!< SysTick CTRL: ENABLE Mask */

/* SysTick Reload Register Definitions */
#define SysTick_LOAD_RELOAD_Pos             0U                                            /*!< SysTick LOAD: RELOAD Position */
#define SysTick_LOAD_RELOAD_Msk            (0xFFFFFFUL /*<< SysTick_LOAD_RELOAD_Pos*/)    /*!< SysTick LOAD: RELOAD Mask */

/* SysTick Current Register Definitions */
#define SysTick_VAL_CURRENT_Pos             0U                                            /*!< SysTick VAL: CURRENT Position */
#define SysTick_VAL_CURRENT_Msk            (0xFFFFFFUL /*<< SysTick_VAL_CURRENT_Pos*/)    /*!< SysTick VAL: CURRENT Mask */

#endif
/*Systick clock selector*/
#define SYSTICK_EXTERNAL_CLK	 (0)
#define SYSTICK_PROCESSOR_CLK	 (1)

/*Systick Interval Mode*/
#define SYSTICK_SINGLE_INTERVAL_MODE   (0)
#define SYSTICK_PERIODIC_INTERVAL_MODE (1)
/*******************************************************************************/



/****************************************************************************************************
 *                                        Macro Functions                                          *
 ****************************************************************************************************/
#define SYSTICK_EN()			       (SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk)
#define SYSTICK_DISABLE()		       (SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk)

#define SYSTICK_CLK_SELECT(CLK)	   	   (WRITE_BIT(SysTick->CTRL,SysTick_CTRL_CLKSOURCE_Pos,CLK))

#define SYSTICK_INTERRUPT_EN()	       (SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk)
#define SYSTICK_INTERRUPT_DISABLE()	   (SysTick->CTRL &= ~SysTick_CTRL_COUNTFLAG_Msk)

#define SYSTICK_RELOAD(TICKS)		   (SysTick->LOAD) = (((uint32)TICKS) & (SysTick_VAL_CURRENT_Msk))
#define SYSTICK_RESET_VAL()			   (SysTick->VAL = 0)

#define SYSTICK_FLAG_CHECK()			(!((SysTick->CTRL) & (1<<SysTick_CTRL_COUNTFLAG_Pos)))
/*****************************************************************************************************/



/*******************************************************************************
 *                          User Defined Data Types                            *
 *******************************************************************************/
#ifndef __STM32F103xB_H
/**
  \brief  Structure type to access the System Timer (SysTick).
 */
typedef struct
{
  volatile uint32 CTRL;                   /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
  volatile uint32 LOAD;                   /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register */
  volatile uint32 VAL;                    /*!< Offset: 0x008 (R/W)  SysTick Current Value Register */
  volatile uint32 CALIB;                  /*!< Offset: 0x00C (R/ )  SysTick Calibration Register */
} SysTick_Type;
#endif

typedef struct
{
	uint32 Ticks;
	uint8 Systick_ClkSource:1;
	uint8 Systick_Interrupt_State:1;
}Systick_cfg_t;

/*
 * @ Brief :	Desctibes Function pointer
 */
typedef void (*PtrFunction)(void);

/*******************************************************************************/


/*******************************************************************************
 *                            Function Prototypes                              *
 *******************************************************************************/
/*
 * @Brief      : Initializes SysTickClock
 * @Description: Sets initial systick ticks and clock source
 * @Parameter Ticks : Initial systick ticks
 * @Parameter Systick_ClkSource : Systick clock source :
 * 							SYSTICK_EXTERNAL_CLK : processor clock / 8.
 * 							SYSTICK_PERIODIC_INTERVAL_MODE : processor clock.
 * @Return Std_ReturnType : Returns error status of the function
 * 							ret = E_OK     : Function excuted succesfully.
 * 							ret = E_NOT_OK : Error occured during ecxution.
 */
Std_ReturnType SysTick_Init(uint32 Ticks,uint8 Systick_ClkSource);
/*
 * @Brief      : Disables SysTickClock
 * @Description: resets SysTickClock and it's counter registers
 */
void SystTick_Deinit(void);
/*
 * @Brief      : wait for SysTick to count .
 * @Description: SysTick to count up to reload register .
 * @Parameter Ticks :systick ticks to count up to .
 * @Note : this function is blocking .
 */
void SysTick_WaitBlocking(uint32 Ticks);
/*
 * @Brief      : Single Interval SysTick task.
 * @Description: SysTick ticks and then excutes a task once
 * @Parameter Ticks   : tick to wait for interrupt.
 * @Parameter CallBack: Required task to excute once.
 * @Return Std_ReturnType : Returns error status of the function
 * 							ret = E_OK     : Function excuted succesfully.
 * 							ret = E_NOT_OK : Error occured during ecxution.
 */
Std_ReturnType Systick_SingleInterval(uint32 Ticks,PtrFunction CallBack);
/*
 * @Brief      : Periodic SysTick task.
 * @Description: SysTick ticks and then excutes periodically
 * @Parameter Ticks   : ticks to wait for interrupt.
 * @Parameter CallBack: Required task to excute periodically.
 * @Return Std_ReturnType : Returns error status of the function
 * 							ret = E_OK     : Function excuted succesfully.
 * 							ret = E_NOT_OK : Error occured during ecxution.
 */
Std_ReturnType Systick_PeriodicInterval(uint32 Ticks,PtrFunction CallBack);
/*
 * @Brief      : Reads value of val register.
 * @Description: Returns value of val register indicating how much ticks are remaining.
 * @return Ticks : systick ticks remaining to count
 */
uint32 SysTick_ReadTicks(void);
/*
 * @Brief      : Reads value of val register.
 * @Description: Returns value of val register.
 * @return Ticks : systick ticks that have been counted.
 */
uint32 SysTick_ReadElapsedTicks(void);
/*
 * @Brief      : Delays time in Milliseconds.
 * @Description: Delays time in Milliseconds.
 * @Parameter delay : Amount of time in Milliseconds to be delayed.
 * @Note : this function is blocking .
 */
void SysTick_delay_ms(uint32 delay);
/*
 * @Brief      : Delays time in Micro Seconds.
 * @Description: Delays time in Micro Seconds.
 * @Parameter delay : Amount of time in Micro Seconds to be delayed.
 * @Note : this function is blocking .
 */
void SysTick_delay_us(uint32 delay);

/*******************************************************************************/


#endif /* CORTEXM3_CORTEXM3_CORE_SYSTICK_H_ */
