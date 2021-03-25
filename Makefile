CC = gcc
CFLAGS = -c -Wall
SRCDIR = src/
PARSEDIR = parser/
OBJ = cas

all: $(SRCDIR)main.o $(SRCDIR)$(PARSEDIR)parser.o $(SRCDIR)$(PARSEDIR)n_ary.o
	$(CC) -g main.o parser.o n_ary.o -o $(OBJ)
	@echo "BUILD COMPLETE"

%.o: %.c
	$(CC) $(CFLAGS) $^

clean:
	@echo "[Cleaning]"
	rm -rf *.exe
	rm -rf *.o