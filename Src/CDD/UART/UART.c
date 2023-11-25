  /*
  ******************************************************************************
  * @file    UART.c
  * @author  Mo'men Elhoseiny
  * @brief   Source file for STM32F103C8T6 USART Driver.
  * @Date    Created on July 26, 2023
  ******************************************************************************
  */

/*=================================*/
  /*
   *  Includes section
   */
		#include "../../../Inc/CDD/UART/UART.h"
		#include "Common/Common_Macros.h"
/*=================================*/

/*******************************************************************************
 *                        Static Function Declarations                         *
 *******************************************************************************/
/*
 * @Brief : Function Uses BaudRate Equation to set prescaler in baud register
 * @Parameter UARTx : Pointer to UART TypeDef Indicating which UART Is Used
 * @Parameter clk   : UART Peripheral Clock
 * @Parameter Baud  : Required Baud Rate
 */
static inline void UART_set_baudrate(USART_TypeDef *UARTx,uint32_t clk,uint32 Baud);
/*
 * @Brief : Function Enables the selected UART Module
 * @Parameter UARTx : Pointer to UART TypeDef Indicating which UART Is Used
 */
static inline void UART_Enable(USART_TypeDef *UARTx);
/*
 * @Brief : Function Disables the selected UART Module
 * @Parameter UARTx : Pointer to UART TypeDef Indicating which UART Is Used
 */
static inline void UART_Disable(USART_TypeDef *UARTx);
/*******************************************************************************
 *                            Function Definitions                             *
 *******************************************************************************/
/*
 * @Brief : Initializes UART Module.
 * @Parameter Pointer to UART Configuration type.
 * @Return
 * 			E_OK 	: Function excuted succesfully
 * 			E_NOT_OK: Function failed to excute.
 */
Std_ReturnType UART_Init(UART_Cfg_t * UART_Cfg){
	Std_ReturnType Ret = E_OK;
	USART_TypeDef *UARTx;
	if(NULL_PTR == UART_Cfg){
		Ret = E_NOT_OK;
	}
	else{
		switch(UART_Cfg->UART_Select){
		case UART_1_SELCTED:
			UARTx = USART1;
			/*Enable clock access to UART_Module*/
			RCC_APB2ENR_USART1_CLK_EN();
			/*Set desired BAUD Rate*/
			UART_set_baudrate(UARTx,APB2CLK,UART_Cfg->BaudRate);
			break;
		case UART_2_SELCTED:
			UARTx = USART2;
			/*Enable clock access to UART_Module*/
			RCC_APB1ENR_USART2_CLK_EN();
			/*Set desired BAUD Rate*/
			UART_set_baudrate(UARTx,APB1CLK,UART_Cfg->BaudRate);

			break;
		case UART_3_SELCTED:
			UARTx = USART3;
			/*Enable clock access to UART_Module*/
			RCC_APB1ENR_USART3_CLK_EN();
			/*Set desired BAUD Rate*/
			UART_set_baudrate(UARTx,APB1CLK,UART_Cfg->BaudRate);

			break;
		default:
			/*Out Of Range*/
			Ret = E_NOT_OK;
			break;
		}
		/*Disable UART Module*/
		UART_Disable(UARTx);
		/*Select Word Length*/
		WRITE_BIT(UARTx->CR1,UART_WORD_SIZE_BIT,UART_Cfg->WordLength);
		/*Select Parity Bits*/
		if(UART_NO_PARITY != UART_Cfg->Parity){
			SET_BIT(UARTx->CR1,UART_PARITY_CONTROL_EN_BIT);
			WRITE_BIT(UARTx->CR1,UART_PARITY_SELECT_BIT,UART_Cfg->Parity);
		}
		else{
			/*Disable Parity*/
			CLEAR_BIT(UARTx->CR1,UART_PARITY_CONTROL_EN_BIT);
		}
		/*Select Stop Bits*/
			UARTx->CR2 |= (UART_STOP_BITS_POS << ((UART_Cfg->Stob_Bits)&&(UART_MODE_BITS_MASK)));
		/*Select Mode*/
			UARTx->CR1 |= (UART_MODE_BITS_POS << ((UART_Cfg->Mode)&&UART_STOP_BITS_MASK));
		/*Select Flow Control Mode*/
			UARTx->CR1 |= (UART_FLOW_CTRL_BITS_POS<<((UART_Cfg->HW_Flow_Control)&&UART_FLOW_CTRL_MASK));
		/*Enable UART Module*/
		UART_Enable(UARTx);

	}
	return Ret;
}

