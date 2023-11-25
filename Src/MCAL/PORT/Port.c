  /*
  ******************************************************************************
  * @file    Port.c
  * @author  Mo'men Elhoseiny
  * @brief   Source file for STM32F103c8t6 Microcontroller - Port Driver
  * @Date    Created on July 26, 2023
  ******************************************************************************
  */
  /*===============================================================================
  *  Project			: AUTOSAR 4.4.0 MCAL
  *  Platform			: ARM
  *  Peripheral			: STM32F103c8t6
  *  Autosar vesion  	: 4.4.0
  *  Autosar Revesion	: ASR_REL_4_0_REV_0000
  *  SW Version			: 1.0.0
  *===============================================================================*/
/*=================================*/
  /*
   *  Includes section
   */
		#include "../../../Inc/MCAL/PORT/Port.h"
		#include "Register_Definition/Register_Definition.h"
		#include "../../../Inc/MCAL/RCC/RCC.h"
/*=================================*/
/*******************************************************************************
 *                           Local Function Prototypes                         *
 *******************************************************************************/
/*
 * @Brief 		: Static function used in Port_Init to lock pin state
 * @Descibtion  : The Function Locks PIN state if configured as unchangable
 * 				  after Initialization
 * @Sync/Async  : Synchronous.
 * @Reentrancy  : Reentrant.
 * @Parameter Port ID    : Port Index
 * @Parameter pin        : Channel Index.
 */
static void Pin_Lock_State(uint8 Port,uint8 Pin);


/*
 * @Brief 		: Static function used in Port_Init to set pin speed as configured
 * @Descibtion  : The Function sets pin speed either to :
 * 			 	  SPEED_MODE_INPUT : Input Mode
 * 			 	  SPEED_10_MHZ     : 10 MHZ Output Mode
 * 			 	  SPEED_2_MHZ      : 2  MHZ Output Mode
 * 			 	  SPEED_50_MHZ     : 50 MHZ Output Mode
 * @Sync/Async  : Synchronous.
 * @Reentrancy  : Reentrant.
 * @Parameter pointer to pin configuration.
 */
static void PORT_OUT_SPEED_SETTER(const Port_ConfigPins * PIN);


/*
 * @Brief 		: Static function used in Port_Init to set pin Mood as configured
 * @Descibtion  : The Function sets pin Mood either to :
 * 			 	  OUT_PUSH_PULL    : Output push pull configuration
 * 			 	  OUT_OPEN_DRAIN   : Output open drain configuration
 * 			 	  AF_PUSH_PULL     : Alternative function push pull configuration
 * 			 	  AF_OPEN_DRAIN    : Alternative function open drain configuration
 * 			 	  ANALOG_INPUT 	   : ANALOG INPUT for ADC Mode
 * 			 	  INPUT			   : Regular input mode which has three Internal resisto connections :
 * 			 	  Port_InternalResistor:
 * 			 	  			            Floating : Pin is floating no internal resistors
 * 			 	  	  	                Pull_UP  : Pin is pulled up using internal resistor
 * 			 	  		                Pull_DOWN: Pin is pulled Down using internal resistor
 * @Sync/Async  : Synchronous.
 * @Reentrancy  : Reentrant.
 * @Parameter pointer to pin configuration.
 */
static void PORT_OUT_MOOD_SETTER(const Port_ConfigPins * PIN);



/*
 * @Brief : Indication either or not the function Port_Init was called or not
 * @Implements : Type uint8
 * 				PORT_NOT_INITIALIZED : Function Port_Init was not called
 * 				and no other module can be used.
 * 				PORT_INITIALIZED	 : Function Port_Init was called and other
 * 				modules can be used
 */
static uint8 Port_Status = PORT_NOT_INITIALIZED;
/******************************************************************************/

/*******************************************************************************
 *                            Function Definitions                             *
 *******************************************************************************/
/*
 * @Name Port_Init
 * @Service ID : 0x00.
 * @Sync/Async : Synchronous.
 * @Reentrancy : Non Reentrant.
 * @Brief : Initializes the Port Driver module.
 * @Parameter ConfigPtr : Pointer to configuration set.
 * @return : no return.
 */
