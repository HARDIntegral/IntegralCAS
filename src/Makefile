CC = gcc
CFLAGS = -c -Wall
PARSEDIR = parser/
OBJ = cas

all: $(SRCDIR)main.o $(PARSEDIR)parser.o $(PARSEDIR)n_ary.o
	$(CC) -g main.o parser.o n_ary.o -o $(OBJ)
	@echo "BUILD COMPLETE"

%.o: %.c
	$(CC) $(CFLAGS) $^

exec:
	./$(OBJ).exe

clean:
	@echo "[Cleaning]"
	rm -rf *.exe
	rm -rf *.o