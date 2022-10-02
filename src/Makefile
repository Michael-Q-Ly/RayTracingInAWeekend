# File 		: Makefile
# Brief 	: Compile inOneWeekend
# Author 	: Michael Ly
# Date 		: October 1, 2022

PROG       = build/Release/inOneWeekend
SRCS       = $(wildcard *.cpp)
OBJS       = $(SRCS:cpp=o)
IMAGE      = image.ppm

CXX        = g++
CXXSTD     = -std=c++17
IDIR       = -I../inc
BUILDDIR   = build
RELEASEDIR = $(BUILDDIR)/Release
CXXFLAGS   = -g -Wall -Werror $(CXXSTD) $(IDIR)

.PHONY: all
all: $(PROG)

$(PROG): $(OBJS) Makefile
	mkdir -pv $(RELEASEDIR)
	$(CXX) -o $@ $(OBJS)

$(OBJS): %.o:%.cpp Makefile
	$(CXX) -c $< $(CXXFLAGS)

.PHONY: build
build:
	./$(PROG) > $(IMAGE)

.PHONY: clean
clean:
	@rm -rf $(BUILDDIR) $(OBJS) $(IMAGE)
