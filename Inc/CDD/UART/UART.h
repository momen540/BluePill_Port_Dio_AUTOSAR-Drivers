  /*
  ******************************************************************************
  * @file    UART.h
  * @author  Mo'men Elhoseiny
  * @brief   Header file for STM32F103c8t6 Microcontroller - USART Driver
  * @Date    Created on July 26, 2023
  ******************************************************************************
  */
#ifndef UART_H
#define UART_H
/*=================================*/
  /*
   *  Includes section
   */
#include <stdarg.h>
#include <stdio.h>
#include <Common/Std_Types.h>
		#include "../../MCAL/RCC/RCC.h"

/*=================================*/


/*******************************************************************************
 *                         		    Macros                                     *
 *******************************************************************************/
/*CR1*/
#define UART_EN_BIT					(13)
#define UART_WORD_SIZE_BIT			(12)
#define UART_PARITY_CONTROL_EN_BIT	(10)
#define UART_PARITY_SELECT_BIT		(10)
#define TXEIE						(7) /*Transmit interrupt enable bit*/
#define RXNEIE						(6)	/*Receive interruo enable bit*/
#define UART_MODE_BITS_POS			(2)	/*UARTx->CR1 Bits [2:3]*/
#define UART_MODE_BITS_MASK			(0xFFF9)
/*CR2*/
#define UART_STOP_BITS_POS			(12) /*UARTx->CR2 Bits [12:13]*/
#define UART_STOP_BITS_MASK			(0xCFFF)
/*CR3*/
#define UART_FLOW_CTRL_BITS_POS		(8)	/*UART->CR3 Bits [8:9]*/
#define	UART_FLOW_CTRL_MASK			(0xFCFF)
/*SR*/
#define RXNE_UART					(5)/*Read data register empty flag*/
#define TXE_UART            		(7)/*Transmit data register empty flag*/
/*
 * @Brief 		: Selects UART_1
 * @Implements	: UART_Index Enumeration
 */
#define UART_1_SELCTED			((UART_Index)0)
/*
 * @Brief 		: Selects UART_2
 * @Implements	: UART_Index Enumeration
 */
#define UART_2_SELCTED			((UART_Index)1)
/*
 * @Brief 		: Selects UART_3
 * @Implements	: UART_Index Enumeration
 */
#define UART_3_SELCTED			((UART_Index)2)


/*
 * @Brief 		: UART 8 Bit word selected
 * @Implements	: UART_Word_Length Enumeration
 */

#define UART_8BIT				((UART_Word_Length)0)
/*
 * @Brief 		: UART 9 Bit word selected
 * @Implements	: UART_Word_Length Enumeration
 */
#define UART_9BIT				((UART_Word_Length)1)


/*
 * @Brief 		: No Parity Selected
 * @Implements	: UART_Parity Enumeration
 */
#define UART_NO_PARITY		    ((UART_Parity)2)
/*
 * @Brief 		: Even Parity Selected
 * @Implements	: UART_Parity Enumeration
 */
#define UART_EVEN_PARITY	    ((UART_Parity)0)
/*
 * @Brief 		: Odd Parity Selected
 * @Implements	: UART_Parity Enumeration
 */
#define UART_ODD_PARITY			((UART_Parity)1)


/*
 * @Brief 		: One Stop Bit
 * @Implements	: UART_Stop_Bits Enumeration
 */
#define UART_1_STOPBIT 			((UART_Stop_Bits)0)
/*
 * @Brief 		: Half Stop Bit
 * @Implements	: UART_Stop_Bits Enumeration
 */
#define UART_0_5_STOPBIT 		((UART_Stop_Bits)1)
/*
 * @Brief 		: Two Stop Bits
 * @Implements	: UART_Stop_Bits Enumeration
 */
#define UART_2_STOPBIT 			((UART_Stop_Bits)2)
/*
 * @Brief 		: One and a half Stop Bits
 * @Implements	: UART_Stop_Bits Enumeration
 */
#define UART_1_5_STOPBIT 		((UART_Stop_Bits)3)

/*
 * @Brief 		: Receive mode
 * @Implements  : UART_Mode Enumeration
 */
#define UART_MODE_RX			((UART_Mode)1)
/*
 * @Brief 		: Transmit mode
 * @Implements  : UART_Mode Enumeration
 */
#define UART_MODE_TX			((UART_Mode)2)
/*
 * @Brief 		: Full duplex Transmit Receive mode
 * @Implements  : UART_Mode Enumeration
 */
#define UART_MODE_RXTX			((UART_Mode)3)


/*
 * @Brief 		: No Hardware flow control
 * @Implements  : UART_Flow_Control Enumeration
 */
#define UART_HWCONTROL_NONE 	((UART_Flow_Control)0)
/*
 * @Brief 		: RTS flow control
 * @Implements  : UART_Flow_Control Enumeration
 */
#define UART_HWCONTROL_RTS		((UART_Flow_Control)1)
/*
 * @Brief 		: CTS flow control
 * @Implements  : UART_Flow_Control Enumeration
 */
#define UART_HWCONTROL_CTS		((UART_Flow_Control)2)
/*
 * @Brief 		: RTS & CTS flow control
 * @Implements  : UART_Flow_Control Enumeration
 */
#define UART_HWCONTROL_RTS_CTS	((UART_Flow_Control)3)

/*******************************************************************************/

/*******************************************************************************
 *                              Macro Functions                                *
 *******************************************************************************/

