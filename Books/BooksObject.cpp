/*
    CSCE 1040 Homework 3
    Section: 001
    Name: Kieron Yin
    UNT Email: kieronyin@my.unt.edu
    Date submitted: 04/23/2022

    File name: BooksObject.cpp
    Description:  Driver code for Book Objects
*/

#include "BooksObject.h"

Book::Book()
{
    Author = "No Author Given";
    Title = "No Title Given";
    ISBN_number = 0;
    Library_ID = 0;
    Cost = 0.0;
    Status = "In";
};
Book::Book(string author, string title, int ISBN, int ID, float cost, string status)
{
    Author = author;
    Title = title;
    ISBN_number = ISBN;
    Library_ID = ID;
    Cost = cost;
    Status = status;
};
void Book::setAuthor(string author)
{
    Author = author;
};
string Book::getAuthor()
{
    return Author;
};
void Book::setTitle(string title)
{
    Title = title;
};
string Book::getTitle()
{
    return Title;
};
void Book::setISBN(int ISBN)
{
    ISBN_number = ISBN;
};
int Book::getISBN()
{
    return ISBN_number;
};
void Book::setID(int ID)
{
    Library_ID = ID;
};
int Book::getID()
{
    return Library_ID;
};
void Book::setCost(float cost)
{
    Cost = cost;
}
float Book::getCost()
{
    return Cost;
};
void Book::setStatus(string status)
{
    Status = status;
};
string Book::getStatus()
{
    return Status;
};