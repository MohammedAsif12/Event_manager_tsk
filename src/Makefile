IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

BINS=../bin

_DEPS = event_manager.h event_module.h header.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = event_man.o init.o module.o
OBJ = $(patsubst %,$(BINS)/%,$(_OBJ))


$(BINS)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BINS)/event_manager: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) 