void Port_Init (
const Port_ConfigType* ConfigPtr
)
{
	if(NULL_PTR == ConfigPtr){
#if PORT_DEV_ERROR_DETECT == STD_ON
		/*APIs called with a Null Pointer Wrrong Parameters*/
		Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_INIT_ID,PORT_E_PARAM_CONFIG);
#endif
	}
	else
	{

		uint8_least l_pin_conuter=PORTA_PIN0;
		RCC_APB2ENR_PORTA_CLK_EN();
		RCC_APB2ENR_PORTB_CLK_EN();
		RCC_APB2ENR_PORTC_CLK_EN();
		for(l_pin_conuter = PORTA_PIN0 ;l_pin_conuter <= PORTC_PIN15 ;l_pin_conuter++)
		{
			/*Sets spped mode for output or sets mode to be input*/
			PORT_OUT_SPEED_SETTER(&ConfigPtr->Pins[l_pin_conuter]);
			/*Sets Pin Mode for output and input mode*/
			PORT_OUT_MOOD_SETTER(&ConfigPtr->Pins[l_pin_conuter]);
			/*Sets initial logic of pin*/
			switch(ConfigPtr->Pins[l_pin_conuter].Port)
			{
				case PORTA_INDEX:
					WRITE_BIT(GPIOA->ODR,ConfigPtr->Pins[l_pin_conuter].Pin_index,ConfigPtr->Pins[l_pin_conuter].Initial_Logic);
					break;
				case PORTB_INDEX:
					WRITE_BIT(GPIOB->ODR,ConfigPtr->Pins[l_pin_conuter].Pin_index,ConfigPtr->Pins[l_pin_conuter].Initial_Logic);
					break;
				case PORTC_INDEX:
					WRITE_BIT(GPIOC->ODR,ConfigPtr->Pins[l_pin_conuter].Pin_index,ConfigPtr->Pins[l_pin_conuter].Initial_Logic);
					break;
				default:break;
			}
			/*Lock the pins of configured as unchangable*/
			if(STD_ON == ConfigPtr->Pins[l_pin_conuter].DirectionChange){
				Pin_Lock_State(ConfigPtr->Pins[l_pin_conuter].Port,Port_Configuration.Pins[l_pin_conuter].Pin_index);
			}
			else{/* Do Nothing */}
		}
		Port_Status = PORT_INITIALIZED;
	}
}
/*
 * @Name Port_SetPinDirection
 * @Service ID : 0x01.
 * @Sync/Async : Synchronous.
 * @Reentrancy : Reentrant.
 * @Brief : Sets the port pin direction
 * @Parameter Pin : Pin ID to configure.
 * @Parameter Direction : Direction of pin.
 * @return : no return.
 */

#if PORT_SET_PIN_DIRECTION_API == STD_ON
void Port_SetPinDirection (
Port_PinType Pin,
Port_PinDirectionType Direction
)
{
	Port_ConfigPins PIN = Port_Configuration.Pins[Pin];
	uint8 error = FALSE;
#if PORT_DEV_ERROR_DETECT == STD_ON
	if( Pin >= NUMBER_OF_PORT_PINS )
	{
		/*Invalid Port Pin ID requested*/
		Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SETPINDIRECTION_ID,PORT_E_PARAM_PIN);
		error = TRUE;
	}
	else{}
	if(STD_OFF == Port_Configuration.Pins[Pin].DirectionChange){
		/*Port Pin not configured as un-changeable*/
		Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SETPINDIRECTION_ID,PORT_E_DIRECTION_UNCHANGEABLE);
		error = TRUE;
	}
	else{}
	if(PORT_NOT_INITIALIZED == Port_Status){
		/*API service called prior to module initialization*/
		Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SETPINDIRECTION_ID,PORT_E_UNINIT);
		error = TRUE;
	}
	else{}
#endif
	if(FALSE == error){
		if( PORT_PIN_IN == Direction ){
			PIN.Speed=SPEED_MODE_INPUT;
			PIN.Mode = INPUT;
			PIN.Pull = Pull_DOWN;
		}
		else if( PORT_PIN_OUT == Direction ){
			PIN.Speed=SPEED_2_MHZ;
			PIN.Mode = OUT_PUSH_PULL;
			PIN.Initial_Logic = STD_LOW;
		}
		PORT_OUT_SPEED_SETTER(&PIN);
		PORT_OUT_MOOD_SETTER(&PIN);
	}
	else{}
}
#endif
/*
 * @Name Port_RefreshPortDirection
 * @Service ID : 0x02.
 * @Sync/Async : Synchronous.
 * @Reentrancy : Reentrant.
 * @Brief : Refreshes port direction.
 * @Parameter: no Parameters
 * @return: no return.
 */
