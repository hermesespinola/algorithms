CC=g++

EXEDIR=..
VER=-std=c++11
IDIR=../include
LDIR=../lib
ODIR=obj
CFLAGS=-I$(IDIR) -Wall

_DEPS=hashTable.cpp
_OBJ=hashTable.o main.o

DEPS=$(patsubst %, $(IDIR)/%, $(_DEPS))
OBJ=$(patsubst %, $(ODIR)/%, $(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) $(VER) -c -o $@ $< $(CFLAGS)

$(EXEDIR)/main: $(OBJ)
	$(CC) $(VER) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
