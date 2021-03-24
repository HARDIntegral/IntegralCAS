CC = gcc
CFLAGS = -c -Wall
SRCDIR = src/
PARSEDIR = parser/
OBJ = cas

all: $(SRCDIR)main.o $(SRCDIR)$(PARSEDIR)parser.o
	$(CC) main.o parser.o -o $(OBJ)
	@echo "BUILD COMPLETE"

%.o: %.c
	$(CC) $(CFLAGS) $^

clean:
	@echo "[Cleaning]"
	rm -rf *.exe
	rm -rf *.o

exec:
	./$(OBJ)