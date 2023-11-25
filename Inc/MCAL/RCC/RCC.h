  /*
  ******************************************************************************
  * @file    RCC.h
  * @author  Mo'men Elhoseiny
  * @brief   RCC Declarations
  * @Date    Created on July 26, 2023
  ******************************************************************************
  */

#ifndef MCAL_RCC_RCC_H_
#define MCAL_RCC_RCC_H_

/*=================================*/
  /*
   *  Includes section
   */
		#include "Common/Std_Types.h"
		#include "Common/Common_Macros.h"
		#include "Register_Definition/Register_Definition.h"
/*=================================*/
extern volatile uint32 SYSCLK;
extern volatile uint32 APB1CLK;
extern volatile uint32 APB2CLK;
extern volatile uint32 AHBCLK;
/*******************************************************************************
 *                         	   Macro Declaration                               *
 *******************************************************************************/
#ifndef __STM32F103xB_H
#define PERIPH_BASE           0x40000000UL /*!< Peripheral base address in the alias region */
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x00020000UL)
#define RCC_BASE              (AHBPERIPH_BASE + 0x00001000UL)
#define RCC					  ((RCC_TypeDef *)RCC_BASE)

#define FLASH_R_BASE          (AHBPERIPH_BASE + 0x00002000UL) /*!< Flash registers base address */
#define FLASH                 ((FLASH_TypeDef *)FLASH_R_BASE)

#endif
/* Flash access control register */
#define PRFTBE 					   ((uint8)4)/*FLASH->ACR Prefetch buffer enable bit*/
#define LATENCY_BIT 			   ((uint8)0)/*FLASH->ACR[0:2] Latency BITS
 	 	 	 	 	 	 	 	 	 	 	  *@ref Flash Latency
 	 	 	 	 	 	 	 	 	 	 	  */
/*Flash Latency*/
#define FLASH_ZERO_WAIT_LATENCY      ((uint8)0) /*For SYSCLK upto 24MHZ*/
#define FLASH_ONE_WAIT_LATENCY       ((uint8)1) /*For 24MHZ < SYSCLK <=48MHZ */
#define FLASH_TWO_WAIT_LATENCY       ((uint8)2) /*For 48MHZ < SYSCLK <=72MHZ */

/*Input Clock*/
#define HSI_Osc					   (0)
#define HSE_Osc					   (1)
#define PLL_Osc	                   (2)

/*AHB-Prescaler*/
#define AHB_DIV1                   (0)                     /*!< SYSCLK not divided */
#define AHB_DIV2                   (8)                       /*!< SYSCLK divided by 2 */
#define AHB_DIV4                   (9)                        /*!< SYSCLK divided by 4 */
#define AHB_DIV8                   (10)                       /*!< SYSCLK divided by 8 */
#define AHB_DIV16                  (11)                       /*!< SYSCLK divided by 16 */
#define AHB_DIV64                  (12)                       /*!< SYSCLK divided by 64 */
#define AHB_DIV128                 (13)                       /*!< SYSCLK divided by 128 */
#define AHB_DIV256                 (14)                       /*!< SYSCLK divided by 256 */
#define AHB_DIV512                 (15)                       /*!< SYSCLK divided by 512 */

/*APB1 Prescaler*/
#define APB1_DIV1                  (0)                       /*!< HCLK not divided */
#define APB1_DIV2                  (4)                       /*!< HCLK divided by 2 */
#define APB1_DIV4                  (5)                       /*!< HCLK divided by 4 */
#define APB1_DIV8                  (6)                       /*!< HCLK divided by 8 */
#define APB1_DIV16                 (7)                       /*!< HCLK divided by 16 */

/*APB2 Prescaler */
#define APB2_DIV1                  (0)                       /*!< HCLK not divided */
#define APB2_DIV2                  (4)                       /*!< HCLK divided by 2 */
#define APB2_DIV4                  (5)                       /*!< HCLK divided by 4 */
#define APB2_DIV8                  (6)                       /*!< HCLK divided by 8 */
#define APB2_DIV16                 (7)                       /*!< HCLK divided by 16 */

