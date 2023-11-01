#Kevin Austin and Matthew Lannon
#date 2023-10-31
#The Makefile for compling Library

#The Compiler
CC = g++

#The Target and its Name/The exectuable Name
TARGET = test

#Debugger and Error Flags
CFLAGS = -g -Wall -Wextra

#Default target entry
all: $(TARGET)

#Rule to create executable
$(TARGET): library.o main.o
	$(CC) $(CFLAGS) -o $(TARGET) library.o main.o

#Rule for creating .o for library class
library.o: library.cpp library.h book.h
	$(CC) $(CFLAGS) -c library.cpp

#Rule for creating .o for main
main.o: main.cpp library.h
	$(CC) $(CFLAGS) -c main.cpp

#cleans the directory of excutable, .o's, and temporary files
clean:
	$(RM) $(TARGET) *.o *~
