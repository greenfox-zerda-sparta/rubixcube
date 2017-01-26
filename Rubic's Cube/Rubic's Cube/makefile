# headers := $(wildcard *.hpp)
# sources := $(wildcard *.cpp)
headers := cube.hpp
sources := Source.cpp cube.cpp
objects := $(sources:%.cpp=%.o)

all: rubixcube

rubixcube: $(objects)
	$(CXX) $^ -o $@

%.o: %.cpp $(headers)
	$(CXX) -c -o $@ $<

clean: 
	$(RM) rubixcube *.o
