
OBJS_DIR = .objs
CXX = g++
LD = g++
STDVERSION = -std=c++20
WARNINGS = -pedantic -Wall -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable
CXXFLAGS = $(STDVERSION) -g -O0 $(WARNINGS) -MMD -MP -msse2 -c
LDFLAGS = $(STDVERSION)

# Test files
OBJS_TEST = $(filter-out $(EXE_OBJ), $(OBJS))
CPP_TEST = $(wildcard tests/*.cpp)
OBJS_TEST += $(CPP_TEST:.cpp=.o)

#  Rules for first executable
$(EXE):
	$(LD) $^ $(LDFLAGS) -o $@

# Rules for executables
$(TEST):
	$(LD) $^ $(LDFLAGS) -o $@
	@echo ""
	@echo " Built the test program: " $(TEST)
	@echo ""

all: $(EXE) $(TEST)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)/tests

$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

# Executable dependencies
$(EXE): $(patsubst %.o, $(OBJS_DIR)/%.o, $(OBJS))
$(TEST): $(patsubst %.o, $(OBJS_DIR)/%.o, $(OBJS_TEST))

# Include automatically generated dependencies
-include $(OBJS_DIR)/*.d
-include $(OBJS_DIR)/tests/*.d

install: $(EXE)
	echo "Install peak program in Linux environment"
	install -m 755 $(EXE) /usr/local/bin

uninstall:
	rm -rf /usr/local/bin/$(EXE)

clean:
	rm -rf $(EXE) $(TEST) $(OBJS_DIR) $(CLEAN_RM) $(ZIP_FILE)
