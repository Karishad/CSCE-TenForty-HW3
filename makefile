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
# Setting files to one directory for testing
#BooksSource = $(wildcard Books/*.cpp)
#BooksObject = $(notdir $(BooksSource:.cpp=.o))
#LoansSource = $(wildcard Loans/*.cpp)
#LoansObject = $(notdir $(BooksSource:.cpp=.o))

HW3: main.o books.o loans.o
	$(CC) -o HW3 main.o books.o loans.o
main.o: main.cpp
	$(CC) -c main.cpp
#books.o: $(BooksSource)
#	$(CC) -c $(BooksSource)
#loans.o: $(LoansSource)
#	$(CC) -c $(LoansSource)

#bookhelp:
#	@echo "BookDirectory: $(BooksSource)"
#	@echo "LoansDirectory $(LoansSource)"
#	@echo "ObjectCreation: $(BooksObject) $(LoansObject)"

clean:
	@echo "Removing Files..."
	rm -rf HW3 *.o