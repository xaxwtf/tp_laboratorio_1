################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Tp2_laboratorio\ y\ Programacion.c \
../src/arrayEmployees.c \
../src/utn.c 

OBJS += \
./src/Tp2_laboratorio\ y\ Programacion.o \
./src/arrayEmployees.o \
./src/utn.o 

C_DEPS += \
./src/Tp2_laboratorio\ y\ Programacion.d \
./src/arrayEmployees.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/Tp2_laboratorio\ y\ Programacion.o: ../src/Tp2_laboratorio\ y\ Programacion.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Tp2_laboratorio y Programacion.d" -MT"src/Tp2_laboratorio\ y\ Programacion.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


