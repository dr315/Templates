
#*********************************************************************************************
# @file     x86.mk
# @project  
# @platform 
# @device   
# @author   Douglas Reis
# @version  0.1
# @date     06-Dec-2017
# @brief    Configure the source to be use during compilation of the Project    
#
# @history
#
# When         Who               What
# -----------  ----------------  -------------------------------------------------------------
# 06-Dec-2017  Douglas Reis     - Initial Version. 
# ********************************************************************************************

CROSS_COMPILE            ?= $(CYGWIN_HOME)/bin/
export PATH              += $(CROSS_COMPILE)

CC                       := $(CROSS_COMPILE)gcc
CPP                      := $(CROSS_COMPILE)g++
AR                       := $(CROSS_COMPILE)ar
OBJCOPY                  := $(CROSS_COMPILE)objcopy
OBJDUMP                  := $(CROSS_COMPILE)objdump

LFLAGS                   += -Wl,--gc-sections

CFLAGS                   +=