void Port_RefreshPortDirection (
void
)
{

	uint8 error = FALSE;
#if PORT_DEV_ERROR_DETECT == STD_ON
	if(PORT_NOT_INITIALIZED == Port_Status){
		/*API service called prior to module initialization*/
		Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_REFRESHPINDIRECTION_ID,PORT_E_UNINIT);
		error = TRUE;
	}
	else{}
#endif
	if(FALSE == error){
		uint8_least l_pin_conuter=PORTA_PIN0;
		for(l_pin_conuter = PORTA_PIN0 ;l_pin_conuter <= PORTC_PIN15 ;l_pin_conuter++)
		{
			if(STD_OFF == Port_Configuration.Pins[l_pin_conuter].DirectionChange)
			{
				/*Sets spped mode for output or sets mode to be input*/
				PORT_OUT_SPEED_SETTER(&Port_Configuration.Pins[l_pin_conuter]);
				/*Sets Pin Mode for output and input mode*/
				PORT_OUT_MOOD_SETTER(&Port_Configuration.Pins[l_pin_conuter]);
				/*Sets initial logic of pin*/
				switch(Port_Configuration.Pins[l_pin_conuter].Port)
				{
					case PORTA_INDEX:
						WRITE_BIT(GPIOA->ODR,Port_Configuration.Pins[l_pin_conuter].Pin_index,STD_HIGH);
						break;
					case PORTB_INDEX:
						WRITE_BIT(GPIOB->ODR,Port_Configuration.Pins[l_pin_conuter].Pin_index,STD_HIGH);
						break;
					case PORTC_INDEX:
						WRITE_BIT(GPIOC->ODR,Port_Configuration.Pins[l_pin_conuter].Pin_index,STD_HIGH);
						break;
					default:break;
				}
			}
		}

	}
	else{}
}

#if PORT_VERSION_INFO_API == STD_ON
/* @Name : Port_GetVersionInfo
 * @Service ID : 0x03.
 * @Sync/Async : Synchronous.
 * @Reentrancy : Reentrant.
 * @Brief :Returns the version information of this module.
 * @Parameter : Pointer to where to store the version information of this module.
 * @Return : No Return.
 */
void Port_GetVersionInfo (
Std_VersionInfoType* versioninfo
)
{

	if(NULL_PTR == versioninfo){
#if PORT_DEV_ERROR_DETECT == STD_ON
		/*Api called with a NULL Pointer Parameter*/
		Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_GETVERSIONINFO_ID,PORT_E_PARAM_POINTER);
#endif
	}
	else
	{

		versioninfo->vendorID =(uint16)PORT_VENDOR_ID_H;

		versioninfo->moduleID =(uint16)PORT_MODULE_ID;

		versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;

		versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;

		versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
	}

}
#endif
/*
 * @Name Port_SetPinMode
 * @Service ID : 0x04.
 * @Sync/Async : Synchronous.
 * @Reentrancy : Reentrant.
 * @Brief : Sets Port Pin Mode.
 * @Parameter Pin : Pin ID to configure.
 * @Parameter Direction : Mode of pin.
 * @return: no return.
 */
#if PORT_SET_PIN_MODE_API == STD_ON
void Port_SetPinMode (
Port_PinType Pin,
Port_PinModeType Mode
)
{
#if PORT_DEV_ERROR_DETECT == STD_ON
	Port_ConfigPins PIN = Port_Configuration.Pins[Pin];
	uint8 error = FALSE;
	if( Pin >= NUMBER_OF_PORT_PINS )
	{
		/*Invalid Port Pin ID requested*/
		Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_MODE_API,PORT_E_PARAM_PIN);
		error = TRUE;
	}
	else{}
	if(STD_OFF == Port_Configuration.Pins[Pin].DirectionChange){
		/*Port Pin not configured as un-changeable*/
		Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_MODE_API,PORT_E_MODE_UNCHANGEABLE);
		error = TRUE;
	}
	else{}
	if((Mode>=OUT_PUSH_PULL)&&(Mode<=INPUT)){
		/*Port Pin Mode passed not valid*/
		Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_MODE_API,PORT_E_PARAM_INVALID_MODE);
		error = TRUE;
	}
	if(PORT_NOT_INITIALIZED == Port_Status){
		/*API service called prior to module initialization*/
		Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_MODE_API,PORT_E_UNINIT);
		error = TRUE;
	}
