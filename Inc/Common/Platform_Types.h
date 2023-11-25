 /*
 * @ file    		Platform_Types.h
 * @ author  		Mo'men Elhoseiny
 * @ brief			Platform dependent data types and definitions
 * @ Description	AUTOSAR Platform dependent header file
 * 					Contains all platform dependent Types and Symbols
 * 					File provides abstraction in order to become platform and compiler dependent
 * @ Date    		Created on July 26, 2023
 */

 /*===============================================================================
 *  Project				: AUTOSAR 4.4.0 MCAL
 *  Platform			: ARM
 *  Peripheral			: STM32F103c8t6
 *  Autosar vesion  	: 4.4.0
 *  Autosar Revesion	: ASR_REL_4_0_REV_0000
 *  SW Version			: 1.0.0
 *===============================================================================*/

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H


/*******************************************************************************
 *                             Version Definitions                             *
 *******************************************************************************/
/*
 * Id for the company in the AUTOSAR
 */

#define PLATFORM_VENDOR_ID                          (1000U)

/*
 * Module Version 1.0.0
 */
#define PLATFORM_SW_MAJOR_VERSION                   (1U)
#define PLATFORM_SW_MINOR_VERSION                   (0U)
#define PLATFORM_SW_PATCH_VERSION                   (0U)

/*
 * AUTOSAR Version 4.4.0
 */
#define PLATFORM_AR_RELEASE_MAJOR_VERSION           (4U)
#define PLATFORM_AR_RELEASE_MINOR_VERSION           (4U)
#define PLATFORM_AR_RELEASE_PATCH_VERSION           (0U)

 /*******************************************************************************/

/*******************************************************************************
 *                                 Macros                                      *
 *******************************************************************************/

/*
 * @ Brief 		:	8bit microprocessor
 * @ implements :	CPU_TYPE_Enumeration
 */
#define CPU_TYPE_8                                  (8U)

/*
 * @ Brief 		:	16bit microprocessor
 * @ implements :	CPU_TYPE_Enumeration
 */
#define CPU_TYPE_16                                 (16U)

/*
 * @ Brief 		:	32bit microprocessor
 * @ implements :	CPU_TYPE_Enumeration
 */
#define CPU_TYPE_32                                 (32U)

/*
 * @ Brief 		:	64bit microprocessor
 * @ implements :	CPU_TYPE_Enumeration
 */
#define CPU_TYPE_64                                 (64U)

/*
 * @ Brief 		:	Big endian bit ordering
 * @ implements :	CPU_BIT_ORDER_Enumeration
 */
#define MSB_FIRST                   (0u)

/*
 * @ Brief 		:	Little endian bit ordering
 * @ implements :	CPU_BIT_ORDER_Enumeration
 */
#define LSB_FIRST                   (1u)

/*
 * @ Brief 		:	Big endian byte ordering
 * @ implements :	CPU_BYTE_ORDER_Enumeration
 */
#define HIGH_BYTE_FIRST             (0u)

/*
 * @ Brief 		:	Little endian byte ordering
 * @ implements :	CPU_BYTE_ORDER_Enumeration
 */
#define LOW_BYTE_FIRST              (1u)

/*
 * @ Brief 		:	Processor Type
 * @ implements :	CPU_TYPE_Enumeration
 */
#define CPU_TYPE            (CPU_TYPE_32)

/*
 * @ Brief 		:	CPU Bit order
 * @ implements :	CPU_BIT_ORDER_Enumeration
 */
#define CPU_BIT_ORDER       (LSB_FIRST)

/*
 * @ Brief 		:	CPU Byte order
 * @ implements :	CPU_BYTE_ORDER_Enumeration
 */
#define CPU_BYTE_ORDER      (LOW_BYTE_FIRST)

#ifndef TRUE
	/*
	 * @Brief 		: 	Boolean True
	 * @Implements	: 	True_False Enumeration
	 */
	#define TRUE  ((uint8)1)
