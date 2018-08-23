
CPP = c++
CPPFLAGS = -std=c++1z -g -Wall -Wno-unused-variable
INCLUDES = -I include/ -I .
SRCS = src/main.cpp src/io.cpp src/rom.cpp
OBJS = $(SRCS:.cpp=.o)

# rename this
MAIN = rhmc

.PHONY: clean

all:    $(MAIN)
		@echo  Success!

$(MAIN): $(OBJS)
		$(CPP) $(CPPFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS)

.cpp.o:
		$(CPP) $(CPPFLAGS) $(INCLUDES) -c $<  -o $@

clean:
		$(RM) src/*.o *.txt *~ $(MAIN)

# TODO: add build dir?
