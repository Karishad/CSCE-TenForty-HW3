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
int Books::getSize()
{
    return BookCollection.size();
}
int Books::findBookID(int ID)
{
    // Error checking if BookCollection is empty to prevent errors
    if (BookCollection.empty() == true)
        return -1;
    for (int i = 0; i < BookCollection.size(); i++)
    {
        if (BookCollection.at(i).getID() == ID)
        {
            return i;
        }
    }
    return -1;
}
Book Books::FoundBookID(int BookPosition)
{
    return BookCollection.at(BookPosition);
}
void Books::addBook(Book newBook)
{
    BookCollection.push_back(newBook);
}
void Books::editBook(int BookPosition, Book newBook)
{
    BookCollection.at(BookPosition) = newBook;
}
void Books::deleteBook(int BookPosition)
{
    BookCollection.erase(BookCollection.begin() + BookPosition);
}
void Books::printOneBook(int BookPosition)
{
    cout << "Author: " << BookCollection.at(BookPosition).getAuthor() << endl;
    cout << "Title: " << BookCollection.at(BookPosition).getTitle() << endl;
    cout << "ISBN: " << BookCollection.at(BookPosition).getISBN() << endl;
    cout << "ID: " << BookCollection.at(BookPosition).getID() << endl;
    cout << "Cost: $" << BookCollection.at(BookPosition).getCost() << endl;
}
void Books::printAllBooks()
{
    if (BookCollection.empty() == true)
        cout << "There are no books registered." << endl;
    else
    {
        for (int i = 0; i < BookCollection.size(); i++)
        {
            cout << "Author: " << BookCollection.at(i).getAuthor() << endl;
            cout << "Title: " << BookCollection.at(i).getTitle() << endl;
            cout << "ISBN: " << BookCollection.at(i).getISBN() << endl;
            cout << "ID: " << BookCollection.at(i).getID() << endl;
            cout << "Cost: $" << BookCollection.at(i).getCost() << endl;
            cout << endl;
        }
    }
}