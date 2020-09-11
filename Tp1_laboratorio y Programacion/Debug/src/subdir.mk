################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Tp1_laboratorio\ y\ Programacion.c \
../src/operaciones.c \
../src/utn.c 

OBJS += \
./src/Tp1_laboratorio\ y\ Programacion.o \
./src/operaciones.o \
./src/utn.o 

C_DEPS += \
./src/Tp1_laboratorio\ y\ Programacion.d \
./src/operaciones.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/Tp1_laboratorio\ y\ Programacion.o: ../src/Tp1_laboratorio\ y\ Programacion.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Tp1_laboratorio y Programacion.d" -MT"src/Tp1_laboratorio\ y\ Programacion.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


