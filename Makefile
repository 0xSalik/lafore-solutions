CXX = g++
CXXFLAGS = -Wall

BUILD_DIR = build

# Find all .cpp files in Chapter_* directories
SRCS := $(shell find . -type f -name "*.cpp" -path "./Chapter_*/*")

# Define targets: prefix with build/ and change extension to .o
# We strip leading ./ if find returns it
SRCS_CLEAN := $(patsubst ./%,%,$(SRCS))
TARGETS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS_CLEAN))

all: $(TARGETS)

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) $< -o $@

clean:
	@echo "Cleaning build directory..."
	@rm -rf $(BUILD_DIR)

.PHONY: all clean
