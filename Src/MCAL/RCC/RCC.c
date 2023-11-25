  /*
  ******************************************************************************
  * @file    RCC.c
  * @author  Mo'men Elhoseiny
  * @brief   RCC Definitions
  * @Date    Created on July 26, 2023
  ******************************************************************************
  */

/*=================================*/
  /*
   *  Includes section
   */
		#include "../../../Inc/MCAL/RCC/RCC.h"
/*=================================*/

/******************************************************************************
 * 								Clock_Values								  *
 ******************************************************************************/
volatile uint32 SYSCLK  = (72000000);
volatile uint32 APB1CLK	= (36000000);
volatile uint32 APB2CLK	= (72000000);
volatile uint32 AHBCLK	= (72000000);
/******************************************************************************/
/*******************************************************************************
 *                           Local Function Prototypes                         *
 *******************************************************************************/
/*
 * @Brief : Function Sets Prescaler of AHB and checks for correct values
 * @Parameter  Pres : Prescaler value
 * @Return
 * 		  E_OK : Function excuted successfully
 * 		  E_NOT_OK: Function encountered an error
 */
static inline Std_ReturnType AHB_SetPres(uint8 Pres);


/*
 * @Brief : Function Sets Prescaler of APB1 and checks for correct values
 * @Parameter  Pres : Prescaler value
 * @Return
 * 		  E_OK : Function excuted successfully
 * 		  E_NOT_OK: Function encountered an error
 */
static inline Std_ReturnType APB1_SetPres(uint8 Pres);


/*
 * @Brief : Function Sets Prescaler of APB2 and checks for correct values
 * @Parameter  Pres : Prescaler value
 * @Return
 * 		  E_OK : Function excuted successfully
 * 		  E_NOT_OK: Function encountered an error
 */
static inline Std_ReturnType APB2_SetPres(uint8 Pres);

/*
 * @Brief : Function sets all peripheral bus prescalers
 * @Parameter  Clock_cfg : Pointer to clock configuration
 * @Return
 * 		  E_OK : Function excuted successfully
 * 		  E_NOT_OK: Function encountered an error
 */
static Std_ReturnType Peripheral_CLK_Init(const Clock_cfg_t * Clock_cfg);

/*
 * @Brief : Function sets oscillator to Internal oscillator
 */
static inline void Set_Osc_HSI(void);


/*
 * @Brief : Function sets oscillator to External crystal oscillator
 */
static inline void Set_Osc_HSE(void);


/*
 * @Brief : Function initializes PLL Unit
 * @Pararmeter  Pointer to clock configuration
 * 		  E_OK : Function excuted successfully
 * 		  E_NOT_OK: Function encountered an error
 */
static Std_ReturnType PLL_Init(const Clock_cfg_t * Clock_cfg);
/******************************************************************************/

/*******************************************************************************
 *                            Function Definitions                             *
 *******************************************************************************/
/*
 * @Brief System_ClockInit
 * @Description initializes system clock using selected cfg data type
 * @Parameter Pointer to clock configurations
 * @Return
 * 		  E_OK : Function excuted successfully
 * 		  E_NOT_OK: Function encountered an error
 */
Std_ReturnType System_ClockInit(const Clock_cfg_t * Clock_cfg)
{
	Std_ReturnType RET = E_OK;
	if(NULL_PTR == Clock_cfg)
	{
		RET = E_NOT_OK;
	}
	else
	{
		RET = Peripheral_CLK_Init(Clock_cfg);
		if(HSI_Osc == Clock_cfg->OscillatorType){
			Set_Osc_HSI();
		}
		else if(HSE_Osc == Clock_cfg->OscillatorType){
			Set_Osc_HSE();
		}
		else if(PLL_Osc == Clock_cfg->OscillatorType){
			RET &= PLL_Init(Clock_cfg);
		}
		else{
			/*Wrong type of oscillator*/
			RET = E_NOT_OK;
		}
	}
	return RET;
}

/**
  * @brief  	  Resets the RCC clock configuration to the default reset state.
  * @Description  The default reset state of the clock configuration is given below:
  *            	  - HSI ON and used as system clock source
  *               - HSE, PLL, PLL2 and PLL3 are OFF
  *               - AHB, APB1 and APB2 prescaler set to 1.
  *               - CSS off
  *               - All interrupts disabled
  *               - All flags are cleared
  * @note   This function does not modify the configuration of the
  *               - Peripheral clocks
  *               - LSI, LSE and RTC clocks
  * @retval HAL_StatusTypeDef
  */
