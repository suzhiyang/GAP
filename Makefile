##
# Author: Zhiyang Su
# Created on 2014-08-10.
#

CXX = g++
OPT = -g -O0
RM = rm

DEPENDENCIES = item.o bin.o knapsack.o gap.o test.o

OBJECTS = gap	# objects

%.o: %.cpp %.h
	$(CXX) $(OPT) -c -o $@ $<

%.o: %.cpp
	$(CXX) $(OPT) -c -o $@ $<

$(OBJECTS): main.cpp $(DEPENDENCIES)
	$(CXX) $(OPT) -o $@ $^

clean:
	$(RM) -rf *.o *.gch $(OBJECTS)