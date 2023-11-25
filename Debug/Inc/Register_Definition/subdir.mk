################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/Register_Definition/stm32f1xx_ll_rcc.c 

OBJS += \
./Inc/Register_Definition/stm32f1xx_ll_rcc.o 

C_DEPS += \
./Inc/Register_Definition/stm32f1xx_ll_rcc.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/Register_Definition/%.o Inc/Register_Definition/%.su Inc/Register_Definition/%.cyclo: ../Inc/Register_Definition/%.c Inc/Register_Definition/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc-2f-Register_Definition

clean-Inc-2f-Register_Definition:
	-$(RM) ./Inc/Register_Definition/stm32f1xx_ll_rcc.cyclo ./Inc/Register_Definition/stm32f1xx_ll_rcc.d ./Inc/Register_Definition/stm32f1xx_ll_rcc.o ./Inc/Register_Definition/stm32f1xx_ll_rcc.su

.PHONY: clean-Inc-2f-Register_Definition

