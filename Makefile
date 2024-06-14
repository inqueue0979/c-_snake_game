CXX = g++
CXXFLAGS = -Wall -Iinclude -std=c++11
LDFLAGS = -lncurses

SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

TARGET = run

.PHONY: all clean

all: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -MMD -c -o $@ $<

-include $(DEPS)

clean:
	rm -f $(TARGET) $(OBJS) $(DEPS)
	clear
