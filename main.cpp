/*
    CSCE 1040 Homework 3
    Section: 001
    Name: Kieron Yin
    UNT Email: kieronyin@my.unt.edu
    Date submitted: xx/xx/2022

    File name: main.cpp
    Description:  Driver code for the project
*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// Book Includes
#include "Books/BooksCollection.h"
#include "Books/BooksObject.h"
// Loan Includes
#include "Loans/LoansCollection.h"
#include "Loans/LoansObject.h"
// Patron Includes
#include "Loans/LoansCollection.h"
#include "Loans/LoansObject.h"
// DataFiles Includes
// #include "DataFiles/Books.csv"
#include "DataFiles/Loans.csv"
#include "DataFiles/Patrons.csv"

using namespace std;

void ReadFromBooksCSV(Books Collection)
{
    string fileName = "DataFiles/Books.csv";
    char delimiter = ',';
    // Vars to read in things
    string toReadStrings;
    int toReadInts;
    float toReadFloats;
    ifstream file(fileName);
    // Error handling
    if (!file.is_open())
    {
        cout << "Error, Books.csv file failed to open...closing application." << endl;
        exit(EXIT_FAILURE);
    }
}

int main()
{
    // cout << "Hello World!" << endl; -> "Hello World" indeed my friend
    // Functions as library database
    Books LibraryCollection;
    // Book bookToAdd("Jordan Brexler", "I am Grandpa Jordan", 123456, 1, 19.87, "In");
    // cout << "Author: " << bookToAdd.getAuthor() << endl;
    // LibraryCollection.addBook(bookToAdd);
    // LibraryCollection.printAllBooks();
    // Book bookToAdd2("Valibrex", "I am wearing a hoodie", 354256, 2, 0.59, "In");
    // LibraryCollection.addBook(bookToAdd2);
    // LibraryCollection.printAllBooks();

    // Creating the application loop
    while (true)
    {
        break;
    }
    return 0;
}