# CSCE 1040 Homework 3
# Section: 001
# Name: Kieron Yin
# UNT Email: kieronyin@my.unt.edu
# Date submitted: xx/xx/2022

# File name: makefile
# Description:  It's a makefile for the project 

#Compiler definition
CC = g++

HW3: main.o BooksCollection.o BooksObject.o LoansCollection.o LoansObject.o PatronsCollection.o PatronsObject.o
	$(CC) -o HW3 main.o BooksCollection.o BooksObject.o LoansCollection.o LoansObject.o PatronsCollection.o PatronsObject.o
main.o: main.cpp
	$(CC) -c main.cpp
# Woah look! Books!
BooksCollection.o: Books/BooksCollection.cpp Books/BooksCollection.h
	$(CC) -c Books/BooksCollection.cpp
BooksObject.o: Books/BooksObject.cpp Books/BooksObject.h
	$(CC) -c Books/BooksObject.cpp
# I am in student debt due to loans
LoansCollection.o: Loans/LoansCollection.cpp Loans/LoansCollection.h
	$(CC) -c Loans/LoansCollection.cpp
LoansObject.o: Loans/LoansObject.cpp Loans/LoansObject.h
	$(CC) -c Loans/LoansObject.cpp
# Patrons
PatronsCollection.o: Patrons/PatronsCollection.cpp Patrons/PatronsCollection.h
	$(CC) -c Patrons/PatronsCollection.cpp
PatronsObject.o: Patrons/PatronsObject.cpp Patrons/PatronsObject.h
	$(CC) -c Patrons/PatronsObject.cpp

clean:
	@echo "Removing Files..."
	rm -rf HW3 *.o