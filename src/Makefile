# File 		: Makefile
# Brief 	: Compile inOneWeekend
# Author 	: Michael Ly
# Date 		: October 1, 2022

PROG = build/Release/inOneWeekend
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:cpp=o)

CXX = g++
CXXSTD = -std=c++17
IDIR = -I../inc
# CXXFLAGS = -g -Wall -Werror $(CXXSTD)
CXXFLAGS = -g -Wall -Werror $(CXXSTD) $(IDIR)

.PHONY: all
all: $(PROG)

$(PROG): $(OBJS) Makefile
	$(CXX) -o $@ $(OBJS)

$(OBJS): %.o:%.cpp Makefile
	$(CXX) -c $< $(CXXFLAGS)

.PHONY: clean
clean:
	@rm -rf $(PROG) $(OBJS)
