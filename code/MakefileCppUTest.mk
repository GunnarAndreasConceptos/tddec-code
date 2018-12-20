#This makefile makes all the main book code with CppUTest test harness

#Set this to @ to keep the makefile quiet
SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = BookCode_CppUTest

#--- Inputs ----#
#CPPUTEST_HOME = CppUTest
CPP_PLATFORM = Gcc
PROJECT_HOME_DIR = .

SRC_DIRS = \
	src/HomeAutomation \
	src/util\
	src/LedDriver \
	src/dvr\
	src/IO \
	src/MyOS \
	src/MyOS/posix \
	src/zune \
	src/MyHomeAutomation \


#TEST_SRC_DIRS = \
	.\
	mocks\
	mocks\
	tests/LedDriver\
	tests/stdio\
	tests/util\
	tests/IO\
	tests/zune\
	tests/HomeAutomation\
	tests/dvr\
	tests\
	tests/MyOS\
	tests/MyHomeAutomation \

TEST_SRC_DIRS = \
	tests\
	tests/MyHomeAutomation \

	
INCLUDE_DIRS =\
  .\
  $(CPPUTEST_HOME)/include\
  include/IO\
  mocks\
  include/util\
  include/HomeAutomation\
  include/LedDriver\
  include/MyOS\
  include/dvr\
  include/zune\
	include/MyHomeAutomation\

MOCKS_SRC_DIRS = \
	mocks\

include ../CppUTestCompileFlags.mk

LD_LIBRARIES = -lpthread
	
  
include $(CPPUTEST_HOME)/build/MakefileWorker.mk