Std_ReturnType System_ClockDeInit(void){
	Std_ReturnType RET = E_OK;
	/*HSI ON and used as system clock source*/
	Set_Osc_HSI();
	/* Reset CFGR register */
	CLEAR_REG(RCC->CFGR);
	/* Wait till clock switch is ready */
	while (READ_BIT(RCC->CFGR, RCC_CFGR_SWS_Pos) != 0);
	return RET;
	/*Disable PLLON */
	/* Second step is to clear PLLON bit */
	 CLEAR_BIT(RCC->CR, PLLON);
	/* Wait till PLL is disabled */
	while (READ_BIT(RCC->CR, PLLRDY) != 0);
	/* Reset CFGR register */
	CLEAR_REG(RCC->CFGR);
	/* Reset HSEON & CSSON bits */
	CLEAR_BIT(RCC->CR, HSEON);
	CLEAR_BIT(RCC->CR,CSSON);
	/*Disable Clock Security*/
	CLEAR_BIT(RCC->CIR,RCC_CIR_CSSF_Pos);
	/* Wait till HSE is disabled */
	while (READ_BIT(RCC->CR, HSERDY) != 0);
	/*Set prescalers to 1*/
	AHB_SetPres(AHB_DIV1);
	APB1_SetPres(APB1_DIV1);
	APB2_SetPres(APB2_DIV1);
	/* Reset all CSR flags */
	SET_BIT(RCC->CSR, RCC_CSR_RMVF_Pos);
	/* Disable all interrupts */
	CLEAR_REG(RCC->CIR);

}
/******************************************************************************/

/*******************************************************************************
 *                          Local Function Definitions                         *
 *******************************************************************************/
/*
 * @Brief : Function Sets Prescaler of AHB and checks for correct values
 * @Parameter  Pres : Prescaler value
 * @Return
 * 		  E_OK : Function excuted successfully
 * 		  E_NOT_OK: Function encountered an error
 */
static inline Std_ReturnType AHB_SetPres(uint8 Pres){
	Std_ReturnType ret = E_OK;
	switch(Pres){
		case AHB_DIV1:
			RCC->CFGR |=(Pres << HPRE);
			AHBCLK = SYSCLK;
			break;
		case AHB_DIV2:
			RCC->CFGR |=(Pres << HPRE);
			AHBCLK = SYSCLK/2;
			break;
		case AHB_DIV4:
			RCC->CFGR |=(Pres << HPRE);
			AHBCLK = SYSCLK/4;
			break;
		case AHB_DIV8:
			RCC->CFGR |=(Pres << HPRE);
			AHBCLK = SYSCLK/8;
			break;
		case AHB_DIV16:
			RCC->CFGR |=(Pres << HPRE);
			AHBCLK = SYSCLK/16;
			break;
		case AHB_DIV64:
			RCC->CFGR |=(Pres << HPRE);
			AHBCLK = SYSCLK/64;
		case AHB_DIV128:
			RCC->CFGR |=(Pres << HPRE);
			AHBCLK = SYSCLK/128;
			break;
		case AHB_DIV256:
			RCC->CFGR |=(Pres << HPRE);
			AHBCLK = SYSCLK/256;
			break;
		case AHB_DIV512:
			RCC->CFGR |=(Pres << HPRE);
			AHBCLK = SYSCLK/512;
			break;
		default : ret = E_NOT_OK;break;
	}
	return ret;
}


/*
 * @Brief : Function Sets Prescaler of APB1 and checks for correct values
 * @Parameter  Pres : Prescaler value
 * @Return
 * 		  E_OK : Function excuted successfully
 * 		  E_NOT_OK: Function encountered an error
 */
static inline Std_ReturnType APB1_SetPres(uint8 Pres){
	Std_ReturnType ret = E_OK;
	switch(Pres){
		case APB1_DIV1:
			RCC->CFGR |=(Pres << PPRE1);
			APB1CLK = SYSCLK;
			break;
		case APB1_DIV2:
			RCC->CFGR |=(Pres << PPRE1);
			APB1CLK = SYSCLK/2;
			break;
		case APB1_DIV4:
			RCC->CFGR |=(Pres << PPRE1);
			APB1CLK = SYSCLK/4;
			break;
		case APB1_DIV8:
			RCC->CFGR |=(Pres << PPRE1);
			APB1CLK = SYSCLK/8;
			break;
		case APB1_DIV16:
			RCC->CFGR |=(Pres << PPRE1);
			APB1CLK = SYSCLK/16;
			break;
		default : ret = E_NOT_OK;break;
	}
	return ret;
}


/*
 * @Brief : Function Sets Prescaler of APB2 and checks for correct values
 * @Parameter  Pres : Prescaler value
 * @Return
 * 		  E_OK : Function excuted successfully
 * 		  E_NOT_OK: Function encountered an error
 */
