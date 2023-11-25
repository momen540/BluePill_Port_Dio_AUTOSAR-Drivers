################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/CortexM3/CortexM3_Core_Nvic.c \
../Src/CortexM3/CortexM3_Core_SCB.c \
../Src/CortexM3/CortexM3_Core_SysTick.c 

OBJS += \
./Src/CortexM3/CortexM3_Core_Nvic.o \
./Src/CortexM3/CortexM3_Core_SCB.o \
./Src/CortexM3/CortexM3_Core_SysTick.o 

C_DEPS += \
./Src/CortexM3/CortexM3_Core_Nvic.d \
./Src/CortexM3/CortexM3_Core_SCB.d \
./Src/CortexM3/CortexM3_Core_SysTick.d 


# Each subdirectory must supply rules for building sources it contributes
Src/CortexM3/%.o Src/CortexM3/%.su Src/CortexM3/%.cyclo: ../Src/CortexM3/%.c Src/CortexM3/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-CortexM3

clean-Src-2f-CortexM3:
	-$(RM) ./Src/CortexM3/CortexM3_Core_Nvic.cyclo ./Src/CortexM3/CortexM3_Core_Nvic.d ./Src/CortexM3/CortexM3_Core_Nvic.o ./Src/CortexM3/CortexM3_Core_Nvic.su ./Src/CortexM3/CortexM3_Core_SCB.cyclo ./Src/CortexM3/CortexM3_Core_SCB.d ./Src/CortexM3/CortexM3_Core_SCB.o ./Src/CortexM3/CortexM3_Core_SCB.su ./Src/CortexM3/CortexM3_Core_SysTick.cyclo ./Src/CortexM3/CortexM3_Core_SysTick.d ./Src/CortexM3/CortexM3_Core_SysTick.o ./Src/CortexM3/CortexM3_Core_SysTick.su

.PHONY: clean-Src-2f-CortexM3

