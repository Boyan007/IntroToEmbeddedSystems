#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile for compiling to a host device and also on a msp432 device.
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#	   <File>.i - Build <File>.i preprocessed file
#	   <File>.asm - Build <File>.asm assembly file
#	   <File>.o - Build <File>.o object file
#	   compile-all - Builds object files from all source files (but doesn't link them)
#	   Build - Builds and links all source files
#	   Clean - Removes all generated files
#
# Platform Overrides:
#      <Put a description of the supported Overrides here>
#	   CPU - Intel(host) and ARM Cortex Architecture(cortex-m4)
#	   ARCH - x86_64 and Arm architecture(arm, thumb)
#	   SPECS - Specs file to give the linker (nosys.specs)
#
#------------------------------------------------------------------------------
include sources.mk

## Platform Overrides
PLATFORM = HOST
#PLATFORM = MSP432


## Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
#CPU = cortex-m4
#ARCH = $(shell arch)
#SPECS = 

ifeq ($(PLATFORM), HOST)
	CC = gcc
	LD = gcc -o
	CFLAGS = -Wall -std=c11 -O0 -c
	LDFLAGS = -Wl,-Map=$(PLATFORM).map
	CPPFLAGS = -DHOST
else
	INCLUDES:=$(INCLUDES) -Iinclude/CMSIS
	INCLUDES+= -Iinclude/msp432
	SOURCES += src/system_msp432p401r.c src/interrupts_msp432p401r_gcc.c src/startup_msp432p401r_gcc.c
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld -o
	CFLAGS = -std=c99 -mcpu=cortex-m4 -mthumb -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs -O0 -c
	LDFLAGS = -T$(LINKER_FILE) -Map=$(PLATFORM).map --wrap=malloc --wrap=free
	CPPFLAGS = -DMSP432
	#in this case, we need to create object files ALSO for the .c files that have no headers
endif

## Compiler Flags and Defines
#CC = compiler
#LD =  linker
#LDFLAGS = linker flags usually -lm
#CFLAGS compiler flags
#CPPFLAGS = preprocessor flags

OBJS := $(SOURCES:.c=.o)
OBJLOC := obj/

%.i : %.c
	$(CC) $(CPPFLAGS) -E -o $@ $< -I$(INCLUDES) $(CPPFLAGS)

%.asm : %.c
	$(CC) $(CPPFLAGS) -S -o $@ $< -I$(INCLUDES) $(CPPFLAGS)

%.o : %.c
	$(CC) $(CPPFLAGS) -I$(INCLUDES) $(CFLAGS) $< -o $@


.PHONY: compile-all
compile-all : $(OBJS)
	$(CC) $(CPPFLAGS) -I$(INCLUDES) $(CFLAGS) $(SOURCES)

.PHONY: Build
Build : compile-all
	$(LD) final.out $(OBJS) -DCOURSE1 $(LDFLAGS)

.PHONY: Build-all
Build-all : compile-all
	$(LD) final.out $(SOURCES) $(CPPFLAGS) -DCOURSE1 -DVERBOSE -I$(INCLUDES)
	mkdir $(OBJLOC)
	mv *.o $(OBJLOC)
	rm src/*.o


.PHONY: clean
Clean :
	rm *.out
	rm -rf $(OBJLOC)