CC = gcc
CFLAGS = -Wall -Wextra
SRCDIR = src/
OBJDIR = build/obj/
EXECDIR = build/executable/
SRCS = $(wildcard $(SRCDIR)*.c) $(wildcard $(SRCDIR)*/*.c)
OBJS = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))
NAME = cas
BUILD = $(EXECDIR)$(NAME)

all: $(OBJS)
	$(CC) $(OBJS) -o $(BUILD)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@