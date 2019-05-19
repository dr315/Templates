#*********************************************************************************************
# @file     Makefile
# @project  SCRS
# @platform 
# @device   
# @author   Douglas Reis
# @version  0.1
# @date     19-Fev-2018
# @brief    
#         CPU     : cm3, arm11 and etc.
#         PROFILE : debug or release
#         BOARD   : MP5, MP15, MP30...
#
# @history
#
# When         Who               What
# -----------  ----------------  -------------------------------------------------------------
# 06-Dec-2017  Douglas Reis     - Initial Version. 
# ********************************************************************************************

-include make/config.mk
-include make/$(PROFILE).mk
-include make/$(CPU).mk

OUTPUT_DIR                := ~build/$(CPU)/$(PROFILE)
OUTPUT_NAME               := $(TARGET_NAME)
MODULE_TYPE               ?= 2                           
                            
#Adding c files specific for each board
SRC_PATH                  := src

LFLAGS                    += 
                             

LFLAGS                    += 

CFLAGS                    +=
                             
                             
INC_DIRS                  += src
                                                       
CFLAGS                    += $(addprefix -I, $(INC_DIRS))


#Searching for c files to be compiled
C_FILES                   := $(shell find $(SRC_PATH) -type f -name "*.c")
OBJS                      := $(subst $(SRC_PATH),$(OUTPUT_DIR)/obj,$(C_FILES))
OBJS                      := $(OBJS:.c=.o)
DEPS                      := $(OBJS:.o=.d)

CPP_FILES                 := $(shell find $(SRC_PATH) -type f -name "*.cpp")
CPP_OBJS                  := $(subst $(SRC_PATH),$(OUTPUT_DIR)/cpp_obj,$(CPP_FILES))
CPP_OBJS                  := $(CPP_OBJS:.cpp=.o)
DEPS                      += $(CPP_OBJS:.o=.d)
                          
empty                     :=
space                     := $(empty) $(empty)

.PHONY: all static binary

all : binary 

binary: printInfo $(OUTPUT_DIR)/$(OUTPUT_NAME).exe

#Link
$(OUTPUT_DIR)/$(OUTPUT_NAME).exe : $(OBJS)	$(CPP_OBJS)
	@mkdir -p $(dir $@)
	@echo "Generating output $@..."
	$(CPP) -o $@ $^ $(LFLAGS)
	@echo "Target $@ done!"	
		
#Compile c files
$(OUTPUT_DIR)/obj/%.o : $(SRC_PATH)/%.c		
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	@$(CC) -c $(CFLAGS) $< -o $@
	
#Compile cpp files
$(OUTPUT_DIR)/cpp_obj/%.o : $(SRC_PATH)/%.cpp		
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	$(CPP) -std=c++11 -c $(CFLAGS) $< -o $@	
		
clean:
	@echo "Cleaning..."
	@rm -rf $(OUTPUT_DIR)
	@rm -rf $(OBJS)
	@echo "Done!"

printInfo:
	@printf "Starting compilation:\n"
	@printf "CPP: $(CPP)\n" 
	@printf "OBJ: $(OBJS)\n"
	@printf "SRC_DIR: $(SRC_PATH)\n"
#	@printf "Compiler Flags: $(CC) $(CC_FLAGS)\n"
#	@printf "Linker Flags: $(LD_FLAGS)\n"
#	@printf "Output Dir: $(OUTPUT_DIR)\n"
#	@printf "name: $(OUTPUT_NAME)\n"	
#	@printf "obj: $(OBJS)\n"
#	@printf "deps: $(DEPS)\n"
	@printf "\n\n"

#include dependency files auto gererated by gcc with -MMD and -MP flags in the last compilation	
-include $(DEPS)

