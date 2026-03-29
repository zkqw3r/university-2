CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: main test

main: main.cpp sorts.cpp
	$(CXX) $(CXXFLAGS) -o main main.cpp sorts.cpp

test: test.cpp sorts.cpp
	$(CXX) $(CXXFLAGS) -o test test.cpp sorts.cpp

run: main
	./main

run-test: test
	./test

clean:
	rm -f main test
