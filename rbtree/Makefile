CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude

TARGET = rbtree
SRCDIR = src

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
TESTCASE = testcase/input.txt

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(TARGET)
	@echo "Running tests..."
	./$(TARGET) < $(TESTCASE)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all test run clean
