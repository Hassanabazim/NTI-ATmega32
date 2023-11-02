################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/MDIO/MDIO_prog.c 

OBJS += \
./MCAL/MDIO/MDIO_prog.o 

C_DEPS += \
./MCAL/MDIO/MDIO_prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/MDIO/%.o: ../MCAL/MDIO/%.c MCAL/MDIO/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Projects\Config_DutyCycle\APP" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Projects\Config_DutyCycle\HAL\HKEYPAD" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Projects\Config_DutyCycle\MCAL\MDIO" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Projects\Config_DutyCycle\MCAL\MTIMER0" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Projects\Config_DutyCycle\HAL\HLCD" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Projects\Config_DutyCycle\HAL\HMOTOR" -I"D:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Projects\Config_DutyCycle\LIB" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


