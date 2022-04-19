/*
    CSCE 1040 Homework 3
    Section: 001
    Name: Kieron Yin
    UNT Email: kieronyin@my.unt.edu
    Date submitted: xx/xx/2022

    File name: BooksCollection.cpp
    Description:  Driver code for Collection of Books
*/

#include "BooksCollection.h"
#include "BooksObject.h"

Books::Books()
{
    vector<Book> BookCollection;
};
bool Books::findBookID(int ID)
{
    // Error checking if BookCollection is empty to prevent errors
    if (BookCollection.empty() == true)
        return false;
    for (int i = 0; i < BookCollection.size(); i++)
    {
        if (BookCollection.at(i).getID() == ID)
        {
            return true;
        }
    }
    return false;
}