#endif
	else{}
	if(FALSE == error){
		PIN.Mode=Mode;
		PORT_OUT_SPEED_SETTER(&PIN);
		PORT_OUT_MOOD_SETTER(&PIN);
	}
	else{}
}
#endif
/******************************************************************************/

/*******************************************************************************
 *                          Local Function Definitions                         *
 *******************************************************************************/

/*
 * @Brief 		: Static function used in Port_Init to lock pin state
 * @Descibtion  : The Function Locks PIN state if configured as unchangable
 * 				  after Initialization
 * @Sync/Async  : Synchronous.
 * @Reentrancy  : Reentrant.
 * @Parameter Port ID    : Port Index
 * @Parameter pin        : Channel Index.
 */
static void Pin_Lock_State(uint8 Port,uint8 Pin){
	GPIO_TypeDef * REG;
	switch(Port)
	{
	case PORTA_INDEX:REG = GPIOA;
		break;
	case PORTB_INDEX:REG = GPIOB;
		break;
	case PORTC_INDEX:REG = GPIOC;
		break;
	default:break;
	}
	SET_BIT(REG->LCKR,Pin);
}


/*
 * @Brief 		: Static function used in Port_Init to set pin speed as configured
 * @Descibtion  : The Function sets pin speed either to :
 * 			 	  SPEED_MODE_INPUT : Input Mode
 * 			 	  SPEED_10_MHZ     : 10 MHZ Output Mode
 * 			 	  SPEED_2_MHZ      : 2  MHZ Output Mode
 * 			 	  SPEED_50_MHZ     : 50 MHZ Output Mode
 * @Sync/Async  : Synchronous.
 * @Reentrancy  : Reentrant.
 * @Parameter pointer to pin configuration.
 */
static void PORT_OUT_SPEED_SETTER(const Port_ConfigPins * PIN)
{
	GPIO_TypeDef * REG;
	switch(PIN->Port)
	{
	case PORTA_INDEX:REG = GPIOA;
		break;
	case PORTB_INDEX:REG = GPIOB;
		break;
	case PORTC_INDEX:REG = GPIOC;
		break;
	default:break;
	}
	switch(PIN->Speed)
	{
	case SPEED_MODE_INPUT:
	    if(PIN->Pin_index<8)
	       {
	    		CLEAR_BIT(REG->CRL,(PIN->Pin_index*4+1));
	        	CLEAR_BIT(REG->CRL,(PIN->Pin_index*4));
	       }
	    else if((PIN->Pin_index>7)&&(PIN->Pin_index<16))
	       {
	    		CLEAR_BIT(REG->CRH,((PIN->Pin_index-8)*4+1));
	    		CLEAR_BIT(REG->CRH,((PIN->Pin_index-8)*4));
	       }
	    break;
	case SPEED_10_MHZ:
	    if(PIN->Pin_index<8)
	       {
	    		CLEAR_BIT(REG->CRL,(PIN->Pin_index*4+1));
	    		SET_BIT(REG->CRL,(PIN->Pin_index*4));
	       }
	    else if((PIN->Pin_index>7)&&(PIN->Pin_index<16))
	       {
	    		CLEAR_BIT(REG->CRH,((PIN->Pin_index-8)*4+1));
	    		SET_BIT(REG->CRH,((PIN->Pin_index-8)*4));
	       }
		break;

	case SPEED_2_MHZ:
	    if(PIN->Pin_index<8)
	       {
	        	SET_BIT(REG->CRL,(PIN->Pin_index*4+1));
	        	CLEAR_BIT(REG->CRL,(PIN->Pin_index*4));
	       }
	    else if((PIN->Pin_index>7)&&(PIN->Pin_index<16))
	       {
	    		SET_BIT(REG->CRH,((PIN->Pin_index-8)*4+1));
	    		CLEAR_BIT(REG->CRH,((PIN->Pin_index-8)*4));
	       }
	    break;
	case SPEED_50_MHZ:
	    if(PIN->Pin_index<8)
	       {
	        	SET_BIT(REG->CRL,(PIN->Pin_index*4+1));
	        	SET_BIT(REG->CRL,(PIN->Pin_index*4));
	       }
	    else if((PIN->Pin_index>7)&&(PIN->Pin_index<16))
	       {
	    		SET_BIT(REG->CRH,((PIN->Pin_index-8)*4+1));
	    		SET_BIT(REG->CRH,((PIN->Pin_index-8)*4));
	       }
	    break;
	default:break;
	}
}



