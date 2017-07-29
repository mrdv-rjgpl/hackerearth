#
# @brief: Makefile for all executables (compiled from single files)
#
cpp_file_names = $(shell find . -name \*.cpp)
exe_file_names = $(patsubst %.cpp,%.exe,$(cpp_file_names))

all: $(exe_file_names)
	@echo "Make successful"

%.exe: %.cpp
	g++ -g -o $(@) $(<)

.PHONY: clean

clean:
	rm $(exe_file_names)
