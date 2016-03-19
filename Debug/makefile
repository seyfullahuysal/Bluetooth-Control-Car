################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include SW-EK-LM4F120XL-9453/utils/subdir.mk
-include SW-EK-LM4F120XL-9453/driverlib/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: LM4F120_eclipse_template_1

# Tool invocations
LM4F120_eclipse_template_1: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross GCC Linker'
	arm-none-eabi-gcc -Wl,--static,--gc-sections,-T../src/LM4F.ld -mthumb -mcpu=cortex-m4 -o "LM4F120_eclipse_template_1" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) LM4F120_eclipse_template_1
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
