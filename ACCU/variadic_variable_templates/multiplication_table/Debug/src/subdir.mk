################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/multiplication_table.cpp 

OBJS += \
./src/multiplication_table.o 

CPP_DEPS += \
./src/multiplication_table.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	/usr/local/clang36/bin/clang++ -std=c++1y -I"/Users/sop/Documents/Vortraege/EmbeddedSEKongress/2014/workspace/multiplication_table/cute" -O0 -Wall -c -fmessage-length=0 -fconstexpr-steps=100000000 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


