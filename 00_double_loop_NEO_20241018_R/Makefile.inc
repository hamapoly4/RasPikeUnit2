mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_CXXOBJS += \
	ScenarioTracer.o \
	Scenario.o \
	IniDevice.o \
	Scene.o \
	Run.o \
	RotRun.o \
	StraRun.o \
	LineTraceRun.o \
	ColorJudge.o \
	RotAngleJudge.o \
	RunDistJudge.o \
	Control.o \
	PConForRotRun.o \
	PDConForStraRun.o \
	PDConForLineTraceRun.o \
	ColorDetect.o \
	RunDistMeasure.o \
	GyroSensorManage.o \
	ColorSensorManage.o \
	MotorManage.o \
	ParameterManage.o \
	dbneo.o \

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif

APPL_DIRS += $(mkfile_path)ScenarioTracer $(mkfile_path)Run $(mkfile_path)Judge $(mkfile_path)Control $(mkfile_path)Detect $(mkfile_path)Manage

INCLUDES += \
	-I$(mkfile_path)ScenarioTracer \
	-I$(mkfile_path)Run \
	-I$(mkfile_path)Judge \
	-I$(mkfile_path)Control \
	-I$(mkfile_path)Detect \
	-I$(mkfile_path)Manage \
