CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

TARGET = test_tree

SRC = test_tree.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)

catch_tree: catch_tree.cpp
	$(CXX) $(CXXFLAGS) -o catch_tree catch_tree.cpp