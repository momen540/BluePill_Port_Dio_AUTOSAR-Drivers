################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/CDD/UART/UART.c 

OBJS += \
./Src/CDD/UART/UART.o 

C_DEPS += \
./Src/CDD/UART/UART.d 


# Each subdirectory must supply rules for building sources it contributes
Src/CDD/UART/%.o Src/CDD/UART/%.su Src/CDD/UART/%.cyclo: ../Src/CDD/UART/%.c Src/CDD/UART/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-CDD-2f-UART

clean-Src-2f-CDD-2f-UART:
	-$(RM) ./Src/CDD/UART/UART.cyclo ./Src/CDD/UART/UART.d ./Src/CDD/UART/UART.o ./Src/CDD/UART/UART.su

.PHONY: clean-Src-2f-CDD-2f-UART

