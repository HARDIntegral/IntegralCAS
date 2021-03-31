CC = gcc
CFLAGS = -g -Wall
SRCDIR = src/
OBJDIR = build/obj/
EXECDIR = build/executable/
SRCS = $(wildcard $(SRCDIR)*.c) $(wildcard $(SRCDIR)*/*.c)
OBJS = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS)) $(patsubst $(SRCDIR)*/%.c, $(OBJDIR)*/%.o, $(SRCS))
NAME = cas
BUILD = $(EXECDIR)$(NAME)

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $@ -o $<