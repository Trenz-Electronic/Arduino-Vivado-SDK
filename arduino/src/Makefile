####################################/-*-Makefile-*- 
#
# Copyright (c) 2008 Xilinx, Inc.  All rights reserved.
#
# Xilinx, Inc.
#
# XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A 
# COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
# ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR 
# STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION
# IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE 
# FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION.  
# XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO 
# THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO 
# ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE 
# FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY 
# AND FITNESS FOR A PARTICULAR PURPOSE.
# 
######################################################

COMPILER=
ARCHIVER=
CP=cp
COMPILER_FLAGS=

ifeq ($(COMPILER) , arm-xilinx-eabi-gcc)
	EXTRA_ARCHIVE_FLAGS=rc
else
	EXTRA_ARCHIVE_FLAGS=--create
endif

ifeq ($(COMPILER) , mb-gcc)
	EXTRA_ARCHIVE_FLAGS=rc
endif


RELEASEDIR=../../../lib
INCLUDEDIR=../../../include
INCLUDES=-I./include/ -I${INCLUDEDIR} 
ARDUINO_DIR = .

LIB_SRCS = $(ARDUINO_DIR)/itoa.c \
           $(ARDUINO_DIR)/wiring_digital.c \
           $(ARDUINO_DIR)/wiring.c \
           $(ARDUINO_DIR)/wmain.c

          
# create ARDUINO_SRCS based on configured options

ARDUINO_SRCS = $(LIB_SRCS)

ARDUINO_OBJS = $(ARDUINO_SRCS:%.c=%.o)
          

EXPORT_INCLUDE_FILES = $(ARDUINO_DIR)/include/Arduino.h 


			
libs: libarduino.a
	cp libarduino.a $(RELEASEDIR)
	make clean

include:
	@for i in $(EXPORT_INCLUDE_FILES); do \
	${CP} -r $$i ${INCLUDEDIR}; \
	done

clean:
	rm -rf obj/itoa.o obj/wiring.o obj/wiring_digital.o obj/wmain.o	
	rmdir obj
	rm libarduino.a


libarduino.a: obj_dir print_msg_arduino_base $(ARDUINO_OBJS)
	@echo "Creating archive $@"
	$(ARCHIVER) $(EXTRA_ARCHIVE_FLAGS) $@ obj/itoa.o obj/wiring.o obj/wiring_digital.o obj/wmain.o
	@echo "Copy include files..."
	${CP} -r $(ARDUINO_DIR)/include/Arduino.h ${INCLUDEDIR} 
	${CP} -r $(ARDUINO_DIR)/include/binary.h ${INCLUDEDIR} 
	${CP} -r $(ARDUINO_DIR)/include/registers.h ${INCLUDEDIR} 
	${CP} -r $(ARDUINO_DIR)/include/wiring.h ${INCLUDEDIR} 
	${CP} -r $(ARDUINO_DIR)/include/wiring_constants.h ${INCLUDEDIR} 
	${CP} -r $(ARDUINO_DIR)/include/wiring_analog.h ${INCLUDEDIR} 
	${CP} -r $(ARDUINO_DIR)/include/wiring_digital.h ${INCLUDEDIR} 
	${CP} -r $(ARDUINO_DIR)/include/wiring_shift.h ${INCLUDEDIR} 
	${CP} -r $(ARDUINO_DIR)/include/pins_arduino.h ${INCLUDEDIR} 
	

obj_dir:
	mkdir obj

print_msg_arduino_base:
	@echo "Compiling Arduino Library"

.c.o:
	$(COMPILER) $(COMPILER_FLAGS) $(EXTRA_COMPILER_FLAGS) $(INCLUDES) -c $< -o obj/$(@F)
