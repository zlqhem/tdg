CC := gcc
CXX := g++
CFLAGS := -I../src -I../vendor/cpputest/include -g
CFLAGS += -fpermissive -std=gnu99
LDFLAGS := -g -L../vendor/cpputest/lib -lCppUTest -lstdc++
EXE := all_tests
SRCS := all_tests.cpp tdg_test.cpp ../src/tdg.c
OBJS := $(SRCS:%.cpp=%.o)
OBJS := $(OBJS:%.c=%.o)

all: $(EXE)
	
$(EXE): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

.PHONY: clean
clean:
	-rm -rf $(OBJS) $(EXE)
