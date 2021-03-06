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
    void addBook(Book newBook);
    void editBook(Book newBook);
    void deleteBook(Book newBook);
    void printOneBook(Book newBook);
    void printAllBooks();

private:
    vector<Book> BookCollection;
    Book findBookTitle(string title);
    Book findBookAuthor(string author);
    Book findBookISBN(int ISBN);
    Book findBookID(int ID);
};

#endif