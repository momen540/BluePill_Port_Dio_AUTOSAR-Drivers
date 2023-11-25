################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/DET/Det.c 

OBJS += \
./Inc/DET/Det.o 

C_DEPS += \
./Inc/DET/Det.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/DET/%.o Inc/DET/%.su Inc/DET/%.cyclo: ../Inc/DET/%.c Inc/DET/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc-2f-DET

clean-Inc-2f-DET:
	-$(RM) ./Inc/DET/Det.cyclo ./Inc/DET/Det.d ./Inc/DET/Det.o ./Inc/DET/Det.su

.PHONY: clean-Inc-2f-DET