/*PLL_state*/
#define PLL_HSI_2				   (0)					     /*PLL Input is InternalClock DIV 2*/
#define PLL_HSE  				   (1)					     /*PLL Input is ExternalClock*/
#define PLL_HSE_2	 			   (2)						 /*PLL Input is ExternalClock DIV 2*/


/*PLL Multiblier*/
#define PLL_MUL_4			       (2)						/*Multiplies PLL Input Clock by 4*/
#define PLL_MUL_5			       (3)						/*Multiplies PLL Input Clock by 5*/
#define PLL_MUL_6			       (4)						/*Multiplies PLL Input Clock by 6*/
#define PLL_MUL_7			       (5)						/*Multiplies PLL Input Clock by 7*/
#define PLL_MUL_8			       (6)						/*Multiplies PLL Input Clock by 8*/
#define PLL_MUL_9			       (7)						/*Multiplies PLL Input Clock by 9*/
#define PLL_MUL_6_5			       (13)						/*Multiplies PLL Input Clock by 6.5*/

/*CR Register pins*/
#define HSION			 ((uint8)0) //RCC->CR InternalHighSpeedOscillator enable bit
#define HSIRDY			 ((uint8)1) //RCC->CR InternalHighSpeedOscillator Wait for ready bit
#define HSEON			 ((uint8)16)//RCC->CR ExternalHighSpeedOscillator enable bit
#define HSERDY           ((uint8)17)//RCC->CR ExternalHighSpeedOscillator Wait for ready bit
#define CSSON			 ((uint8)19)
#define PLLON            ((uint8)24)//RCC->CR PLL Enable pin
#define PLLRDY			 ((uint8)25)//RCC->CR PLL Wait for ready bit

/*RCC_CFGR clock configure register definitions*/

#define SW				 ((uint8)0)//RCC->CFGR[0:1] select SYSCLK source
								   //@ref RCC_Oscillator_Type
#define SWS				 ((uint8)2)//RCC->CFGR[2:3] ReadOnly Set and cleared by hardware to indicate which clock source is used as system clock.
								   //@ref RCC_Oscillator_Type
#define HPRE		     ((uint8)4)//RCC->CFGR[4:7] AHB Division clock factor
								   //@ref AHB-Prescale
#define PPRE1            ((uint8)8)//RCC->CFGR[8:10] APB1 Division clock factor
								   //@ref APB1 Prescaler
						           // Caution: Software must configure these bits ensure that the frequency in this domain does not exceed 36 MHz.
#define PPRE2		    ((uint8)11)//RCC->CFGR[8:10] APB2 Division clock factor.
								   //@ref APB1 Prescaler

#define PLLSRC			((uint8)16)//RCC->CFGR Selects PLL entry Clock
								    //@ref PLL_state
#define PLLXTPRE        ((uint8)17)//RCC->CFGR Selects divisor for external clock PLL if
									//@ref PLL_state
#define PLLMUL          ((uint8)18)//RCC->CFGR[18:21] PLL Multiblier
								   //@ref PLL Multiblier
								   // Caution : The PLL output frequency must not exceed 72 MHz.



#define CRCEN			 ((uint8)6)//RCC->AHBENR CLOCK ENABLE FOR CRC UNIT

