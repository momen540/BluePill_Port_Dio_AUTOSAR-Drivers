################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/DET/Det.c 

OBJS += \
./Src/DET/Det.o 

C_DEPS += \
./Src/DET/Det.d 


# Each subdirectory must supply rules for building sources it contributes
Src/DET/%.o Src/DET/%.su Src/DET/%.cyclo: ../Src/DET/%.c Src/DET/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-DET

clean-Src-2f-DET:
	-$(RM) ./Src/DET/Det.cyclo ./Src/DET/Det.d ./Src/DET/Det.o ./Src/DET/Det.su

.PHONY: clean-Src-2f-DET

