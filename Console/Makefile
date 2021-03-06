#*********************************************************************************************
# @file     
# @project  
# @platform 
# @device   
# @author   Douglas Reis
# @version  0.1
# @date     06-Feb-2019
# @brief    Configure the source to be use during compilation of the Project    
#
# @history
#
# When         Who               What
# -----------  ----------------  -------------------------------------------------------------
# 06-Feb-2019  Douglas Reis     - Initial Version. 
# ********************************************************************************************

MKFILE_DIR      := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
DIR_NAME        := $(notdir $(patsubst %/,%,$(MKFILE_DIR)))

CPU             ?= x86
PROFILE         ?= release

include  $(MKFILE_DIR)/make/functions.mk
-include $(MKFILE_DIR)/make/help.mk
include  $(MKFILE_DIR)/make/config.mk
include  $(MKFILE_DIR)/make/cpu/$(CPU).mk
include  $(MKFILE_DIR)/make/profile/$(PROFILE).mk
include  $(MKFILE_DIR)/make/dependencies.mk


SOURCE_HOME   := src

TARGET_NAME   ?= $(DIR_NAME)
BUILD_DIR     ?= ~build/$(CPU)/$(PROFILE)

# INCDIRS       += $(shell find $(SOURCE_HOME) -type d)
INCDIRS       += $(call rdwildcard,$(SOURCE_HOME)/,*)

# SRC           := $(shell find $(SOURCE_HOME) -type f -name "*.c")
SRC           := $(call rfwildcard,$(SOURCE_HOME)/,*.c)
OBJS          := $(addprefix $(BUILD_DIR)/, $(SRC))
OBJS          := $(OBJS:.c=.o)
DEPS          := $(OBJS:.o=.d)

#CPP_FILES     := $(shell find $(SRC) -type f -name "*.cpp")
CPP_FILES     := $(call rfwildcard,$(SOURCE_HOME)/,*.cpp)
CPP_OBJS      := $(addprefix $(BUILD_DIR)/, $(CPP_FILES))
#CPP_OBJS      := $(subst $(SOURCE_HOME),$(BUILD_DIR)/cpp_obj,$(CPP_FILES))
CPP_OBJS      := $(CPP_OBJS:.cpp=.o)
DEPS          += $(CPP_OBJS:.o=.d)

INCFLAGS      := $(addprefix -I, $(INCDIRS))
CFLAGS        += -Wall -Werror -fdata-sections -ffunction-sections

                          
empty                     :=
space                     := $(empty) $(empty)

PHONY: clean static binary help

static: prerequisites log $(BUILD_DIR)/lib$(TARGET_NAME).a	

binary: prerequisites log $(BUILD_DIR)/$(TARGET_NAME).exe	

#Link
$(BUILD_DIR)/$(TARGET_NAME).exe : $(CPP_OBJS) $(OBJS) 
	@mkdir -p $(dir $@)
	@echo "Generating output $@..."
	$(CPP) -o $@ $^ $(LD_FLAGS)
	@echo "Target $@ done!"	
		
#Compile c files
$(BUILD_DIR)/%.o : %.c		
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	$(CC) -c $(CFLAGS) $< -o $@ $(INCFLAGS)
	
#Compile cpp files
$(BUILD_DIR)/%.o : %.cpp		
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	$(CPP) -std=c++11 $(CFLAGS) -c $< -o $@	$(INCFLAGS)
		
clean:
	$(RM) $(BUILD_DIR)/
	
log:
	@printf "\nBuilding $(TARGET_NAME) whith the folowing setup:\n"
	@printf "CPU      : $(CPU)\n"
	@printf "PROFILE  : $(PROFILE)\n"
	@printf "CC       : $(CC)\n"
	@printf "CFLAGS   : $(CFLAGS)\n"
	@printf "INCFLAGS : $(INCFLAGS)\n\n"

prerequisites: dependenciesRequisites cpuRequisites profileRequisites
#include dependency files auto gererated by gcc with -MMD and -MP flags in the last compilation	
-include $(DEPS)

