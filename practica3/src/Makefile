# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread

# All tests produced by this Makefile.  Remember to add new tests you
# created to the list.
MAKE = test

# House-keeping build targets.

all : $(MAKE)
	rm -f *.o

# Builds gtest.a and gtest_main.a.

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
SRCS = *.cpp *.hpp

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
city.o : $(SRCS)
	$(CXX) $(CXXFLAGS) -c city.cpp

test.o : $(SRCS)
	$(CXX) $(CXXFLAGS) -c test.cpp

# Builds a sample test.

city.o : city.cpp city.hpp

test.o : test.cpp traveling_salesman_greedy_algorithm.hpp graph_utils.hpp graph.hpp

test : test.o city.o
	$(CXX) $(CXXFLAGS) $^ -o $@
