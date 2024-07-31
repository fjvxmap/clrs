CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = KMP
INPUT_DIR = testcase/input
OUTPUT_DIR = testcase/output
TEST_FILES = $(wildcard $(INPUT_DIR)/*.in)

all: $(TARGET)

$(TARGET): KMP.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

test: $(TARGET)
	@echo "Running tests..."
	@all_passed=1; \
	for i in $$(seq 1 100); do \
		test_file=$(INPUT_DIR)/$$i.in; \
		expected_output=$(OUTPUT_DIR)/$$i.out; \
		actual_output=output; \
		if [ -f $$test_file ]; then \
			./$(TARGET) < $$test_file > $$actual_output; \
			if ! diff -q $$actual_output $$expected_output > /dev/null; then \
				echo "Test $$i failed."; \
				all_passed=0; \
			fi; \
		else \
			echo "Test file $$test_file not found."; \
			all_passed=0; \
		fi; \
	done; \
	if [ $$all_passed -eq 1 ]; then \
		echo "All tests passed."; \
	fi

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) output

.PHONY: all test run clean