#endif

#ifndef FALSE
	/*
	 * @Brief 		: 	Boolean False
	 * @Implements	: 	True_False Enumeration
	 */
	#define FALSE ((uint8)0)
#endif

/*NULL Definition*/


/*******************************************************************************/

/*******************************************************************************
 *                          User Defined Data Types                            *
 *******************************************************************************/

#if (CPU_TYPE == CPU_TYPE_16)


/*
 * @Brief 		: 	Standard AUTOSAR Boolean implemented on 8bit long basis
 * @Implements	:	Boolean Type
 */
typedef unsigned char boolean;


 /*
  * @Brief 		: 	Unsigned 8 bit integer ranging from 0 ..+255 (0x00 to 0xFF)
  * @Implements	:	uint8_Type
  */
typedef unsigned char uint8;


/*
 * @Brief 		: 	Unsigned 16 bit integer ranging from 0 ..+65535 (0x0000 to 0xFFFF)
 * @Implements	:	uint16_Type
 */
typedef unsigned short uint16;


/*
 * @Brief 		: 	Unsigned 32 bit integer ranging from 0 ..+4294967295 (0x00000000 to 0xFFFFFFFF)
 * @Implements	:	uint32_Type
 */
typedef unsigned long uint32;


/*
 * @Brief 		: 	Unsigned 64 bit integer ranging from 0 ..+18446744073709551615 (0x0000000000000000 to 0xFFFFFFFFFFFFFFFF)
 * @Implements	:	uint64_Type
 */
typedef unsigned long long uint64;


/*
 * @Brief 		: 	Signed 8 bit integer ranging from -128 ..+127 (0x00 to 0xFF)
 * @Implements	:	sint8_Type
 */
typedef signed char sint8;


/*
 * @Brief 		: 	Signed 16 bit integer ranging from -32768 ..+32767 (0x0000 to 0xFFFF)
 * @Implements	:	sint16_Type
 */
typedef signed short sint16;


/*
 * @Brief 		: 	Unsigned 32 bit integer ranging from -2147483648 ..+2147483647 (0x00000000 to 0xFFFFFFFF)
 * @Implements	:	sint32_Type
 */
typedef signed long sint32;


/*
 * @Brief 		: 	Unsigned 64 bit integer ranging from -9223372036854775808 ..+9223372036854775807
 * 					(0x0000000000000000 to 0xFFFFFFFFFFFFFFFF)
 * @Implements	:	sint64_Type
 */
typedef signed long long sint64;


/*
 * @Brief 		: 	Unsigned integer atleast 8 bit ranging from 0 ..+255 (0x00 to 0xFF)
 * @Implements	:	uint8_least_Type
 */
typedef unsigned long uint8_least;


/*
 * @Brief 		: 	Unsigned integer atleast 16 bit ranging from 0 ..+65535 (0x0000 to 0xFFFF)
 * @Implements	:	uint16_least_Type
 */
typedef unsigned long uint16_least;


/*
 * @Brief 		: 	Unsigned integer at least 32 bit ranging from 0 ..+4294967295 (0x00000000 to 0xFFFFFFFF)
 * @Implements	:	uint32_least_Type
 */
typedef unsigned long uint32_least;


/*
 * @Brief 		: 	Signed integer at least 8 bit ranging from -128 ..+127 (0x00 to 0xFF)
 * @Implements	:	sint8_type_least_Type
 */
typedef signed long sint8_least;


/*
 * @Brief 		: 	signed integer atleast 16 bit ranging from -32768 ..+32767 (0x0000 to 0xFFFF)
 * @Implements	:	sint16_least_Type
 */
typedef signed long sint16_least;


/*
 * @Brief 		: 	signed integer at least 32 bit ranging from -2147483648 ..+2147483647 (0x00000000 to 0xFFFFFFFF)
 * @Implements	:	sint32_least_Type
 */
typedef signed long sint32_least;