/*
 * @Brief 		: Static function used in Port_Init to set pin Mood as configured
 * @Descibtion  : The Function sets pin Mood either to :
 * 			 	  OUT_PUSH_PULL    : Output push pull configuration
 * 			 	  OUT_OPEN_DRAIN   : Output open drain configuration
 * 			 	  AF_PUSH_PULL     : Alternative function push pull configuration
 * 			 	  AF_OPEN_DRAIN    : Alternative function open drain configuration
 * 			 	  ANALOG_INPUT 	   : ANALOG INPUT for ADC Mode
 * 			 	  INPUT			   : Regular input mode which has three Internal resisto connections :
 * 			 	  Port_InternalResistor:
 * 			 	  			            Floating : Pin is floating no internal resistors
 * 			 	  	  	                Pull_UP  : Pin is pulled up using internal resistor
 * 			 	  		                Pull_DOWN: Pin is pulled Down using internal resistor
 * @Sync/Async  : Synchronous.
 * @Reentrancy  : Reentrant.
 * @Parameter pointer to pin configuration.
 */
static void PORT_OUT_MOOD_SETTER(const Port_ConfigPins * PIN)
{
	GPIO_TypeDef * REG;
	switch(PIN->Port)
	{
	case PORTA_INDEX:REG = GPIOA;
		break;
	case PORTB_INDEX:REG = GPIOB;
		break;
	case PORTC_INDEX:REG = GPIOC;
		break;
	default:break;
	}
	if((OUT_PUSH_PULL == PIN->Mode)||(ANALOG_INPUT == PIN->Mode))
	{
	    if(PIN->Pin_index<8)
	    {
	   		CLEAR_BIT(REG->CRL,(PIN->Pin_index*4+2));
	       	CLEAR_BIT(REG->CRL,(PIN->Pin_index*4+3));
        }
	    else if((PIN->Pin_index>7)&&(PIN->Pin_index<16))
	    {
	  		CLEAR_BIT(REG->CRH,((PIN->Pin_index-8)*4+2));
	   		CLEAR_BIT(REG->CRH,((PIN->Pin_index-8)*4+3));
	    }
	}
	else if((OUT_OPEN_DRAIN == PIN->Mode)||((INPUT == PIN->Mode)&&(Floating == PIN->Pull)))
	{
		if(PIN->Pin_index<8)
		{
			CLEAR_BIT(REG->CRL,(PIN->Pin_index*4+3));
			SET_BIT(REG->CRL,(PIN->Pin_index*4+2));
		}
		else if((PIN->Pin_index>7)&&(PIN->Pin_index<16))
	    {
			CLEAR_BIT(REG->CRH,((PIN->Pin_index-8)*4+3));
			SET_BIT(REG->CRH,((PIN->Pin_index-8)*4+2));
	    }
	}
	else if((AF_PUSH_PULL == PIN->Mode)||((INPUT == PIN->Mode)&&(Pull_UP == PIN->Pull)))
	{
		if(PIN->Pin_index<8)
	    {
	       	SET_BIT(REG->CRL,(PIN->Pin_index*4+3));
	       	CLEAR_BIT(REG->CRL,((PIN->Pin_index)*4+2));
	    }
		else if((PIN->Pin_index>7)&&(PIN->Pin_index<16))
	    {
    		SET_BIT(REG->CRH,((PIN->Pin_index-8)*4+3));
	   		CLEAR_BIT(REG->CRH,((PIN->Pin_index-8)*4+2));
	    }
	}
    else if((AF_OPEN_DRAIN == PIN->Mode)||((INPUT == PIN->Mode)&&(Pull_DOWN == PIN->Pull)))
    {
	    if(PIN->Pin_index<8)
	    {
	       	SET_BIT(REG->CRL,(PIN->Pin_index*4+3));
	       	SET_BIT(REG->CRL,((PIN->Pin_index)*4+2));
        }
    else if((PIN->Pin_index>7)&&(PIN->Pin_index<16))
	    {
	   		SET_BIT(REG->CRH,((PIN->Pin_index-8)*4+3));
	   		SET_BIT(REG->CRH,((PIN->Pin_index-8)*4+2));
        }
    }
    else{/*Do Nothing*/}
}
/******************************************************************************/