static inline Std_ReturnType APB2_SetPres(uint8 Pres){
	Std_ReturnType ret = E_OK;
	switch(Pres){
			case APB2_DIV1:
				RCC->CFGR |=(Pres << PPRE2);
				APB2CLK = SYSCLK;
				break;
			case APB2_DIV2:
				RCC->CFGR |=(Pres << PPRE2);
				APB2CLK = SYSCLK/2;
				break;
			case APB2_DIV4:
				RCC->CFGR |=(Pres << PPRE2);
				APB2CLK = SYSCLK/4;
				break;
			case APB2_DIV8:
				RCC->CFGR |=(Pres << PPRE2);
				APB2CLK = SYSCLK/8;
				break;
			case APB2_DIV16:
				RCC->CFGR |=(Pres << PPRE2);
				APB2CLK = SYSCLK/16;
				break;
			default : ret = E_NOT_OK;break;
		}
	return ret;
}
/*
 * @Brief : Function sets oscillator to internal oscillator
 */
static inline void Set_Osc_HSI(void)
{
	SET_BIT(RCC->CR,HSION);
	while(!(RCC->CR & (1 << HSIRDY)));
	SYSCLK = 8000000;
}
/*
 * @Brief : Function sets oscillator to External crystal oscillator
 */
static inline void Set_Osc_HSE(void)
{
	SET_BIT(RCC->CR,HSEON);
	while(!(RCC->CR & (1 << HSERDY)));
	SYSCLK = 8000000;
}
/*
 * @Brief : Function initializes PLL Unit
 * @Pararmeter  Pointer to clock configuration
 * 		  E_OK : Function excuted successfully
 * 		  E_NOT_OK: Function encountered an error
 */
static Std_ReturnType PLL_Init(const Clock_cfg_t * Clock_cfg)
{
	Std_ReturnType RET = E_OK;
	uint8 MULT=0;
	uint8 dive=1;
	if(NULL_PTR == Clock_cfg)
	{
		RET =E_NOT_OK;
	}
	else{
			if((PLL_MUL_6_5 == Clock_cfg->PLL_Multiblier)||((Clock_cfg->PLL_Multiblier >= PLL_MUL_4)&&(Clock_cfg->PLL_Multiblier <= PLL_MUL_9))){
				if(PLL_MUL_6_5 == Clock_cfg->PLL_Multiblier){
					MULT=6;
					dive=2;
				}
				else{
					MULT = (Clock_cfg->PLL_Multiblier - 2);
				}
				RCC->CFGR |=(Clock_cfg->PLL_Multiblier << PLLMUL);
			}
			else{
				/*Wrong Multiblier*/
				RET = E_NOT_OK;
			}
			switch(Clock_cfg->PLL_state)
			{
			case PLL_HSI_2:
				Set_Osc_HSI();
				SYSCLK=8000000/2;
				break;
			case PLL_HSE:
				Set_Osc_HSE();
				SYSCLK=8000000;
				SET_BIT(RCC->CFGR,PLLSRC);
				CLEAR_BIT(RCC->CFGR,PLLXTPRE);
				break;
			case PLL_HSE_2:
				Set_Osc_HSE();
				SYSCLK=8000000/2;
				SET_BIT(RCC->CFGR,PLLSRC);
				SET_BIT(RCC->CFGR,PLLXTPRE);
			}
			SET_BIT(RCC->CR,PLLON);
			while(!(RCC->CR & (1 << PLLRDY)));
			RCC->CFGR|=(PLL_Osc << SW);
			while((RCC -> CFGR & RCC_CFGR_SWS_PLL) != RCC_CFGR_SWS_PLL);
			SYSCLK = SYSCLK * MULT/dive;
	}
	return RET;
}
/*
 * @Brief : Function sets all peripheral bus prescalers
 * @Parameter  Clock_cfg : Pointer to clock configuration
 * @Return
 * 		  E_OK : Function excuted successfully
 * 		  E_NOT_OK: Function encountered an error
 */
static Std_ReturnType Peripheral_CLK_Init(const Clock_cfg_t * Clock_cfg)
{
	Std_ReturnType RET = E_OK;
	RET = AHB_SetPres(Clock_cfg->AHB_Prescaler);
	RET &= APB2_SetPres(Clock_cfg->APB2_Prescaler);
	if(SYSCLK > 36000000ul){

		RET &= APB1_SetPres(Clock_cfg->APB1_Prescaler);
	}
	else{
		/*APB1 Peripherals must not exceed 36 MHZ*/
		RET &= APB1_SetPres(APB1_DIV2);
	}

	FLASH_PREFETCH_BUFF_EN();
	if(SYSCLK < 24000000ul){
		FLASH_SET_LATENCY(FLASH_ZERO_WAIT_LATENCY);
	}
	else if((SYSCLK >= 24000000ul)&&(SYSCLK < 48000000ul)){
		FLASH_SET_LATENCY(FLASH_ONE_WAIT_LATENCY);
	}
	else if(SYSCLK >= 48000000ul){
		FLASH_SET_LATENCY(FLASH_TWO_WAIT_LATENCY);
	}
	else{/*Do Nothing*/}
	return RET;
}
/******************************************************************************/