/*
 * @Brief 		: 	32 bit long float
 * @Implements	:	float32
 */
typedef float float32;


/*
 * @Brief 		: 	64bit long float
 * @Implements	:	float64_Type
 */
typedef double float64;

#elif (CPU_TYPE == CPU_TYPE_32)


/*
 * @Brief 		: 	Standard AUTOSAR Boolean implemented on 8bit long basis
 * @Implements	:	Boolean Type
 */
typedef unsigned char boolean;


/*
 * @Brief 		: 	Unsigned 8 bit integer ranging from 0 ..+255 (0x00 to 0xFF)
 * @Implements	:	uint8_Type
 */
typedef unsigned char uint8;


/*
 * @Brief 		: 	Unsigned 16 bit integer ranging from 0 ..+65535 (0x0000 to 0xFFFF)
 * @Implements	:	uint16_Type
 */
typedef unsigned short uint16;


/*
 * @Brief 		: 	Unsigned 32 bit integer ranging from 0 ..+4294967295 (0x00000000 to 0xFFFFFFFF)
 * @Implements	:	uint32_Type
 */
typedef unsigned long uint32;


/*
 * @Brief 		: 	Unsigned 64 bit integer ranging from 0 ..+18446744073709551615 (0x0000000000000000 to 0xFFFFFFFFFFFFFFFF)
 * @Implements	:	uint64_Type
 */
typedef unsigned long long uint64;


/*
 * @Brief 		: 	Signed 8 bit integer ranging from -128 ..+127 (0x00 to 0xFF)
 * @Implements	:	sint8_Type
 */
typedef signed char sint8;


/*
 * @Brief 		: 	Signed 16 bit integer ranging from -32768 ..+32767 (0x0000 to 0xFFFF)
 * @Implements	:	sint16_Type
 */
typedef signed short sint16;


/*
 * @Brief 		: 	Unsigned 32 bit integer ranging from -2147483648 ..+2147483647 (0x00000000 to 0xFFFFFFFF)
 * @Implements	:	sint32_Type
 */
typedef signed long sint32;


/*
 * @Brief 		: 	Unsigned 64 bit integer ranging from -9223372036854775808 ..+9223372036854775807
 * 					(0x0000000000000000 to 0xFFFFFFFFFFFFFFFF)
 * @Implements	:	sint64_Type
 */
typedef signed long long sint64;


/*
 * @Brief 		: 	Unsigned integer atleast 8 bit ranging from 0 ..+255 (0x00 to 0xFF)
 * @Implements	:	uint8_least_Type
 */
typedef unsigned long uint8_least;


/*
 * @Brief 		: 	Unsigned integer atleast 16 bit ranging from 0 ..+65535 (0x0000 to 0xFFFF)
 * @Implements	:	uint16_least_Type
 */
typedef unsigned long uint16_least;


/*
 * @Brief 		: 	Unsigned integer at least 32 bit ranging from 0 ..+4294967295 (0x00000000 to 0xFFFFFFFF)
 * @Implements	:	uint32_least_Type
 */
typedef unsigned long uint32_least;


/*
 * @Brief 		: 	Signed integer at least 8 bit ranging from -128 ..+127 (0x00 to 0xFF)
 * @Implements	:	sint8_type_least_Type
 */
typedef signed long sint8_least;


/*
 * @Brief 		: 	signed integer atleast 16 bit ranging from -32768 ..+32767 (0x0000 to 0xFFFF)
 * @Implements	:	sint16_least_Type
 */
typedef signed long sint16_least;


/*
 * @Brief 		: 	signed integer at least 32 bit ranging from -2147483648 ..+2147483647 (0x00000000 to 0xFFFFFFFF)
 * @Implements	:	sint32_least_Type
 */
typedef signed long sint32_least;


/*
 * @Brief 		: 	32 bit long float
 * @Implements	:	float32
 */
typedef float float32;


