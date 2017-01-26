################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Camera.cpp \
../Cube_drawer.cpp \
../Opengl.cpp \
../Source.cpp \
../User_input.cpp \
../cube.cpp \
../main.cpp 

OBJS += \
./Camera.o \
./Cube_drawer.o \
./Opengl.o \
./Source.o \
./User_input.o \
./cube.o \
./main.o 

CPP_DEPS += \
./Camera.d \
./Cube_drawer.d \
./Opengl.d \
./Source.d \
./User_input.d \
./cube.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -D__FERI -O2 -g -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