#define IOPAEN           ((uint8)2)//RCC->APB2ENR CLOCK ENABLE BIT FOR PORTA
#define IOPBEN           ((uint8)3)//RCC->APB2ENR CLOCK ENABLE BIT FOR PORTB
#define IOPCEN           ((uint8)4)//RCC->APB2ENR CLOCK ENABLE BIT FOR PORTC
#define IOPDEN           ((uint8)5)//RCC->APB2ENR CLOCK ENABLE BIT FOR PORTD
#define IOPEEN           ((uint8)6)//RCC->APB2ENR CLOCK ENABLE BIT FOR PORTE
#define ADC1EN           ((uint8)9)//RCC->APB2ENR CLOCK ENABLE BIT FOR ADC1
#define ADC2EN           ((uint8)10)//RCC->APB2ENR CLOCK ENABLE BIT FOR ADC2
#define TIM1EN			 ((uint8)11)//RCC->APB2ENR CLOCK ENABLE BIT FOR TIMER1
#define SPI1EN			 ((uint8)12)//RCC->APB2ENR CLOCK ENABLE BIT FOR SPI1
#define USART1EN	     ((uint8)14)//RCC->APB2ENR CLOCK ENABLE BIT FOR USART1

#define TIM2EN			 ((uint8)0)//RCC->APB1ENR CLOCK ENABLE BIT FOR TIMER2
#define TIM3EN			 ((uint8)1)//RCC->APB1ENR CLOCK ENABLE BIT FOR TIMER3
#define TIM4EN			 ((uint8)2)//RCC->APB1ENR CLOCK ENABLE BIT FOR TIMER4
#define TIM5EN			 ((uint8)3)//RCC->APB1ENR CLOCK ENABLE BIT FOR TIMER5
#define TIM6EN			 ((uint8)4)//RCC->APB1ENR CLOCK ENABLE BIT FOR TIMER6
#define TIM7EN			 ((uint8)5)//RCC->APB1ENR CLOCK ENABLE BIT FOR TIMER7
#define WWDGEN			 ((uint8)11)//RCC->APB1ENR CLOCK ENABLE BIT FOR Window watchdog clock
#define SPI2EN			 ((uint8)14)//RCC->APB1ENR CLOCK ENABLE BIT FOR SPI2
#define SPI3EN			 ((uint8)15)//RCC->APB1ENR CLOCK ENABLE BIT FOR SPI3
#define USART2EN	     ((uint8)17)//RCC->APB1ENR CLOCK ENABLE BIT FOR USART2
#define USART3EN	     ((uint8)18)//RCC->APB1ENR CLOCK ENABLE BIT FOR USART3
#define USART4EN	     ((uint8)19)//RCC->APB1ENR CLOCK ENABLE BIT FOR USART4
#define USART5EN	     ((uint8)20)//RCC->APB1ENR CLOCK ENABLE BIT FOR USART5
#define I2C1EN			 ((uint8)21)//RCC->APB1ENR CLOCK ENABLE BIT FOR I2C1
#define I2C2EN			 ((uint8)22)//RCC->APB2ENR CLOCK ENABLE BIT FOR I2C1
#define CAN1EN			 ((uint8)25)//RCC->APB1ENR CLOCK ENABLE BIT FOR CAN1
#define CAN2EN			 ((uint8)26)//RCC->APB2ENR CLOCK ENABLE BIT FOR CAN2
#define BKPEN			 ((uint8)27)//RCC->APB2ENR CLOCK ENABLE BIT FOR Backup interface clock enable
#define PWREN			 ((uint8)28)//RCC->APB1ENR CLOCK ENABLE BIT FOR Power interface clock enable
#define DACEN			 ((uint8)29)//RCC->APB2ENR CLOCK ENABLE BIT FOR DAC interface clock enable
/*******************************************************************************/

/*******************************************************************************
 *                              Macro Functions                                *
 *******************************************************************************/
/* ============ FLASH ACCESS CONTROL REG ============== */
#define FLASH_PREFETCH_BUFF_EN()  		    SET_BIT(FLASH->ACR,PRFTBE)
#define FLASH_SET_LATENCY(LATENCY)			MODIFY_REG(FLASH->ACR,(0xFFFFFFF7),LATENCY)

/* ============ AHB2ENR ============== */
#define RCC_AHBENR_CRC_CLK_EN()				SET_BIT(RCC->AHBENR,CRCEN)

