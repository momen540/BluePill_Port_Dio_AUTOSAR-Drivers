################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/MCAL/DIO/Dio.c \
../Inc/MCAL/DIO/Dio_PBcfg.c 

OBJS += \
./Inc/MCAL/DIO/Dio.o \
./Inc/MCAL/DIO/Dio_PBcfg.o 

C_DEPS += \
./Inc/MCAL/DIO/Dio.d \
./Inc/MCAL/DIO/Dio_PBcfg.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/MCAL/DIO/%.o Inc/MCAL/DIO/%.su Inc/MCAL/DIO/%.cyclo: ../Inc/MCAL/DIO/%.c Inc/MCAL/DIO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc-2f-MCAL-2f-DIO

clean-Inc-2f-MCAL-2f-DIO:
	-$(RM) ./Inc/MCAL/DIO/Dio.cyclo ./Inc/MCAL/DIO/Dio.d ./Inc/MCAL/DIO/Dio.o ./Inc/MCAL/DIO/Dio.su ./Inc/MCAL/DIO/Dio_PBcfg.cyclo ./Inc/MCAL/DIO/Dio_PBcfg.d ./Inc/MCAL/DIO/Dio_PBcfg.o ./Inc/MCAL/DIO/Dio_PBcfg.su

.PHONY: clean-Inc-2f-MCAL-2f-DIO

