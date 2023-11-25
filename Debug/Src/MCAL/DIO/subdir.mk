################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/DIO/Dio.c \
../Src/MCAL/DIO/Dio_PBcfg.c 

OBJS += \
./Src/MCAL/DIO/Dio.o \
./Src/MCAL/DIO/Dio_PBcfg.o 

C_DEPS += \
./Src/MCAL/DIO/Dio.d \
./Src/MCAL/DIO/Dio_PBcfg.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/DIO/%.o Src/MCAL/DIO/%.su Src/MCAL/DIO/%.cyclo: ../Src/MCAL/DIO/%.c Src/MCAL/DIO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-MCAL-2f-DIO

clean-Src-2f-MCAL-2f-DIO:
	-$(RM) ./Src/MCAL/DIO/Dio.cyclo ./Src/MCAL/DIO/Dio.d ./Src/MCAL/DIO/Dio.o ./Src/MCAL/DIO/Dio.su ./Src/MCAL/DIO/Dio_PBcfg.cyclo ./Src/MCAL/DIO/Dio_PBcfg.d ./Src/MCAL/DIO/Dio_PBcfg.o ./Src/MCAL/DIO/Dio_PBcfg.su

.PHONY: clean-Src-2f-MCAL-2f-DIO