/* ============ APB2ENR ============== */

#define RCC_APB2ENR_PORTA_CLK_EN()			SET_BIT(RCC->APB2ENR,IOPAEN)
#define RCC_APB2ENR_PORTB_CLK_EN()			SET_BIT(RCC->APB2ENR,IOPBEN)
#define RCC_APB2ENR_PORTC_CLK_EN()			SET_BIT(RCC->APB2ENR,IOPCEN)
#define RCC_APB2ENR_PORTD_CLK_EN()			SET_BIT(RCC->APB2ENR,IOPDEN)
#define RCC_APB2ENR_PORTE_CLK_EN()			SET_BIT(RCC->APB2ENR,IOPEEN)
#define RCC_APB2ENR_ADC1_CLK_EN()			SET_BIT(RCC->APB2ENR,ADC1EN)
#define RCC_APB2ENR_ADC2_CLK_EN()			SET_BIT(RCC->APB2ENR,ADC2EN)
#define RCC_APB2ENR_TIM1_CLK_EN()			SET_BIT(RCC->APB2ENR,TIM1EN)
#define RCC_APB2ENR_SPI1_CLK_EN()			SET_BIT(RCC->APB2ENR,SPI1EN)
#define RCC_APB2ENR_USART1_CLK_EN()		    SET_BIT(RCC->APB2ENR,USART1EN)

#define RCC_APB2ENR_PORTA_CLK_DISABLE()		CLEAR_BIT(RCC->APB2ENR,IOPAEN)
#define RCC_APB2ENR_PORTB_CLK_DISABLE()		CLEAR_BIT(RCC->APB2ENR,IOPBEN)
#define RCC_APB2ENR_PORTC_CLK_DISABLE()		CLEAR_BIT(RCC->APB2ENR,IOPCEN)
#define RCC_APB2ENR_PORTD_CLK_DISABLE()		CLEAR_BIT(RCC->APB2ENR,IOPDEN)
#define RCC_APB2ENR_PORTE_CLK_DISABLE()		CLEAR_BIT(RCC->APB2ENR,IOPEEN)
#define RCC_APB2ENR_ADC1_CLK_DISABLE()		CLEAR_BIT(RCC->APB2ENR,ADC1EN)
#define RCC_APB2ENR_ADC2_CLK_DISABLE()		CLEAR_BIT(RCC->APB2ENR,ADC2EN)
#define RCC_APB2ENR_TIM1_CLK_DISABLE()		CLEAR_BIT(RCC->APB2ENR,TIM1EN)
#define RCC_APB2ENR_SPI1_CLK_DISABLE()		CLEAR_BIT(RCC->APB2ENR,SPI1EN)
#define RCC_APB2ENR_USART1_CLK_DISABLE()	CLEAR_BIT(RCC->APB2ENR,USART1EN)

/* ============ APB1ENR ============== */


