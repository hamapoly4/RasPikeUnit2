mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_CXXOBJS += \
	Scenario.o \
	Scene.o \
	abstract_run.o \
	LineSearchRun.o \
	LineTraceRun.o \
	RotateRun.o \
	StraRun.o \
	JudgeMent.o \
	RotateAngleJudgeMent.o \
	RunDistJudgeMent.o \
	ColorJudgeMent.o \
	GyroSensor.o \

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif

APPL_DIRS += $(mkfile_path)Scenario $(mkfile_path)SpikeCon $(mkfile_path)JudgeMent

INCLUDES += \
	-I$(mkfile_path)Scenario \
	-I$(mkfile_path)SpikeCon \
	-I$(mkfile_path)JudgeMent \
