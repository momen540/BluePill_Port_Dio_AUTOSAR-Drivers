  /*
  ******************************************************************************
  * @file    Dio.c
  * @author  Mo'men Elhoseiny
  * @brief   Source file for STM32F103c8t6 Microcontroller - Dio Driver
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
		#include <Common/Common_Macros.h>
		#include "../../../Inc/MCAL/DIO/Dio.h"
		#include "Register_Definition/Register_Definition.h"
/*=================================*/

/*
 * @Name  : Dio_ReadChannel.
 * @Service ID : 0x00
 * @Sync/Async : Synchronous.
 * @Reentrancy : Reentrant.
 * @Brief : Function receives a channel and returns it's state.
 * @Parameter ChannelId : ID Of DIO Channel.
 * @return :  Returns the value of specified DIO Channel :
 *			  STD_LEVEL_HIGH : Physical level of the pin  is HIGH.
 *			  STD_LEVEL_LOW : Physical level of the pin  is LOW.
 */
Dio_LevelType Dio_ReadChannel (
		Dio_ChannelType ChannelId
		)
{
	Dio_LevelType BitLogic=0;
#if DIO_DEV_ERROR_DETECT
	if( ChannelId > NUMBER_OF_DIO_CHANNELS )
	{
		/*Invalid channel requested*/
		Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_READ_CHANNEL_SID,DIO_E_PARAM_INVALID_CHANNEL_ID);
	}
	else
#endif
		{
			switch(Dio_Configuration.Channel[ChannelId].Port)
			{
				case DIO_PORTA:
					BitLogic =(Dio_LevelType) READ_BIT(GPIOA->IDR,Dio_Configuration.Channel[ChannelId].Pin);
					break;
				case DIO_PORTB:
					BitLogic =(Dio_LevelType) READ_BIT(GPIOB->IDR,Dio_Configuration.Channel[ChannelId].Pin);
					break;
				case DIO_PORTC:
					BitLogic =(Dio_LevelType) READ_BIT(GPIOC->IDR,Dio_Configuration.Channel[ChannelId].Pin);
					break;
				default:break;
			}
		}
	return BitLogic;
}


/*
 * @Name  : Dio_WriteChannel.
 * @Service ID : 0x01
 * @Sync/Async : Synchronous.
 * @Reentrancy : Reentrant.
 * @Brief : Function writes value on given channel.
 * @Parameter ChannelId : ID Of DIO Channel.
 * @Parameter Level : Value to be written on channel
 * @return : No return
 */
void Dio_WriteChannel (
		Dio_ChannelType ChannelId,
		Dio_LevelType Level
		)
{
#if DIO_DEV_ERROR_DETECT
	if( ChannelId > NUMBER_OF_DIO_CHANNELS)
	{
		/*Invalid channel requested*/
		Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_WRITE_CHANNEL_SID,DIO_E_PARAM_INVALID_CHANNEL_ID);
	}
	else
#endif
	{
		if(DIO_OUTPUT == Dio_Configuration.Channel[ChannelId].Mode){
				switch(Dio_Configuration.Channel[ChannelId].Port)
				{
					case DIO_PORTA:
						WRITE_BIT(GPIOA->ODR,Dio_Configuration.Channel[ChannelId].Pin,Level);
						break;
					case DIO_PORTB:
						WRITE_BIT(GPIOB->ODR,Dio_Configuration.Channel[ChannelId].Pin,Level);
						break;
					case DIO_PORTC:
						WRITE_BIT(GPIOC->ODR,Dio_Configuration.Channel[ChannelId].Pin,Level);
						break;
					default:break;
				}
		}
		else{
			/*Channel is not an output don't configure*/
		}
	}
}

/*
 * @Name  : Dio_ReadPort
 * @Service ID : 0x02
 * @Sync/Async : Synchronous.
 * @Reentrancy : Reentrant.
 * @Brief : Returns the level of all channels of that port.
 * @Parameter PortId : ID of DIO Port
 * @return Dio_PortLevelType : Returns the level of all channels of that port.
 */
Dio_PortLevelType Dio_ReadPort (
		Dio_PortType PortId
		)
{
	Dio_PortLevelType PORT_VAL=0;
#if DIO_DEV_ERROR_DETECT
	if(PortId > DIO_NUMBER_OF_PORTS)
	{
		/*Invalid port requested*/
		Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_READ_PORT_SID,DIO_E_PARAM_INVALID_PORT_ID);
	}
	else
