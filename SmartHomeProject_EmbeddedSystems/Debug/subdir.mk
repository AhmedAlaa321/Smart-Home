################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../BUZZER.c \
../DC_MOTOR.c \
../DIO.c \
../Keypad.c \
../LCD.c \
../LED.c \
../SERVO.c \
../TEMP_SENSOR.c \
../TIM.c \
../UART.c \
../UART_CFG.c \
../main.c 

OBJS += \
./ADC.o \
./BUZZER.o \
./DC_MOTOR.o \
./DIO.o \
./Keypad.o \
./LCD.o \
./LED.o \
./SERVO.o \
./TEMP_SENSOR.o \
./TIM.o \
./UART.o \
./UART_CFG.o \
./main.o 

C_DEPS += \
./ADC.d \
./BUZZER.d \
./DC_MOTOR.d \
./DIO.d \
./Keypad.d \
./LCD.d \
./LED.d \
./SERVO.d \
./TEMP_SENSOR.d \
./TIM.d \
./UART.d \
./UART_CFG.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


