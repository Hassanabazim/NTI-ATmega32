################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/HLED/HLED_prog.c 

OBJS += \
./HAL/HLED/HLED_prog.o 

C_DEPS += \
./HAL/HLED/HLED_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/HLED/%.o: ../HAL/HLED/%.c HAL/HLED/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Projects\SMALL_OS\APP" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Projects\SMALL_OS\HAL\HLED" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Projects\SMALL_OS\HAL\HPB" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Projects\SMALL_OS\LIB" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Projects\SMALL_OS\MCAL\MDIO" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Projects\SMALL_OS\MCAL\MGIO" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Projects\SMALL_OS\MCAL\MTIMER0" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


