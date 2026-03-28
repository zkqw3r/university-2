CXX = g++
CXXFLAGS = -std=c++17 

all: simpson test

simpson: main.cpp functions.cpp
	$(CXX) $(CXXFLAGS) -o simpson main.cpp functions.cpp

test: test.cpp functions.cpp
	$(CXX) $(CXXFLAGS) -o test test.cpp functions.cpp
	./test