#endif
	{
		switch(PortId)
		{
			case DIO_PORTA:PORT_VAL = (Dio_PortLevelType) READ_REG(GPIOA->IDR);
				break;
			case DIO_PORTB:PORT_VAL = (Dio_PortLevelType) READ_REG(GPIOB->IDR);
				break;
			case DIO_PORTC:PORT_VAL = (Dio_PortLevelType) READ_REG(GPIOC->IDR);
				break;
		}
	}
	return PORT_VAL;
}



/*
 * @Name  : Dio_WritePort.
 * @Service ID : 0x03
 * @Sync/Async : Synchronous.
 * @Reentrancy : Reentrant.
 * @Brief : Function writes value on given port.
 * @Parameter PortId : ID Of DIO Port.
 * @Parameter Level : Value to be written on Port.
 * @return : No return
 */
void Dio_WritePort (
		Dio_PortType PortId,
		Dio_PortLevelType Level
		)
{
	uint8_least l_ctr = 0;
#if DIO_DEV_ERROR_DETECT
	if(PortId > DIO_NUMBER_OF_PORTS)
	{
		/*Invalid port requested*/
		Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_WRITE_PORT_SID,DIO_E_PARAM_INVALID_PORT_ID);
	}
	else
#endif
	{
		switch(PortId)
		{
			case DIO_PORTA:
				for(l_ctr = DIO_PORTA_PIN0 ; l_ctr <= DIO_PORTA_PIN15 ; l_ctr++){
					if(DIO_OUTPUT == Dio_Configuration.Channel[l_ctr].Mode){
						WRITE_BIT(GPIOA->ODR,Dio_Configuration.Channel[l_ctr].Pin,((Level>>l_ctr)&0x01));
					}
					else{/*Do Nothing Channel is not output*/}
				}
				break;
			case DIO_PORTB:
				for(l_ctr = DIO_PORTB_PIN0 ; l_ctr <= DIO_PORTB_PIN15 ; l_ctr++){
					if(DIO_OUTPUT == Dio_Configuration.Channel[l_ctr].Mode){
						WRITE_BIT(GPIOB->ODR,Dio_Configuration.Channel[l_ctr].Pin,((Level>>(l_ctr-DIO_PORTB_PIN0))&0x01));
					}
					else{/*Do Nothing Channel is not output*/}
				}
				break;
			case DIO_PORTC:
				for(l_ctr = DIO_PORTC_PIN13 ; l_ctr <= DIO_PORTC_PIN15 ; l_ctr++){
					if(DIO_OUTPUT == Dio_Configuration.Channel[l_ctr].Mode){
						WRITE_BIT(GPIOC->ODR,Dio_Configuration.Channel[l_ctr].Pin,((Level>>(l_ctr-DIO_PORTC_PIN13))&0x01));
					}
					else{/*Do Nothing Channel is not output*/}
				}
				break;
		}
	}
}



/*
 * @Name  : Dio_ReadChannelGroup
 * @Service ID : 0x04
 * @Sync/Async : Synchronous.
 * @Reentrancy : Reentrant.
 * @Brief : This Service reads a subset of the adjoining bits of a port.
 * @Parameter ChannelGroupIdPtr : Pointer to ChannelGroup
 * @return Dio_PortLevelType : Level of a subset of the adjoining bits of a port
 *
 */
Dio_PortLevelType Dio_ReadChannelGroup (
		const Dio_ChannelGroupType* ChannelGroupIdPtr
		)
{
	Dio_PortLevelType Ret = 0;
	if( NULL_PTR == ChannelGroupIdPtr )
	{
#if DIO_DEV_ERROR_DETECT
		/*Invalid channel requested*/
		Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_READ_CHANNEL_GROUP_SID,DIO_E_PARAM_POINTER);
#endif
	}
	else
	{
		switch(ChannelGroupIdPtr->PortIndex)
		{
			case DIO_PORTA:
				Ret = (GPIOA->IDR << ChannelGroupIdPtr->offset)& (ChannelGroupIdPtr->mask);
				break;
			case DIO_PORTB:
				Ret = (GPIOB->IDR << ChannelGroupIdPtr->offset)& (ChannelGroupIdPtr->mask);
				break;
			case DIO_PORTC:
				Ret = (GPIOC->IDR << ChannelGroupIdPtr->offset)& (ChannelGroupIdPtr->mask);
				break;
			default:break;
		}
	}
	return Ret;
}

