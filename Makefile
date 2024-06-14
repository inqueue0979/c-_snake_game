CXX = g++
CXXFLAGS = -Wall -Iinclude -lncurses

SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

TARGET = run

.PHONY: all clean run

all: $(TARGET) run

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -MMD -c -o $@ $<

-include $(DEPS)

clean:
	rm -f $(TARGET) $(OBJS) $(DEPS)
	clear

run: $(TARGET)
	./$(TARGET)