#define RCC_APB1ENR_TIM2_CLK_EN()			SET_BIT(RCC->APB1ENR,TIM2EN)
#define RCC_APB1ENR_TIM3_CLK_EN()			SET_BIT(RCC->APB1ENR,TIM3EN)
#define RCC_APB1ENR_TIM4_CLK_EN()			SET_BIT(RCC->APB1ENR,TIM4EN)
#define RCC_APB1ENR_TIM5_CLK_EN()			SET_BIT(RCC->APB1ENR,TIM5EN)
#define RCC_APB1ENR_TIM6_CLK_EN()			SET_BIT(RCC->APB1ENR,TIM6EN)
#define RCC_APB1ENR_TIM7_CLK_EN()			SET_BIT(RCC->APB1ENR,TIM7EN)
#define RCC_APB1ENR_WWDG_CLK_EN()			SET_BIT(RCC->APB1ENR,WWDGEN)
#define RCC_APB1ENR_SPI2_CLK_EN()			SET_BIT(RCC->APB1ENR,SPI2EN)
#define RCC_APB1ENR_SPI3_CLK_EN()			SET_BIT(RCC->APB1ENR,SPI3EN)
#define RCC_APB1ENR_USART2_CLK_EN()			SET_BIT(RCC->APB1ENR,USART2EN)
#define RCC_APB1ENR_USART3_CLK_EN()			SET_BIT(RCC->APB1ENR,USART3EN)
#define RCC_APB1ENR_USART4_CLK_EN()			SET_BIT(RCC->APB1ENR,USART4EN)
#define RCC_APB1ENR_USART5_CLK_EN()			SET_BIT(RCC->APB1ENR,USART5EN)
#define RCC_APB1ENR_I2C1_CLK_EN()			SET_BIT(RCC->APB1ENR,I2C1EN)
#define RCC_APB1ENR_I2C2_CLK_EN()			SET_BIT(RCC->APB1ENR,I2C2EN)
#define RCC_APB1ENR_CAN1_CLK_EN()			SET_BIT(RCC->APB1ENR,CAN1EN)
#define RCC_APB1ENR_CAN2_CLK_EN()			SET_BIT(RCC->APB1ENR,CAN2EN)
#define RCC_APB1ENR_BKP_CLK_EN()			SET_BIT(RCC->APB1ENR,BKPEN)
#define RCC_APB1ENR_PWR_CLK_EN()			SET_BIT(RCC->APB1ENR,PWREN)
#define RCC_APB1ENR_DAC_CLK_EN()			SET_BIT(RCC->APB1ENR,DACEN)

#define RCC_APB1ENR_TIM2_CLK_DISABLE()			CLEAR_BIT(RCC->APB1ENR,TIM2EN)
#define RCC_APB1ENR_TIM3_CLK_DISABLE()			CLEAR_BIT(RCC->APB1ENR,TIM3EN)
#define RCC_APB1ENR_TIM4_CLK_DISABLE()			CLEAR_BIT(RCC->APB1ENR,TIM4EN)
#define RCC_APB1ENR_TIM5_CLK_DISABLE()			CLEAR_BIT(RCC->APB1ENR,TIM5EN)
#define RCC_APB1ENR_TIM6_CLK_DISABLE()			CLEAR_BIT(RCC->APB1ENR,TIM6EN)
#define RCC_APB1ENR_TIM7_CLK_DISABLE()			CLEAR_BIT(RCC->APB1ENR,TIM7EN)
#define RCC_APB1ENR_WWDG_CLK_DISABLE()			CLEAR_BIT(RCC->APB1ENR,WWDGEN)
#define RCC_APB1ENR_SPI2_CLK_DISABLE()			CLEAR_BIT(RCC->APB1ENR,SPI2EN)
#define RCC_APB1ENR_SPI3_CLK_DISABLE()			CLEAR_BIT(RCC->APB1ENR,SPI3EN)
#define RCC_APB1ENR_USART2_CLK_DISABLE()		CLEAR_BIT(RCC->APB1ENR,USART2EN)
#define RCC_APB1ENR_USART3_CLK_DISABLE()		CLEAR_BIT(RCC->APB1ENR,USART3EN)
#define RCC_APB1ENR_USART4_CLK_DISABLE()		CLEAR_BIT(RCC->APB1ENR,USART4EN)
#define RCC_APB1ENR_USART5_CLK_DISABLE()		CLEAR_BIT(RCC->APB1ENR,USART5EN)
#define RCC_APB1ENR_I2C1_CLK_DISABLE()			CLEAR_BIT(RCC->APB1ENR,I2C1EN)
#define RCC_APB1ENR_I2C2_CLK_DISABLE()			CLEAR_BIT(RCC->APB1ENR,I2C2EN)
#define RCC_APB1ENR_CAN1_CLK_DISABLE()			CLEAR_BIT(RCC->APB1ENR,CAN1EN)
#define RCC_APB1ENR_CAN2_CLK_DISABLE()			CLEAR_BIT(RCC->APB1ENR,CAN2EN)
#define RCC_APB1ENR_BKP_CLK_DISABLE()			CLEAR_BIT(RCC->APB1ENR,BKPEN)
#define RCC_APB1ENR_PWR_CLK_DISABLE()			CLEAR_BIT(RCC->APB1ENR,PWREN)
#define RCC_APB1ENR_DAC_CLK_DISABLE()			CLEAR_BIT(RCC->APB1ENR,DACEN)
/*******************************************************************************/


