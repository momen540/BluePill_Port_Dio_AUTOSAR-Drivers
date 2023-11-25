################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/CRC/CRC.c 

OBJS += \
./Src/MCAL/CRC/CRC.o 

C_DEPS += \
./Src/MCAL/CRC/CRC.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/CRC/%.o Src/MCAL/CRC/%.su Src/MCAL/CRC/%.cyclo: ../Src/MCAL/CRC/%.c Src/MCAL/CRC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-MCAL-2f-CRC

clean-Src-2f-MCAL-2f-CRC:
	-$(RM) ./Src/MCAL/CRC/CRC.cyclo ./Src/MCAL/CRC/CRC.d ./Src/MCAL/CRC/CRC.o ./Src/MCAL/CRC/CRC.su

.PHONY: clean-Src-2f-MCAL-2f-CRC

