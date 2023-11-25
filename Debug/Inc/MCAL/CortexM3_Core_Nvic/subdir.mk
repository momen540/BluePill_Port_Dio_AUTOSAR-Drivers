################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/MCAL/CortexM3_Core_Nvic/CortexM3_Core_Nvic.c 

OBJS += \
./Inc/MCAL/CortexM3_Core_Nvic/CortexM3_Core_Nvic.o 

C_DEPS += \
./Inc/MCAL/CortexM3_Core_Nvic/CortexM3_Core_Nvic.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/MCAL/CortexM3_Core_Nvic/%.o Inc/MCAL/CortexM3_Core_Nvic/%.su Inc/MCAL/CortexM3_Core_Nvic/%.cyclo: ../Inc/MCAL/CortexM3_Core_Nvic/%.c Inc/MCAL/CortexM3_Core_Nvic/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc-2f-MCAL-2f-CortexM3_Core_Nvic

clean-Inc-2f-MCAL-2f-CortexM3_Core_Nvic:
	-$(RM) ./Inc/MCAL/CortexM3_Core_Nvic/CortexM3_Core_Nvic.cyclo ./Inc/MCAL/CortexM3_Core_Nvic/CortexM3_Core_Nvic.d ./Inc/MCAL/CortexM3_Core_Nvic/CortexM3_Core_Nvic.o ./Inc/MCAL/CortexM3_Core_Nvic/CortexM3_Core_Nvic.su

.PHONY: clean-Inc-2f-MCAL-2f-CortexM3_Core_Nvic

