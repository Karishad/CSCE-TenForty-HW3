#ifndef BOOKSCOLLECTION_H
#define BOOKSCOLLECTION_H

/*
    CSCE 1040 Homework 3
    Section: 001
    Name: Kieron Yin
    UNT Email: kieronyin@my.unt.edu
    Date submitted: xx/xx/2022

    File name: BooksCollection.h
    Description:  Class definition for BooksCollection.cpp
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "BooksObject.h"

class Books
{
public:
    Books();
    int findBookID(int ID);             // Will search to see if the book exists in the database: If found return position ID, else return -1
    Book FoundBookID(int BookPosition); // Run findBookID -> DO NOT RUN IF findBookID == -1
    void addBook(Book newBook);
    void editBook(int BookPosition, Book newBook); // Run findBookID -> DO NOT RUN IF findBookID == -1
    void deleteBook(int BookPosition);             // Run findBookID -> DO NOT RUN IF findBookID == -1
    void printOneBook(int BookPosition);           // Run findBookID -> DO NOT RUN IF findBookID == -1
    void printAllBooks();

private:
    vector<Book> BookCollection;
    // These will be commented out unless needed
    // assuming that what we will have is the book ID's
    // Book findBookTitle(string title);
    // Book findBookAuthor(string author);
    // Book findBookISBN(int ISBN);
};

#endif