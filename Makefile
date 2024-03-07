# Executable names:
EXE = peak
TEST = unit_test

# Add all object files needed for compiling:
EXE_OBJ = main.o
OBJS = main.o peak.o

# Include the master templated makefile:
include Makefile.mk
