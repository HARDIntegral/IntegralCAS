CC = gcc
CFLAGS = -c -Wall
PARSEDIR = parser/
OBJ = cas
OBJDIR = ../build/obj/
EXECDIR = build/executable/

all: main.o $(PARSEDIR)parser.o $(PARSEDIR)binary.o
	$(CC) -g main.o parser.o binary.o -o $(OBJ)
	@echo "BUILD COMPLETE"

%.o: %.c
	$(CC) $(CFLAGS) $^

exec:
	./$(OBJ).exe

clean:
	@echo "[Cleaning]"
	rm -rf *.exe
	rm -rf *.o