/*
 * @Brief 		: 	64bit long float
 * @Implements	:	float64_Type
 */
typedef double float64;

#elif (CPU_TYPE == CPU_TYPE_64)

/*
 * @Brief 		: 	Standard AUTOSAR Boolean implemented on 8bit long basis
 * @Implements	:	Boolean Type
 */
typedef unsigned char boolean;


/*
 * @Brief 		: 	Unsigned 8 bit integer ranging from 0 ..+255 (0x00 to 0xFF)
 * @Implements	:	uint8_Type
 */


/*
 * @Brief 		: 	Unsigned 16 bit integer ranging from 0 ..+65535 (0x0000 to 0xFFFF)
 * @Implements	:	uint16_Type
 */
typedef unsigned short uint16;


/*
 * @Brief 		: 	Unsigned 32 bit integer ranging from 0 ..+4294967295 (0x00000000 to 0xFFFFFFFF)
 * @Implements	:	uint32_Type
 */
typedef unsigned int uint32;


/*
 * @Brief 		: 	Unsigned 64 bit integer ranging from 0 ..+18446744073709551615 (0x0000000000000000 to 0xFFFFFFFFFFFFFFFF)
 * @Implements	:	uint64_Type
 */
typedef unsigned long long uint64;


/*
 * @Brief 		: 	Signed 8 bit integer ranging from -128 ..+127 (0x00 to 0xFF)
 * @Implements	:	sint8_Type
 */
typedef signed char sint8;


/*
 * @Brief 		: 	Signed 16 bit integer ranging from -32768 ..+32767 (0x0000 to 0xFFFF)
 * @Implements	:	sint16_Type
 */
typedef signed short sint16;


/*
 * @Brief 		: 	Unsigned 32 bit integer ranging from -2147483648 ..+2147483647 (0x00000000 to 0xFFFFFFFF)
 * @Implements	:	sint32_Type
 */
typedef signed int sint32;


/*
 * @Brief 		: 	Unsigned 64 bit integer ranging from -9223372036854775808 ..+9223372036854775807
 * 					(0x0000000000000000 to 0xFFFFFFFFFFFFFFFF)
 * @Implements	:	sint64_Type
 */
typedef signed long long sint64;


/*
 * @Brief 		: 	Unsigned integer atleast 8 bit ranging from 0 ..+255 (0x00 to 0xFF)
 * @Implements	:	uint8_least_Type
 */
typedef unsigned int uint8_least;


/*
 * @Brief 		: 	Unsigned integer atleast 16 bit ranging from 0 ..+65535 (0x0000 to 0xFFFF)
 * @Implements	:	uint16_least_Type
 */
typedef unsigned int uint16_least;


/*
 * @Brief 		: 	Unsigned integer at least 32 bit ranging from 0 ..+4294967295 (0x00000000 to 0xFFFFFFFF)
 * @Implements	:	uint32_least_Type
 */
typedef unsigned int uint32_least;


/*
 * @Brief 		: 	Signed integer at least 8 bit ranging from -128 ..+127 (0x00 to 0xFF)
 * @Implements	:	sint8_type_least_Type
 */
typedef signed int sint8_least;


/*
 * @Brief 		: 	signed integer atleast 16 bit ranging from -32768 ..+32767 (0x0000 to 0xFFFF)
 * @Implements	:	sint16_least_Type
 */
typedef signed int sint16_least;


/*
 * @Brief 		: 	signed integer at least 32 bit ranging from -2147483648 ..+2147483647 (0x00000000 to 0xFFFFFFFF)
 * @Implements	:	sint32_least_Type
 */
typedef signed int sint32_least;


/*
 * @Brief 		: 	32 bit long float
 * @Implements	:	float32
 */
typedef float float32;


/*
 * @Brief 		: 	64bit long float
 * @Implements	:	float64_Type
 */
typedef double float64;

#endif /*Cpu Type*/
/*******************************************************************************/
#endif /* PLATFORM_TYPES_H */


