 /*
 * @ file    		Compiler.h
 * @ author  		Mo'men Elhoseiny
 * @ brief			Common macros header file
 * @ Description	Provides macros commonly used in project
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

#ifndef COMMON_COMMON_MACROS_H_
#define COMMON_COMMON_MACROS_H_

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/*WRITES LOGIC TO DIO BIT*/
#define WRITE_BIT(REG,BIT,LOGIC)    REG=(REG&(~(1<<BIT)))|(LOGIC<<BIT)
/*READS A DIO BIT*/
#define READ_BIT(REG,PIN)           ((REG>>PIN)&0x01)
/*WRITES A DIO PORT*/
#define WRITE_REG(REG,DATA)              (REG = DATA)
/*READS A DIO PORT*/
#define READ_REG(REG)           	      (REG)
/*MODIFY REGISTER TO MUSK*/
#define MODIFY_REG(REG,CLEARMASK,SETMASK) WRITE_REG((REG),((READ_REG(REG)&(~(CLEARMASK))))|(SETMASK))
#define CLEAR_REG(REG)        ((REG) = (0x0))

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

#endif /* COMMON_COMMON_MACROS_H_ */
