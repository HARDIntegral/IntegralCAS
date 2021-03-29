CC = gcc
CFLAGS = -c -Wall
PARSEDIR = parser/
INCLUDIR = includes/
OBJ = cas
OBJDIR = ../build/obj/
EXECDIR = build/executable/

all: main.o $(PARSEDIR)parser.o $(PARSEDIR)tokenizer.o $(INCLUDIR)binary.o $(INCLUDIR)parse_list.o $(INCLUDIR)stack.o
	$(CC) -g main.o tokenizer.o parser.o binary.o parse_list.o stack.o -o $(OBJ)
	@echo "BUILD COMPLETE"

%.o: %.c
	$(CC) $(CFLAGS) $^