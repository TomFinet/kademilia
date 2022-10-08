CXX=g++
#CPPFLAGS=
CXXFLAGS=-g -Wall
#LDFLAGS=

OUT=main
BUILD_DIR=./build
SRC_DIR=.

SRC=$(shell find $(SRC_DIR) -name '*.cpp')
OBJ=$(SRC:%=$(BUILD_DIR)/%.o)

base=./
node_dir=./node
server_dir=./server
dirs=$(base) $(node_dir) $(server_dir)
INC_PARAMS=$(foreach d, $(dirs), -I$d)

# final build step
$(BUILD_DIR)/$(OUT): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

# .cpp -> .o
$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(INC_PARAMS) -c $< -o $@


.PHONY: clean
clean:
	rm -r $(BUILD_DIR)