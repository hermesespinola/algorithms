CC=g++

VER=-std=c++11
IDIR=../include
LDIR=../lib
ODIR=obj
CFLAGS=-I$(IDIR)

_DEPS=maxheap.h
_OBJ=maxheap.o main.o

DEPS=$(patsubst %, $(IDIR)/%, $(_DEPS))
OBJ=$(patsubst %, $(ODIR)/%, $(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) $(VER) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) $(VER) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