/*******************************************************************************/

/*******************************************************************************
 *                          User Defined Data Types                            *
 *******************************************************************************/
/*
 * @Brief : UART_Parity_selection
 */
typedef uint8 UART_Parity;


/*
 * @Brief : UART_Start_Bit_number
 */
typedef uint8 UART_Stop_Bits;


/*
 * @Brief : UART_Module_Select
 */
typedef uint8 UART_Index;


/*
 * @Brief : UART_Mode_Select
 */
typedef uint8 UART_Mode;


/*
 * @Brief : UART_Flow_Control Mode
 */
typedef uint8 UART_Flow_Control;

/*
 * @Brief : Selects UART_Word_Length
 */
typedef uint8 UART_Word_Length;


/*
 * @Brief : Struct used to initialize UART Module
 * BaudRate
 *
 *
 *
 *
 */
typedef struct{
	uint32   			BaudRate;				/*Selects UART Baud Rate
												 The baud rate is computed using the following formula:
												 IntegerDivider = ((PCLKx) / (16 * (huart->Init.BaudRate)))
												 FractionalDivider = ((IntegerDivider - ((uint32_t) IntegerDivider)) * 16) + 0.5
	 	 	 	 	 	 	 	 	 	 	 	 */

	UART_Word_Length	WordLength:1;			/*Selects UART Word Length 8 or 9 bits
												 @ref : UART_Word_Length
	 	 	 	 	 	 	 	 	 	 	 	 */

	UART_Index			UART_Select:2;			/*Selects UART Module 1,2,3
												 @ref : UART_Index
	 	 	 	 	 	 	 	 	 	 	 	 */

	UART_Parity     	Parity:2;			    /*Selects UART Module Even, Odd or disabled
												 @ref : UART_Parity
	 	 	 	 	 	 	 	 	 	 	 	 */

	UART_Stop_Bits  	Stob_Bits:2;		    /*Selects UART Module Stop Bits selection
											     @ref : UART_Stop_Bits
	 	 	 	 	 	 	 	 	 	  	     */

	UART_Mode			Mode:2;		            /*Selects UART Module Mode selection  RX,TX or full duplex
											     @ref : UART_Mode
	 	 	 	 	 	 	 	 	 	  	     */
	UART_Flow_Control	HW_Flow_Control:2;		/*Selects UART Module Mode Hardware Flow control
											     @ref : UART_Mode
	 	 	 	 	 	 	 	 	 	  	     */
}UART_Cfg_t;
/*******************************************************************************/

/*******************************************************************************
 *                            Function Prototypes                            *
 *******************************************************************************/
/*
 * @Brief : Initializes UART Module.
 * @Parameter Pointer to UART Configuration type.
 * @Return
 * 			E_OK 	: Function excuted succesfully
 * 			E_NOT_OK: Function failed to excute.
 */
Std_ReturnType UART_Init(UART_Cfg_t * UART_Cfg);


/*
 * @Brief : De-initializes UART Module.
 * @Parameter Pointer to UART Configuration type.
 * @Return
 * 			E_OK 	: Function excuted succesfully
 * 			E_NOT_OK: Function failed to excute.
 */
Std_ReturnType UART_Deinit(UART_Cfg_t * UART_Cfg);



/*
 * @Brief : Reads one 8 bit char from UART Module
 * @Parameter Pointer to UART Configuration type.
 * @Parameter Pointer to Data to return received data in.
 * @Return
 * 			E_OK 	: Function excuted succesfully
 * 			E_NOT_OK: Function failed to excute.
 */
Std_ReturnType UART_Read_Char(UART_Cfg_t * UART_Cfg, uint8 *Data);
/*
 * @Brief : Writes one 8 bit char using UART Module
 * @Parameter Pointer to UART Configuration type.
 * @Parameter Data to send on UART
 * @Return
 * 			E_OK 	: Function excuted succesfully
 * 			E_NOT_OK: Function failed to excute.
 */
Std_ReturnType UART_Write_Char(UART_Cfg_t * UART_Cfg, uint8 Data);
/*
 * @Brief : Transmits data on the UART Module
 * @Parameter Pointer to UART Configuration type.
 * @Parameter Pointer to Data to send on UART
 * @Parameter Length of Data sent on UART
 * @Return
 * 			E_OK 	: Function excuted succesfully
 * 			E_NOT_OK: Function failed to excute.
 */
Std_ReturnType UART_Transmit(UART_Cfg_t *UART_Cfg, uint8 *Data,uint16 Length);
/*
 * @Brief : Receives data on the UART Module
 * @Parameter Pointer to UART Configuration type.
 * @Parameter Pointer to Data to Receive on UART
 * @Parameter Length of Data Receive on UART
 * @Return
 * 			E_OK 	: Function excuted succesfully
 * 			E_NOT_OK: Function failed to excute.
 */
Std_ReturnType UART_Receive(UART_Cfg_t *UART_Cfg, uint8 *Data,uint16 Length);


/*
 * @Brief     : Function uses the UART_Transmit API To send data.
 * @Note  	  : This function is a multi-variatic function which takes multible inputs
 * @Parameter Pointer to UART Configuration type.
 * @Parameter Pointer to charachter string to send.
 */
Std_ReturnType UART_Print_Message(UART_Cfg_t *UART_Cfg,char * Format, ...);
/*******************************************************************************/

#endif /* UART_H */
