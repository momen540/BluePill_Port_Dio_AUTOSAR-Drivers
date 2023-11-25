  /*
  ******************************************************************************
  * @file    RCC.c
  * @author  Mo'men Elhoseiny
  * @brief   RCC post-build Configurations
  * @Date    Created on July 26, 2023
  ******************************************************************************
  */

/*=================================*/
  /*
   *  Includes section
   */
		#include "../../../Inc/MCAL/RCC/RCC.h"
/*=================================*/


const Clock_cfg_t SystemClkCfg=
{
		AHB_DIV1,
		PLL_MUL_9,
		APB2_DIV1,
		APB1_DIV2,
		PLL_Osc,
		PLL_HSE,

};
