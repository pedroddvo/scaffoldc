CC=g++
SRCS=$(wildcard src/*.cpp) $(wildcard src/lang/*.cpp)
LIBS=$(wildcard src/*.h)   $(wildcard src/lang/*.h)
OBJS=$(SRCS:.cpp=.o)

%.o: %.cpp $(LIBS)
	$(CC) $(CFLAGS) -c -o $@ $<

scaffold: $(OBJS)
	$(CC) $(CFLAGS) -o $@.exe $(OBJS)