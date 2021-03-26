CC = gcc
CFLAGS = -c -Wall
PARSEDIR = parser/
OBJ = cas
OBJDIR = ../build/obj/
EXECDIR = build/executable/

all: main.o $(PARSEDIR)parser.o $(PARSEDIR)n_ary.o
	$(CC) -g main.o parser.o n_ary.o -o $(OBJ)
	mv *.o $(OBJDIR)
	mv *.exe $(EXECDIR)
	@echo "BUILD COMPLETE"

%.o: %.c
	$(CC) $(CFLAGS) $^

exec:
	./$(OBJ).exe

clean:
	@echo "[Cleaning]"
	rm -rf *.exe
	rm -rf *.o