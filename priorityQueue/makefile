CC=g++
CFLAGS=-I.
DEPS=maxheap.h
OBJ=maxheap.o main.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