/*
 * @Name  : Dio_WriteChannelGroup
 * @Service ID : 0x05
 * @Sync/Async : Synchronous.
 * @Reentrancy : Reentrant.
 * @Brief : Service to set a subset of the adjoining bits of a port to a specified level.
 * @Parameter ChannelGroupIdPtr : Pointer to ChannelGroup
 * @Parameter Level : Value to be written ChannelGroup
 * @return : No return
 */
void Dio_WriteChannelGroup (
		const Dio_ChannelGroupType* ChannelGroupIdPtr,
		Dio_PortLevelType Level )
{
	Dio_PortLevelType Masked_Level = Level & ChannelGroupIdPtr->mask ;
	uint8_least l_ctr = 0;
	if( NULL_PTR == ChannelGroupIdPtr )
	{
#if DIO_DEV_ERROR_DETECT
		/*Invalid channel requested*/
		Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_WRITE_CHANNEL_GROUP_SID,DIO_E_PARAM_POINTER);
#endif
	}
	else
	switch(ChannelGroupIdPtr->PortIndex)
	{
			case DIO_PORTA:
				for((l_ctr = DIO_PORTA_PIN0 + ChannelGroupIdPtr->offset) ; l_ctr <= DIO_PORTA_PIN15 ; l_ctr++){
					if(DIO_OUTPUT == Dio_Configuration.Channel[l_ctr].Mode){
						WRITE_BIT(GPIOA->ODR,Dio_Configuration.Channel[l_ctr].Pin,((Masked_Level>>l_ctr)&0x01));
					}
					else{/*Do Nothing Channel is not output*/}
				}
				break;
			case DIO_PORTB:
				for((l_ctr = DIO_PORTB_PIN0 + ChannelGroupIdPtr->offset) ; l_ctr <= DIO_PORTB_PIN15 ; l_ctr++){
					if(DIO_OUTPUT == Dio_Configuration.Channel[l_ctr].Mode){
						WRITE_BIT(GPIOB->ODR,Dio_Configuration.Channel[l_ctr].Pin,((Masked_Level>>(l_ctr-DIO_PORTB_PIN0))&0x01));
					}
					else{/*Do Nothing Channel is not output*/}
				}
				break;
			case DIO_PORTC:
				for((l_ctr = DIO_PORTC_PIN13 + ChannelGroupIdPtr->offset); l_ctr <= DIO_PORTC_PIN15 ; l_ctr++){
					if(DIO_OUTPUT == Dio_Configuration.Channel[l_ctr].Mode){
						WRITE_BIT(GPIOC->ODR,Dio_Configuration.Channel[l_ctr].Pin,((Masked_Level>>(l_ctr-DIO_PORTC_PIN13))&0x01));
					}
					else{/*Do Nothing Channel is not output*/}
				}
				break;
	}
}



#if DIO_VERSION_INFO_API == STD_ON
/*
 * @Name  : Dio_GetVersionInfo
 * @Service ID : 0x12
 * @Brief : Service to get the version information of this module.
 * @Parameter : Pointer to store version info for the module.
 * @return : No return
 */
void Dio_GetVersionInfo (
		Std_VersionInfoType* VersionInfo
		)
{
	if(NULL_PTR == VersionInfo)
	{
#if DIO_DEV_ERROR_DETECT == STD_ON
		/*API service called with a NULL pointer*/
		Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_GET_VERSION_INFO_SID,DIO_E_PARAM_POINTER);
#endif
	}
	else
	{
		/* Copy the vendor Id */
		VersionInfo->vendorID = (uint16)DIO_VENDOR_ID;
		/* Copy the module Id */
		VersionInfo->moduleID = (uint16)DIO_MODULE_ID;
		/* Copy Software Major Version */
		VersionInfo->sw_major_version = (uint8)DIO_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		VersionInfo->sw_minor_version = (uint8)DIO_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		VersionInfo->sw_patch_version = (uint8)DIO_SW_PATCH_VERSION;
	}
}
#endif




#if DIO_FLIP_CHANNEL_API == STD_ON
/*
 * @Name  : Dio_FlipChannel
 * @Service ID : 0x11
 * @Sync/Async : Synchronous.
 * @Reentrancy : Reentrant.
 * @Brief : Service to toggle channel
 * @Parameter ChannelId : ID Of DIO Channel.
 * @return :  Returns the value of specified DIO Channel :
 *			  STD_LEVEL_HIGH : Physical level of the pin  is HIGH.
 *			  STD_LEVEL_LOW : Physical level of the pin  is LOW.
 */
