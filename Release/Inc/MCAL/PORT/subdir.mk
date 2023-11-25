################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/MCAL/PORT/Port.c \
../Inc/MCAL/PORT/Port_PBcfg.c 

OBJS += \
./Inc/MCAL/PORT/Port.o \
./Inc/MCAL/PORT/Port_PBcfg.o 

C_DEPS += \
./Inc/MCAL/PORT/Port.d \
./Inc/MCAL/PORT/Port_PBcfg.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/MCAL/PORT/%.o Inc/MCAL/PORT/%.su Inc/MCAL/PORT/%.cyclo: ../Inc/MCAL/PORT/%.c Inc/MCAL/PORT/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc-2f-MCAL-2f-PORT

clean-Inc-2f-MCAL-2f-PORT:
	-$(RM) ./Inc/MCAL/PORT/Port.cyclo ./Inc/MCAL/PORT/Port.d ./Inc/MCAL/PORT/Port.o ./Inc/MCAL/PORT/Port.su ./Inc/MCAL/PORT/Port_PBcfg.cyclo ./Inc/MCAL/PORT/Port_PBcfg.d ./Inc/MCAL/PORT/Port_PBcfg.o ./Inc/MCAL/PORT/Port_PBcfg.su

.PHONY: clean-Inc-2f-MCAL-2f-PORT

