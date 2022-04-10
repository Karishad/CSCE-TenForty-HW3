# CSCE 1040 Homework 3
# Section: 001
# Name: Kieron Yin
# UNT Email: kieronyin@my.unt.edu
# Date submitted: xx/xx/2022

# File name: makefile
# Description:  It's a makefile for the project 

#Compiler definition
CC = g++

# Setting up Sources
BooksSource = $(wildcard Books/*.cpp)
BooksObject = $(notdir $(BooksSource:.cpp=.o))

HW3: main.o books.o
	$(CC) -o HW3 main.o books.o
main.o: main.cpp
	$(CC) -c main.cpp
books.o: $(BooksSource)
	$(CC) -c $(BooksSource)

bookhelp:
	@echo "BookDirectory: $(BooksSource)"
	@echo "ObjectCreation: $(BooksObject)"

clean:
	@echo "Removing Files..."
	rm -rf HW3 *.o