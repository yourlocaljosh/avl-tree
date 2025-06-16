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

#For catch2 tests
test_avl: catch_tests.cpp
	$(CXX) $(CXXFLAGS) -o catch_tests catch_tests.cpp