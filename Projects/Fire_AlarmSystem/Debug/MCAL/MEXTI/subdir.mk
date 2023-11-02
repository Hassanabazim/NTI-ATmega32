################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/MEXTI/MEXTI_prog.c 

OBJS += \
./MCAL/MEXTI/MEXTI_prog.o 

C_DEPS += \
./MCAL/MEXTI/MEXTI_prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/MEXTI/%.o: ../MCAL/MEXTI/%.c MCAL/MEXTI/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Projects\Fire_AlarmSystem\LIB" -I"E:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Projects\Fire_AlarmSystem\MCAL\MDIO" -I"E:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Projects\Fire_AlarmSystem\MCAL\MEXTI" -I"E:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Projects\Fire_AlarmSystem\MCAL\MGIO" -I"E:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Projects\Fire_AlarmSystem\HAL\HBUZZ" -I"E:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Projects\Fire_AlarmSystem\HAL\HLCD" -I"E:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Projects\Fire_AlarmSystem\HAL\HLED" -I"E:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Projects\Fire_AlarmSystem\HAL\HPB" -I"E:\NTI-Embedded System\AVR Interfacing\NTI-ATmega32\Projects\Fire_AlarmSystem\APP" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


