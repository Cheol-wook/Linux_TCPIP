# makefile
.SUFFIXES : .c .o

OBJECT = main.o print.o input.o
SRCS = main.c print.c input.c

CC = gcc
CFLAGS = -g
TARGET = test

$(TARGET) : $(OBJECT)
		$(CC) -o $@ $(OBJECT)

.c.o :
		$(CC) $(CFLAGS) -c $< -o $@

clean : 
	$(RM) $(OBJECT) $(TARGET) core

main.o : main.c common.h
print.o : print.c common.h
input.o : input.c common.h
