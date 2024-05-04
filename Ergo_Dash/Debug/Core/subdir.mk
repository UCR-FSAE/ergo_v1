################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/CAN_Receive.cpp \
../Core/CAN_Send.cpp \
../Core/Filter_Config.cpp \
../Core/main.cpp 

OBJS += \
./Core/CAN_Receive.o \
./Core/CAN_Send.o \
./Core/Filter_Config.o \
./Core/main.o 

CPP_DEPS += \
./Core/CAN_Receive.d \
./Core/CAN_Send.d \
./Core/Filter_Config.d \
./Core/main.d 


# Each subdirectory must supply rules for building sources it contributes
Core/%.o Core/%.su Core/%.cyclo: ../Core/%.cpp Core/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F413xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core

clean-Core:
	-$(RM) ./Core/CAN_Receive.cyclo ./Core/CAN_Receive.d ./Core/CAN_Receive.o ./Core/CAN_Receive.su ./Core/CAN_Send.cyclo ./Core/CAN_Send.d ./Core/CAN_Send.o ./Core/CAN_Send.su ./Core/Filter_Config.cyclo ./Core/Filter_Config.d ./Core/Filter_Config.o ./Core/Filter_Config.su ./Core/main.cyclo ./Core/main.d ./Core/main.o ./Core/main.su

.PHONY: clean-Core

