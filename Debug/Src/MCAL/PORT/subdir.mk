################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/PORT/Port.c \
../Src/MCAL/PORT/Port_PBcfg.c 

OBJS += \
./Src/MCAL/PORT/Port.o \
./Src/MCAL/PORT/Port_PBcfg.o 

C_DEPS += \
./Src/MCAL/PORT/Port.d \
./Src/MCAL/PORT/Port_PBcfg.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/PORT/%.o Src/MCAL/PORT/%.su Src/MCAL/PORT/%.cyclo: ../Src/MCAL/PORT/%.c Src/MCAL/PORT/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-MCAL-2f-PORT

clean-Src-2f-MCAL-2f-PORT:
	-$(RM) ./Src/MCAL/PORT/Port.cyclo ./Src/MCAL/PORT/Port.d ./Src/MCAL/PORT/Port.o ./Src/MCAL/PORT/Port.su ./Src/MCAL/PORT/Port_PBcfg.cyclo ./Src/MCAL/PORT/Port_PBcfg.d ./Src/MCAL/PORT/Port_PBcfg.o ./Src/MCAL/PORT/Port_PBcfg.su

.PHONY: clean-Src-2f-MCAL-2f-PORT