/*
 * @Brief : De-initializes UART Module.
 * @Parameter Pointer to UART Configuration type.
 * @Return
 * 			E_OK 	: Function excuted succesfully
 * 			E_NOT_OK: Function failed to excute.
 */
Std_ReturnType UART_Deinit(UART_Cfg_t * UART_Cfg){
	Std_ReturnType Ret = E_OK;
	USART_TypeDef *UARTx;
	if(NULL_PTR == UART_Cfg){
		Ret = E_NOT_OK;
	}
	else{
		switch(UART_Cfg->UART_Select){
		case UART_1_SELCTED:UARTx = USART1;break;
		case UART_2_SELCTED:UARTx = USART2;break;
		case UART_3_SELCTED:UARTx = USART3;break;
		default:
			/*Out Of Range*/
			Ret = E_NOT_OK;
			break;
		/*Disable UART Module*/
		UART_Disable(UARTx);
		}
	}
	return Ret;
}

/*
 * @Brief : Reads one 8 bit char from UART Module
 * @Parameter Pointer to UART Configuration type.
 * @Parameter Pointer to Data to return received data in.
 * @Return
 * 			E_OK 	: Function excuted succesfully
 * 			E_NOT_OK: Function failed to excute.
 */
Std_ReturnType UART_Read_Char(UART_Cfg_t * UART_Cfg, uint8 *Data){
	Std_ReturnType Ret = E_OK;
	USART_TypeDef *UARTx;
	if((NULL_PTR == UART_Cfg)||(NULL_PTR == Data)||(UART_MODE_RX == UART_Cfg->Mode)){
		Ret = E_NOT_OK;
	}
	else{
		switch(UART_Cfg->UART_Select){
		case UART_1_SELCTED:UARTx = USART1;break;
		case UART_2_SELCTED:UARTx = USART2;break;
		case UART_3_SELCTED:UARTx = USART3;break;
		default:
			/*Out Of Range*/
			Ret = E_NOT_OK;
			break;
		}
		/*Wait for receive flag*/
		while(!READ_BIT(UARTx->SR,RXNE_UART));
		/*Read received data*/
		*Data = UARTx->DR;
	}
	return Ret;
}
/*
 * @Brief : Writes one 8 bit char using UART Module
 * @Parameter Pointer to UART Configuration type.
 * @Parameter Data to send on UART
 * @Return
 * 			E_OK 	: Function excuted succesfully
 * 			E_NOT_OK: Function failed to excute.
 */
Std_ReturnType UART_Write_Char(UART_Cfg_t * UART_Cfg, uint8 Data){
	Std_ReturnType Ret = E_OK;
	USART_TypeDef *UARTx;
	if((NULL_PTR == UART_Cfg)||(UART_MODE_RX == UART_Cfg->Mode)){
		Ret = E_NOT_OK;
	}
	else{
		switch(UART_Cfg->UART_Select){
		case UART_1_SELCTED:UARTx = USART1;break;
		case UART_2_SELCTED:UARTx = USART2;break;
		case UART_3_SELCTED:UARTx = USART3;break;
		default:
			/*Out Of Range*/
			Ret = E_NOT_OK;
			break;
		}
		/*Wait for Transmission to finish*/
		while(!READ_BIT(UARTx->SR,TXE_UART));
		/*Load Data Register with Transmitted Data*/
		UARTx->DR= Data;

	}
	return Ret;
}
/*
 * @Brief : Transmits data on the UART Module
 * @Parameter Pointer to UART Configuration type.
 * @Parameter Pointer to Data to send on UART
 * @Parameter Length of Data sent on UART
 * @Return
 * 			E_OK 	: Function excuted succesfully
 * 			E_NOT_OK: Function failed to excute.
 */
