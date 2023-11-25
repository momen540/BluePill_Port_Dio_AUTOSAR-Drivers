  /*
  ******************************************************************************
  * @file    main.c
  * @author  Mo'men Elhoseiny
  * @brief	 Main for AUTOSAR Mcal drivers test
  * @Date    Created on July 26, 2023
  ******************************************************************************
  */

/************************************************** start of include section *********************************************************/
#include "main.h"
/**************************************************   end of include section  *********************************************************/


/**************************************************      GLOBAL VARIABLES     *********************************************************/
void fun1(void);
Std_ReturnType SystemInit(void);
Std_ReturnType Return = E_OK;
/**************************************************  End of  GLOBAL VARIABLES  ********************************************************/


int main(void)
{
	/************Initialize used modules************/
	Return = SystemInit();
	Button_State ON_BOARD_LED_ButtonState = BUTTON_RESET;
	Button_State Green_LED_ButtonState = BUTTON_RESET;
	Button_State Blue_LED_ButtonState = BUTTON_RESET;
	Button_State Red_LED_ButtonState = BUTTON_RESET;
	Button_State Yellow_LED_ButtonState = BUTTON_RESET;
	/************************************************/
	while(1)
	{
		Return = Read_Button_Debounced_Blocking(ON_BOARD_LED_BUTTON,&ON_BOARD_LED_ButtonState);
		Return = Read_Button_Debounced_Blocking(GREEN_LED_BUTTON,&Green_LED_ButtonState);
		Return = Read_Button_Debounced_Blocking(BLUE_LED_BUTTON,&Blue_LED_ButtonState);
		Return = Read_Button_Debounced_Blocking(RED_LED_BUTTON,&Red_LED_ButtonState);
		Return = Read_Button_Debounced_Blocking(YELLOW_LED_BUTTON,&Yellow_LED_ButtonState);
		if(Green_LED_ButtonState == BUTTON_SET){
			Led_toggle(GREEN_LED);
			UART_Print_Message(&UART3_Cfg,"Green Button Pressed\n\r");
		}
		if(ON_BOARD_LED_ButtonState == BUTTON_SET){
			Led_toggle(ON_BOARD_LED);
			UART_Print_Message(&UART3_Cfg,"On Board Button Pressed\n\r");
		}
		if(BUTTON_SET == Blue_LED_ButtonState){
			Led_toggle(BLUE_LED);
			UART_Print_Message(&UART3_Cfg,"Blue Button Pressed\n\r");
		}
		if(BUTTON_SET == Red_LED_ButtonState){
			Led_toggle(RED_LED);
			UART_Print_Message(&UART3_Cfg,"Red Button Pressed\n\r");
		}
		if(BUTTON_SET == Yellow_LED_ButtonState){
			Led_toggle(YELLOW_LED);
			UART_Print_Message(&UART3_Cfg,"Yellow Button Pressed\n\r");
		}
	}
}

Std_ReturnType SystemInit(void){
	Std_ReturnType Ret = E_OK;
	Ret = System_ClockInit(&SystemClkCfg);
	Ret &= SysTick_Init(0,SYSTICK_EXTERNAL_CLK);
	Port_Init(&Port_Configuration);
	Ret &= UART_Init(&UART3_Cfg);
	return Ret;
}


