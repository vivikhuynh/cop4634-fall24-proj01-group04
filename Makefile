CXX = g++
CXXFLAGS = -Wall -std=c++11
OBJS = myshell.o parse.o param.o
TARGET = myshell

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

myshell.o: myshell.cpp param.hpp parse.hpp
	$(CXX) $(CXXFLAGS) -c myshell.cpp

parse.o: parse.cpp param.hpp parse.hpp
	$(CXX) $(CXXFLAGS) -c parse.cpp

param.o: param.cpp param.hpp
	$(CXX) $(CXXFLAGS) -c param.cpp

clean:
	rm -f $(OBJS) $(TARGET)
