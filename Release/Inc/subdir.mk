################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/cfg.c \
../Inc/stm32f1xx_ll_rcc.c \
../Inc/systick_delay.c 

OBJS += \
./Inc/cfg.o \
./Inc/stm32f1xx_ll_rcc.o \
./Inc/systick_delay.o 

C_DEPS += \
./Inc/cfg.d \
./Inc/stm32f1xx_ll_rcc.d \
./Inc/systick_delay.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/%.o Inc/%.su Inc/%.cyclo: ../Inc/%.c Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc

clean-Inc:
	-$(RM) ./Inc/cfg.cyclo ./Inc/cfg.d ./Inc/cfg.o ./Inc/cfg.su ./Inc/stm32f1xx_ll_rcc.cyclo ./Inc/stm32f1xx_ll_rcc.d ./Inc/stm32f1xx_ll_rcc.o ./Inc/stm32f1xx_ll_rcc.su ./Inc/systick_delay.cyclo ./Inc/systick_delay.d ./Inc/systick_delay.o ./Inc/systick_delay.su

.PHONY: clean-Inc

