CC=g++
SRCS=$(wildcard src/*.cpp)
LIBS=$(wildcard src/*.h)
OBJS=$(SRCS:.cpp=.o)

%.o: %.c $(LIBS)
	$(CC) $(CFLAGS) -c -o $@ $<

scaffold: $(OBJS)
	$(CC) $(CFLAGS) -o $@.exe $(OBJS)