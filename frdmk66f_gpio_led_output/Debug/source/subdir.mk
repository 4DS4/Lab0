################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Problem4.c \
../source/semihost_hardfault.c 

C_DEPS += \
./source/Problem4.d \
./source/semihost_hardfault.d 

OBJS += \
./source/Problem4.o \
./source/semihost_hardfault.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MK66FN2M0VMD18 -DCPU_MK66FN2M0VMD18_cm4 -DFRDM_K66F -DFREEDOM -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\markanda\Documents\4DS4\Lab0\frdmk66f_gpio_led_output\source" -I"C:\Users\markanda\Documents\4DS4\Lab0\frdmk66f_gpio_led_output\utilities" -I"C:\Users\markanda\Documents\4DS4\Lab0\frdmk66f_gpio_led_output\drivers" -I"C:\Users\markanda\Documents\4DS4\Lab0\frdmk66f_gpio_led_output\device" -I"C:\Users\markanda\Documents\4DS4\Lab0\frdmk66f_gpio_led_output\component\uart" -I"C:\Users\markanda\Documents\4DS4\Lab0\frdmk66f_gpio_led_output\component\lists" -I"C:\Users\markanda\Documents\4DS4\Lab0\frdmk66f_gpio_led_output\CMSIS" -I"C:\Users\markanda\Documents\4DS4\Lab0\frdmk66f_gpio_led_output\board" -O0 -fno-common -g3 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/Problem4.d ./source/Problem4.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o

.PHONY: clean-source

