CXX = g++
CXXOPTS = -g -Wall -fPIC  -O2
CXXOPTS += -DNO_DEBUG_

all:
	$(CXX) $(CXXOPTS) main.cpp

clean:
	rm -f *.o a.out *.so