/*******************************************************************************
 *                          User Defined Data Types                            *
 *******************************************************************************/
#ifndef __STM32F103xB_H
typedef struct
{
  volatile uint32 CR;
  volatile uint32 CFGR;
  volatile uint32 CIR;
  volatile uint32 APB2RSTR;
  volatile uint32 APB1RSTR;
  volatile uint32 AHBENR;
  volatile uint32 APB2ENR;
  volatile uint32 APB1ENR;
  volatile uint32 BDCR;
  volatile uint32 CSR;
} RCC_TypeDef;

typedef struct
{
  volatile uint32 ACR;
  volatile uint32 KEYR;
  volatile uint32 OPTKEYR;
  volatile uint32 SR;
  volatile uint32 CR;
  volatile uint32 AR;
  volatile uint32 RESERVED;
  volatile uint32 OBR;
  volatile uint32 WRPR;
} FLASH_TypeDef;

#endif

typedef struct{
	uint8 AHB_Prescaler :4;  /*Prescaler of the main processor bus
							  *@ref AHB-Prescaler
	 	 	 	 	 	 	  */

	uint8 PLL_Multiblier:4;  /*PLL Multiblier selection
							  *@ref PLL Multiblier
							  */

	uint8 APB2_Prescaler:3;  /*Prescaler of the main processor bus
							  *@ref APB2 Prescaler
	 	 	 	 	 	 	  */

	uint8 APB1_Prescaler:3;  /*Prescaler of the main processor bus
							  *@ref APB1 Prescaler
	 	 	 	 	 	 	  */

	uint8 OscillatorType:2;  /*Oscillator to be configured using @ref RCC_Oscillator_Type
						      *@REF Input Clock
						      */

	uint8 PLL_state:2;		 /*state of PLL If used
							  *@ref PLL_state
							  */
}Clock_cfg_t;
/*******************************************************************************/

/*******************************************************************************
 *                            Function Prototypes                              *
 *******************************************************************************/
/*
 * @Brief System_ClockInit
 * @Description initializes system clock using selected cfg data type
 * @Parameter Pointer to clock configurations
 * @Return
 * 		  E_OK : Function excuted successfully
 * 		  E_NOT_OK: Function encountered an error
 */
Std_ReturnType System_ClockInit(const Clock_cfg_t * Clock_cfg);
/**
  * @brief  	  Resets the RCC clock configuration to the default reset state.
  * @Description  The default reset state of the clock configuration is given below:
  *            	  - HSI ON and used as system clock source
  *               - HSE, PLL, PLL2 and PLL3 are OFF
  *               - AHB, APB1 and APB2 prescaler set to 1.
  *               - CSS and MCO1 OFF
  *               - All interrupts disabled
  *               - All flags are cleared
  * @note   This function does not modify the configuration of the
  *               - Peripheral clocks
  *               - LSI, LSE and RTC clocks
  * @retval HAL_StatusTypeDef
  */
Std_ReturnType System_ClockDeInit(void);
/*******************************************************************************/

/*******************************************************************************
 *                              Global Variables                               *
 *******************************************************************************/
extern const Clock_cfg_t SystemClkCfg;
/*******************************************************************************/
#endif /* MCAL_RCC_RCC_H_ */
