################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SW-EK-LM4F120XL-9453/utils/cmdline.c \
../SW-EK-LM4F120XL-9453/utils/cpu_usage.c \
../SW-EK-LM4F120XL-9453/utils/crc.c \
../SW-EK-LM4F120XL-9453/utils/flash_pb.c \
../SW-EK-LM4F120XL-9453/utils/isqrt.c \
../SW-EK-LM4F120XL-9453/utils/ringbuf.c \
../SW-EK-LM4F120XL-9453/utils/scheduler.c \
../SW-EK-LM4F120XL-9453/utils/sine.c \
../SW-EK-LM4F120XL-9453/utils/softi2c.c \
../SW-EK-LM4F120XL-9453/utils/softssi.c \
../SW-EK-LM4F120XL-9453/utils/softuart.c \
../SW-EK-LM4F120XL-9453/utils/uartstdio.c \
../SW-EK-LM4F120XL-9453/utils/ustdlib.c 

OBJS += \
./SW-EK-LM4F120XL-9453/utils/cmdline.o \
./SW-EK-LM4F120XL-9453/utils/cpu_usage.o \
./SW-EK-LM4F120XL-9453/utils/crc.o \
./SW-EK-LM4F120XL-9453/utils/flash_pb.o \
./SW-EK-LM4F120XL-9453/utils/isqrt.o \
./SW-EK-LM4F120XL-9453/utils/ringbuf.o \
./SW-EK-LM4F120XL-9453/utils/scheduler.o \
./SW-EK-LM4F120XL-9453/utils/sine.o \
./SW-EK-LM4F120XL-9453/utils/softi2c.o \
./SW-EK-LM4F120XL-9453/utils/softssi.o \
./SW-EK-LM4F120XL-9453/utils/softuart.o \
./SW-EK-LM4F120XL-9453/utils/uartstdio.o \
./SW-EK-LM4F120XL-9453/utils/ustdlib.o 

C_DEPS += \
./SW-EK-LM4F120XL-9453/utils/cmdline.d \
./SW-EK-LM4F120XL-9453/utils/cpu_usage.d \
./SW-EK-LM4F120XL-9453/utils/crc.d \
./SW-EK-LM4F120XL-9453/utils/flash_pb.d \
./SW-EK-LM4F120XL-9453/utils/isqrt.d \
./SW-EK-LM4F120XL-9453/utils/ringbuf.d \
./SW-EK-LM4F120XL-9453/utils/scheduler.d \
./SW-EK-LM4F120XL-9453/utils/sine.d \
./SW-EK-LM4F120XL-9453/utils/softi2c.d \
./SW-EK-LM4F120XL-9453/utils/softssi.d \
./SW-EK-LM4F120XL-9453/utils/softuart.d \
./SW-EK-LM4F120XL-9453/utils/uartstdio.d \
./SW-EK-LM4F120XL-9453/utils/ustdlib.d 


# Each subdirectory must supply rules for building sources it contributes
SW-EK-LM4F120XL-9453/utils/%.o: ../SW-EK-LM4F120XL-9453/utils/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -DPART_LM4F120H5QR -Dgcc -DARM_MATH_CM4 -DTARGET_IS_BLIZZARD_RA1 -I"/home/seyfullah/eclipse/LM4F120_eclipse_template_1/SW-EK-LM4F120XL-9453" -O0 -g3 -Wall -c -fmessage-length=0 -mthumb -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -ffunction-sections -fdata-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


