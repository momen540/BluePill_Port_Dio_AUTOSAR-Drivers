################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/HAL/LED/Led.c 

OBJS += \
./Src/HAL/LED/Led.o 

C_DEPS += \
./Src/HAL/LED/Led.d 


# Each subdirectory must supply rules for building sources it contributes
Src/HAL/LED/%.o Src/HAL/LED/%.su Src/HAL/LED/%.cyclo: ../Src/HAL/LED/%.c Src/HAL/LED/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-HAL-2f-LED

clean-Src-2f-HAL-2f-LED:
	-$(RM) ./Src/HAL/LED/Led.cyclo ./Src/HAL/LED/Led.d ./Src/HAL/LED/Led.o ./Src/HAL/LED/Led.su

.PHONY: clean-Src-2f-HAL-2f-LED

