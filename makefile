# CSCE 1040 Homework 3
# Section: 001
# Name: Kieron Yin
# UNT Email: kieronyin@my.unt.edu
# Date submitted: xx/xx/2022

# File name: makefile
# Description:  It's a makefile for the project 

#Compiler definition
CC = g++

HW3: main.o
	$(CC) -o HW3 main.o

main.o: main.cpp
	$(CC) -c main.cpp

clean:
	@echo "Removing Files..."
	rm -rf HW3 *.o