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
    bool findBookID(int ID);  // Will search to see if the book exists in the database
    Book FoundBookID(int ID); // Will only execute if findBookID returns true
    void addBook(Book newBook);
    void editBook(Book newBook);
    void deleteBook(Book newBook);
    void printOneBook(Book newBook);
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