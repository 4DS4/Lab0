################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../startup/startup_mk66f18.c 

C_DEPS += \
./startup/startup_mk66f18.d 

OBJS += \
./startup/startup_mk66f18.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.c startup/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MK66FN2M0VMD18 -DCPU_MK66FN2M0VMD18_cm4 -DFRDM_K66F -DFREEDOM -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\markanda\Documents\4DS4\Lab0\frdmk66f_gpio_led_output\source" -I"C:\Users\markanda\Documents\4DS4\Lab0\frdmk66f_gpio_led_output\utilities" -I"C:\Users\markanda\Documents\4DS4\Lab0\frdmk66f_gpio_led_output\drivers" -I"C:\Users\markanda\Documents\4DS4\Lab0\frdmk66f_gpio_led_output\device" -I"C:\Users\markanda\Documents\4DS4\Lab0\frdmk66f_gpio_led_output\component\uart" -I"C:\Users\markanda\Documents\4DS4\Lab0\frdmk66f_gpio_led_output\component\lists" -I"C:\Users\markanda\Documents\4DS4\Lab0\frdmk66f_gpio_led_output\CMSIS" -I"C:\Users\markanda\Documents\4DS4\Lab0\frdmk66f_gpio_led_output\board" -O0 -fno-common -g3 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-startup

clean-startup:
	-$(RM) ./startup/startup_mk66f18.d ./startup/startup_mk66f18.o

.PHONY: clean-startup

