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
	avr-gcc -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Atmega32-Drives\HAL\HULTRA" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Atmega32-Drives\APP" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Atmega32-Drives\HAL\H16x2LCD" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Atmega32-Drives\HAL\H20x4LCD" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Atmega32-Drives\HAL\H4SSD" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Atmega32-Drives\HAL\HBUZZ" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Atmega32-Drives\HAL\HEEPROM" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Atmega32-Drives\HAL\HKEYPAD" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Atmega32-Drives\HAL\HLED" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Atmega32-Drives\HAL\HLM35" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Atmega32-Drives\HAL\HMOTOR" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Atmega32-Drives\HAL\HPB" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Atmega32-Drives\HAL\HSSD" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Atmega32-Drives\LIB" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Atmega32-Drives\MCAL\MADC" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Atmega32-Drives\MCAL\MDIO" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Atmega32-Drives\MCAL\MEXTI" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Atmega32-Drives\MCAL\MGIE" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Atmega32-Drives\MCAL\MSPI" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Atmega32-Drives\MCAL\MTIMER0" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Atmega32-Drives\MCAL\MTIMER1" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Atmega32-Drives\MCAL\MTWI" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Atmega32-Drives\MCAL\MUSART" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Atmega32-Drives\MCAL\MWDT" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


