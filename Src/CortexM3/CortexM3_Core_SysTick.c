  /*
  ******************************************************************************
  * @file    CortexM3_Core_SysTick.c
  * @author  Mo'men Elhoseiny
  * @brief   Cortex M3 SystickTimer Definitions
  * @Date    Created on July 26, 2023
  ******************************************************************************
  */

/*=================================*/
  /*
   *  Includes section
   */
		#include "../../Inc/CortexM3/CortexM3_Core_SysTick.h"
/*=================================*/

static PtrFunction SysTick_CallBack = NULL_PTR;
static volatile uint8 Systick_Mode = 0;
Std_ReturnType SysTick_Init(uint32 Ticks,uint8 Systick_ClkSource)
{
	Std_ReturnType RET=E_OK;
	/*Disable SysTick Counter*/
	SYSTICK_DISABLE();
	if(Ticks > SysTick_LOAD_RELOAD_Msk){
		RET=E_NOT_OK;
	}
	else{
		/*Set Reload Register to system ticks*/
		SYSTICK_RELOAD(Ticks);
	}
	/*Reset Counter value*/
	SYSTICK_RESET_VAL();
	/*Select Processor Clock*/
	if((SYSTICK_EXTERNAL_CLK == Systick_ClkSource)||(SYSTICK_PROCESSOR_CLK == Systick_ClkSource)){
		SYSTICK_CLK_SELECT(Systick_ClkSource);
	}
	else{
		RET = E_NOT_OK;
	}
	/*Disable Interrupt*/
	SYSTICK_INTERRUPT_DISABLE();
	return RET;
}
void SystTick_Deinit(void)
{
	/*Disable SysTick Counte*/
	SYSTICK_DISABLE();
	/*Reset Reload Register*/
	SYSTICK_RELOAD(0);
	/*Reset Counter Val*/
	SYSTICK_RESET_VAL();
	/*Systick Exception Disable*/
	SYSTICK_INTERRUPT_DISABLE();
}
void SysTick_WaitBlocking(uint32 Ticks)
{
	/*Reload SysTick Register */
	SYSTICK_RELOAD(Ticks);
	/*Enable Systic Timer*/
	SYSTICK_EN();
	/*Wait for counter flag to be 1*/
	while(SYSTICK_FLAG_CHECK());;
	/*Disable SysTick Counte*/
	SYSTICK_DISABLE();
	/*Reset Reload Register*/
	SYSTICK_RELOAD(0);
	/*Reset Counter Val*/
	SYSTICK_RESET_VAL();

}
Std_ReturnType Systick_SingleInterval(uint32 Ticks,PtrFunction CallBack)
{
	Std_ReturnType RET = E_OK;
	if(NULL_PTR == CallBack){
		/*Passing NULL Pointer*/
		RET = E_OK;
	}
	else{
		/* Set Reload Register to Ticks*/
		SYSTICK_RELOAD(Ticks);
		/*Copy user call back to Local PtrFunction*/
		SysTick_CallBack = CallBack;
		/*Set Timer to single interval mode*/
		Systick_Mode = SYSTICK_SINGLE_INTERVAL_MODE;
		/*Enable Interrupt*/
		SYSTICK_INTERRUPT_EN();

		/*Set Systick priority*/

		/*Enable Systic Timer*/
		SYSTICK_EN();
	}
	return RET;
}
Std_ReturnType Systick_PeriodicInterval(uint32 Ticks,PtrFunction CallBack)
{
	Std_ReturnType RET = E_OK;
	if(NULL_PTR == CallBack){
		/*Passing NULL Pointer*/
		RET = E_OK;
	}
	else{
		/* Set Reload Register to Ticks*/
		SYSTICK_RELOAD(Ticks);
		/*Copy user call back to Local PtrFunction*/
		SysTick_CallBack = CallBack;
		/*Set Timer to single interval mode*/
		Systick_Mode = SYSTICK_PERIODIC_INTERVAL_MODE;
		/*Enable Interrupt*/
		SYSTICK_INTERRUPT_EN();

		/*Set Systick priority*/

		/*Enable Systic Timer*/
		SYSTICK_EN();
	}
	return RET;
}
uint32 SysTick_ReadTicks(void)
{
	return (SysTick->VAL & SysTick_VAL_CURRENT_Msk);
}

void SysTick_delay_ms(uint32 delay)
{
	 uint32 l_Ticks=0;
	 /*Calculate 1ms tick*/
	 l_Ticks=(SYSCLK/1000)-1;
	 if(SYSTICK_EXTERNAL_CLK == READ_BIT(SysTick->CTRL,SysTick_CTRL_CLKSOURCE_Pos))
	 {
		 l_Ticks/=8;
	 }
	 /*Reload SysTick Register */
	 SYSTICK_RELOAD(l_Ticks);
	 /*Reset Counter value*/
	 SYSTICK_RESET_VAL();
	 /*Enable Systic Timer*/
	 SYSTICK_EN();
	 for(uint32 Time_ctr=0; Time_ctr<delay; Time_ctr++)
	 {
		 while(SYSTICK_FLAG_CHECK());
	 }
     /*Disable SysTick Counte*/
     SYSTICK_DISABLE();
	 /*Reset Reload Register*/
 	 SYSTICK_RELOAD(0);
 	 /*Reset Counter Val*/
 	 SYSTICK_RESET_VAL();
}
void SysTick_delay_us(uint32 delay)
{
	 uint32 l_Ticks = 0;
	 /*Calculate 1ms tick*/
	 l_Ticks=(SYSCLK/(1000000ul))-1;
	 if(SYSTICK_EXTERNAL_CLK == READ_BIT(SysTick->CTRL,SysTick_CTRL_CLKSOURCE_Pos))
	 {
		 l_Ticks/=8;
	 }
	 /*Reload SysTick Register */
	 SYSTICK_RELOAD(l_Ticks);
	 /*Reset Counter value*/
	 SYSTICK_RESET_VAL();
	 /*Enable Systic Timer*/
	 SYSTICK_EN();
	 for(uint32 Time_ctr=0; Time_ctr < delay; Time_ctr++)
	 {
		 while(SYSTICK_FLAG_CHECK());;
	 }
     /*Disable SysTick Counte*/
     SYSTICK_DISABLE();
	 /*Reset Reload Register*/
 	 SYSTICK_RELOAD(0);
 	 /*Reset Counter Val*/
 	 SYSTICK_RESET_VAL();
}



void SysTick_Handler(void){
	if(SysTick_CallBack){
		SysTick_CallBack();
	}
	if(SYSTICK_SINGLE_INTERVAL_MODE ==Systick_Mode ){
		SystTick_Deinit();
	}
	else{
		/* Do Nothing */
	}
}
