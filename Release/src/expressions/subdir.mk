################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/expressions/arithmetic_expression.cpp \
../src/expressions/binary_expression.cpp \
../src/expressions/comparison_expression.cpp \
../src/expressions/constant_expression.cpp \
../src/expressions/default_value_expression.cpp \
../src/expressions/expression.cpp \
../src/expressions/function_expression.cpp \
../src/expressions/invoke_expression.cpp \
../src/expressions/logic_expression.cpp \
../src/expressions/unary_expression.cpp \
../src/expressions/variable_expression.cpp \
../src/expressions/with_expression.cpp 

OBJS += \
./src/expressions/arithmetic_expression.o \
./src/expressions/binary_expression.o \
./src/expressions/comparison_expression.o \
./src/expressions/constant_expression.o \
./src/expressions/default_value_expression.o \
./src/expressions/expression.o \
./src/expressions/function_expression.o \
./src/expressions/invoke_expression.o \
./src/expressions/logic_expression.o \
./src/expressions/unary_expression.o \
./src/expressions/variable_expression.o \
./src/expressions/with_expression.o 

CPP_DEPS += \
./src/expressions/arithmetic_expression.d \
./src/expressions/binary_expression.d \
./src/expressions/comparison_expression.d \
./src/expressions/constant_expression.d \
./src/expressions/default_value_expression.d \
./src/expressions/expression.d \
./src/expressions/function_expression.d \
./src/expressions/invoke_expression.d \
./src/expressions/logic_expression.d \
./src/expressions/unary_expression.d \
./src/expressions/variable_expression.d \
./src/expressions/with_expression.d 


# Each subdirectory must supply rules for building sources it contributes
src/expressions/%.o: ../src/expressions/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I./ -I../src -I../src/expressions -I../src/specifiers -I../src/statements -I../src/variables -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


