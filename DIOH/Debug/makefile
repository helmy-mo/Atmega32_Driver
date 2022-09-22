################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
DIOH.lss \

FLASH_IMAGE += \
DIOH.hex \

EEPROM_IMAGE += \
DIOH.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: DIOH.elf secondary-outputs

# Tool invocations
DIOH.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,DIOH.map -mmcu=atmega32 -o "DIOH.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

DIOH.lss: DIOH.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S DIOH.elf  >"DIOH.lss"
	@echo 'Finished building: $@'
	@echo ' '

DIOH.hex: DIOH.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex DIOH.elf  "DIOH.hex"
	@echo 'Finished building: $@'
	@echo ' '

DIOH.eep: DIOH.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex DIOH.elf  "DIOH.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: DIOH.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 DIOH.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) DIOH.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