Std_ReturnType UART_Transmit(UART_Cfg_t *UART_Cfg, uint8 *Data,uint16 Length){
	Std_ReturnType Ret = E_OK;
	uint16_least Counter = 0;
	if((NULL_PTR == UART_Cfg)||(NULL_PTR == Data)||(UART_MODE_RX == UART_Cfg->Mode)){
		Ret = E_NOT_OK;
	}
	else{
		for(Counter = 0 ; Counter < Length ; Counter++){
			Ret &= UART_Write_Char(UART_Cfg,Data[Counter]);
		}
	}
	return Ret;
}
/*
 * @Brief : Receives data on the UART Module
 * @Parameter Pointer to UART Configuration type.
 * @Parameter Pointer to Data to Receive on UART
 * @Parameter Length of Data Receive on UART
 * @Return
 * 			E_OK 	: Function excuted succesfully
 * 			E_NOT_OK: Function failed to excute.
 */
Std_ReturnType UART_Receive(UART_Cfg_t *UART_Cfg, uint8 *Data,uint16 Length){
	Std_ReturnType Ret = E_OK;
	uint16_least Counter = 0;
	if((NULL_PTR == UART_Cfg)||(NULL_PTR == Data)||(UART_MODE_TX == UART_Cfg->Mode)){
		Ret = E_NOT_OK;
	}
	else{
		for(Counter = 0 ; Counter < Length ; Counter++){
			Ret &= UART_Read_Char(UART_Cfg,&Data[Counter]);
		}
	}
	return Ret;
}


/*
 * @Brief     : Function uses the UART_Transmit API To send data.
 * @Note  	  : This function is a multi-variatic function which takes multible inputs
 * @Parameter Pointer to UART Configuration type.
 * @Parameter Pointer to charachter string to send.
 */
Std_ReturnType UART_Print_Message(UART_Cfg_t *UART_Cfg,char * Format, ...){
	Std_ReturnType Ret = E_OK;;
	char Message[100]={0};
	va_list args;
	/*Enable access to variable arguments*/
	va_start(args,Format);
	/*Write formatted data to string*/
	vsprintf(Message,Format,args);
	/*Transmit Formated data through UART*/
	Ret = UART_Transmit(UART_Cfg,(uint8_t*)Message,sizeof(Message));
	/*Clean object initialized by va_start*/
	va_end(args);
	return Ret;
}
/*******************************************************************************/


/*******************************************************************************
 *                        Static Function Definitions                          *
 *******************************************************************************/
/*
 * @Brief : Function Uses BaudRate Equation to set prescaler in baud register
 * @Parameter UARTx : Pointer to UART TypeDef Indicating which UART Is Used
 * @Parameter clk   : UART Peripheral Clock
 * @Parameter Baud  : Required Baud Rate
 */
static inline void UART_set_baudrate(USART_TypeDef *UARTx,uint32_t clk,uint32 Baud){
	UARTx->BRR = ((clk)+(Baud/(2U)))/(Baud);
}
/*
 * @Brief : Function Enables the selected UART Module
 * @Parameter UARTx : Pointer to UART TypeDef Indicating which UART Is Used
 */
static inline void UART_Enable(USART_TypeDef *UARTx){
	SET_BIT(UARTx->CR1,UART_EN_BIT);
}
/*
 * @Brief : Function Disables the selected UART Module
 * @Parameter UARTx : Pointer to UART TypeDef Indicating which UART Is Used
 */
static inline void UART_Disable(USART_TypeDef *UARTx){
	CLEAR_BIT(UARTx->CR1,UART_EN_BIT);
}
/*******************************************************************************/
