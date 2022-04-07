#ifndef BOOKSOBJECT_H
#define BOOKSOBJECT_H

/*
    CSCE 1040 Homework 3
    Section: 001
    Name: Kieron Yin
    UNT Email: kieronyin@my.unt.edu
    Date submitted: xx/xx/2022

    File name: BooksObject.h
    Description:  Class definition for BooksObject.cpp
    Class parameters:
        string author, string title, int ISBN, int ID, float cost, string status
    Sets/Gets for each parameter
*/
#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
    Book();
    Book(string author, string title, int ISBN, int ID, float cost, string status);
    void setAuthor(string author);
    string getAuthor();
    void setTitle(string title);
    string getTitle();
    void setISBN(int ISBN);
    int getISBN();
    void setID(int ID);
    int getID();
    void setCost(float cost);
    float getCost();

    // Important for checking-out, checking-in, Repairing and setting-lost book
    void setStatus(string status);
    string getStatus();

private:
    string Author;
    string Title;
    int ISBN_number;
    int Library_ID;
    float Cost;
    string Status;
};

#endif