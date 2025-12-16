ifeq ($(shell command -v ccache 2>/dev/null),)
    CC  := gcc
    CXX := g++
else
    CC  := ccache gcc
    CXX := ccache g++
endif

INCPATH = -Iinclude -Isrc

CFLAGS   = -Wall -Wextra -Werror -O2
CXXFLAGS = -Wall -Wextra -Werror -O2 -std=c++11

LIB     = -lapi
LIBPATH = -Llib

LDFLAGS = -Wl,-rpath='$$ORIGIN/lib'

SRCS = src/main.cpp \
		src/Utils.cpp

TARGET = bin/demo

C_SRCS   = $(filter %.c, $(SRCS))
CPP_SRCS = $(filter %.cpp, $(SRCS))

C_OBJS   = $(C_SRCS:.c=.o)
CPP_OBJS = $(CPP_SRCS:.cpp=.o)
OBJS     = $(C_OBJS) $(CPP_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCPATH) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCPATH) -c $< -o $@

all: clean $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p bin
	$(CXX) $(OBJS) -o $@ $(LDFLAGS) $(LIBPATH) $(LIB)
	@echo Successfully generated the [$(TARGET)]!

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean
