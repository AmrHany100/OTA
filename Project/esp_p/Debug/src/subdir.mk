################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ESP_program.c \
../src/FPEC_program.c \
../src/GPIO_program.c \
../src/Parse.c \
../src/RCC_program.c \
../src/UART_config.c \
../src/UART_program.c \
../src/main.c 

OBJS += \
./src/ESP_program.o \
./src/FPEC_program.o \
./src/GPIO_program.o \
./src/Parse.o \
./src/RCC_program.o \
./src/UART_config.o \
./src/UART_program.o \
./src/main.o 

C_DEPS += \
./src/ESP_program.d \
./src/FPEC_program.d \
./src/GPIO_program.d \
./src/Parse.d \
./src/RCC_program.d \
./src/UART_config.d \
./src/UART_program.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