Dio_LevelType Dio_FlipChannel (
		Dio_ChannelType ChannelId
		)
{
	Dio_LevelType ChannelLogic = 0;
#if DIO_DEV_ERROR_DETECT
	if( ChannelId > NUMBER_OF_DIO_CHANNELS)
	{
		/*Invalid channel requested*/
		Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_FLIP_CHANNEL_SID,DIO_E_PARAM_INVALID_CHANNEL_ID);
	}
	else
#endif
		{
			if(DIO_OUTPUT == Dio_Configuration.Channel[ChannelId].Mode){
				switch(Dio_Configuration.Channel[ChannelId].Port)
					{
						case DIO_PORTA:
							TOGGLE_BIT(GPIOA->ODR,Dio_Configuration.Channel[ChannelId].Pin);
							ChannelLogic = (Dio_LevelType) READ_BIT(GPIOA->ODR,Dio_Configuration.Channel[ChannelId].Pin);
							break;
						case DIO_PORTB:
							TOGGLE_BIT(GPIOA->ODR,Dio_Configuration.Channel[ChannelId].Pin);
							ChannelLogic = (Dio_LevelType) READ_BIT(GPIOB->ODR,Dio_Configuration.Channel[ChannelId].Pin);
							break;
						case DIO_PORTC:
							TOGGLE_BIT(GPIOC->ODR,Dio_Configuration.Channel[ChannelId].Pin);
							ChannelLogic = (Dio_LevelType) READ_BIT(GPIOC->ODR,Dio_Configuration.Channel[ChannelId].Pin);
							break;
						default:break;
					}
			}
			else{
				/*Channel is not an output don't configure*/
			}
		}
return ChannelLogic;
}
#endif



/*
 * @Name  : Dio_MaskedWritePort
 * @Service ID : 0x13
 * @Sync/Async : Synchronous.
 * @Reentrancy : Reentrant.
 * @Brief : Service to set the value of a given port with required mask.
 * @Parameter PortId : ID of DIO Port.
 * @Parameter Level : Value to be written.
 * @Parameter Mask : Channels to be masked in the port.
 * @return : No return
 */
void Dio_MaskedWritePort (
		Dio_PortType PortId,
		Dio_PortLevelType Level,
		Dio_PortLevelType Mask
		)
{
	Dio_PortLevelType Masked_Level = Level & Mask ;
	uint8_least l_ctr = 0;
#if DIO_DEV_ERROR_DETECT
	if(PortId > DIO_NUMBER_OF_PORTS)
	{
		/*Invalid port requested*/
		Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_MASKED_WRITE_PORT_SID,DIO_E_PARAM_INVALID_PORT_ID);
	}
	else
#endif
		switch(PortId)
		{
				case DIO_PORTA:
					for((l_ctr = DIO_PORTA_PIN0) ; l_ctr <= DIO_PORTA_PIN15 ; l_ctr++){
						if(DIO_OUTPUT == Dio_Configuration.Channel[l_ctr].Mode){
							WRITE_BIT(GPIOA->ODR,Dio_Configuration.Channel[l_ctr].Pin,((Masked_Level>>l_ctr)&0x01));
						}
						else{/*Do Nothing Channel is not output*/}
					}
					break;
				case DIO_PORTB:
					for((l_ctr = DIO_PORTB_PIN0) ; l_ctr <= DIO_PORTB_PIN15 ; l_ctr++){
						if(DIO_OUTPUT == Dio_Configuration.Channel[l_ctr].Mode){
							WRITE_BIT(GPIOB->ODR,Dio_Configuration.Channel[l_ctr].Pin,((Masked_Level>>(l_ctr-DIO_PORTB_PIN0))&0x01));
						}
						else{/*Do Nothing Channel is not output*/}
					}
					break;
				case DIO_PORTC:
					for((l_ctr = DIO_PORTC_PIN13); l_ctr <= DIO_PORTC_PIN15 ; l_ctr++){
						if(DIO_OUTPUT == Dio_Configuration.Channel[l_ctr].Mode){
							WRITE_BIT(GPIOC->ODR,Dio_Configuration.Channel[l_ctr].Pin,((Masked_Level>>(l_ctr-DIO_PORTC_PIN13))&0x01));
						}
						else{/*Do Nothing Channel is not output*/}
					}
					break;
		}
}
