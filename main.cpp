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
#include "Patrons/PatronsCollection.h"
#include "Patrons/PatronsObject.h"
// DataFiles Includes -> Learned that this causes an error if included here and called from fstreams, so don't do that
// #include "DataFiles/Books.csv"
// #include "DataFiles/Loans.csv"
// #include "DataFiles/Patrons.csv"

using namespace std;

void ReadFromBooksCSV(Books &Collection)
{
    string fileName = "DataFiles/Books.csv";
    // Vars to read in things
    string toReadLines;
    string author;
    string title;
    string temp; // Used to read in the ints and floats before type conversions
    int isbn;
    int id;
    float cost;
    string status;
    int posOfDelim = 0;
    Book tempBook;
    ifstream file(fileName);
    // Error handling
    if (!file.is_open())
    {
        cout << "Error, Books.csv file failed to open...closing application." << endl;
        exit(EXIT_FAILURE);
    }
    while (getline(file, toReadLines))
    {
        // For the author
        posOfDelim = toReadLines.find(',');
        author = toReadLines.substr(0, posOfDelim);
        tempBook.setAuthor(author);
        // For the title
        toReadLines = toReadLines.substr(posOfDelim + 1);
        posOfDelim = toReadLines.find(',');
        title = toReadLines.substr(0, posOfDelim);
        tempBook.setTitle(title);
        // For the isbn
        toReadLines = toReadLines.substr(posOfDelim + 1);
        posOfDelim = toReadLines.find(',');
        temp = toReadLines.substr(0, posOfDelim);
        isbn = stoi(temp);
        tempBook.setISBN(isbn);
        // For the id
        toReadLines = toReadLines.substr(posOfDelim + 1);
        posOfDelim = toReadLines.find(',');
        temp = toReadLines.substr(0, posOfDelim);
        id = stoi(temp);
        tempBook.setID(id);
        // For the cost
        toReadLines = toReadLines.substr(posOfDelim + 1);
        posOfDelim = toReadLines.find(',');
        temp = toReadLines.substr(0, posOfDelim);
        cost = stof(temp);
        tempBook.setCost(cost);
        // For the status
        toReadLines = toReadLines.substr(posOfDelim + 1);
        posOfDelim = toReadLines.find(',');
        status = toReadLines.substr(0, posOfDelim);
        tempBook.setStatus(status);
        Collection.addBook(tempBook);
        // Reset delim
        posOfDelim = 0;
    }
}
void WriteToBooksCSV(Books &Collection)
{
    string fileName = "DataFiles/Books.csv";
    // Vars to read in things
    Book tempBook;
    ofstream file(fileName);
    // Error handling
    if (!file.is_open())
    {
        cout << "Error, Books.csv file failed to open...closing application." << endl;
        exit(EXIT_FAILURE);
    }
    while (Collection.getSize() > 0)
    {
        tempBook = Collection.FoundBookID(0);
        file << tempBook.getAuthor() << ",";
        file << tempBook.getTitle() << ",";
        file << tempBook.getISBN() << ",";
        file << tempBook.getID() << ",";
        file << tempBook.getCost() << ",";
        file << tempBook.getStatus() << ",";
        file << endl;
        Collection.deleteBook(0);
    }
}
void ReadFromPatronsCSV(Patrons &Collection)
{
    string fileName = "DataFiles/Patrons.csv";
    // Vars to read in things
    string toReadLines;
    string name;
    string temp; // Used to read in the ints and floats before type conversions
    int id;
    float fines;
    int num_books_out;
    int posOfDelim = 0;
    Patron tempPatron;
    ifstream file(fileName);
    // Error handling
    if (!file.is_open())
    {
        cout << "Error, Patrons.csv file failed to open...closing application." << endl;
        exit(EXIT_FAILURE);
    }
    while (getline(file, toReadLines))
    {
        // For the name
        posOfDelim = toReadLines.find(',');
        name = toReadLines.substr(0, posOfDelim);
        tempPatron.setName(name);
        // For the id
        toReadLines = toReadLines.substr(posOfDelim + 1);
        posOfDelim = toReadLines.find(',');
        temp = toReadLines.substr(0, posOfDelim);
        id = stoi(temp);
        tempPatron.setID(id);
        // For the fines
        toReadLines = toReadLines.substr(posOfDelim + 1);
        posOfDelim = toReadLines.find(',');
        temp = toReadLines.substr(0, posOfDelim);
        fines = stof(temp);
        tempPatron.setFines(fines);
        // For the status
        toReadLines = toReadLines.substr(posOfDelim + 1);
        posOfDelim = toReadLines.find(',');
        temp = toReadLines.substr(0, posOfDelim);
        num_books_out = stoi(temp);
        tempPatron.setBooks(num_books_out);
        // Reset delim
        posOfDelim = 0;
    }
}
void WriteToPatronsCSV(Patrons &Collection)
{
    string fileName = "DataFiles/Patrons.csv";
    // Vars to read in things
    Patron tempPatron;
    ofstream file(fileName);
    // Error handling
    if (!file.is_open())
    {
        cout << "Error, Patrons.csv file failed to open...closing application." << endl;
        exit(EXIT_FAILURE);
    }
    while (Collection.getSize() > 0)
    {
        tempPatron = Collection.FoundPatronID(0);
        file << tempPatron.getName() << ",";
        file << tempPatron.getID() << ",";
        file << tempPatron.getFines() << ",";
        file << tempPatron.getBooks() << ",";
        file << endl;
        Collection.deletePatron(0);
    }
}

int main()
{
    // cout << "Hello World!" << endl; -> "Hello World" indeed my friend
    // Functions as library database
    Books LibraryCollection;
    // Functions to read in the library database from the Books.csv file
    ReadFromBooksCSV(LibraryCollection);
    LibraryCollection.printAllBooks();
    Patrons PatronCollection;
    ReadFromPatronsCSV(PatronCollection);
    // Loans LoanCollection;
    // ReadFromLoanCollection(LoanCollection);

    // Creating the application loop
    while (true)
    {
        break;
    }
    // We will pass in the reference simply as a way to free space when writing to the CSV's
    WriteToBooksCSV(LibraryCollection);
    WriteToPatronsCSV(PatronCollection);
    // WriteToLoansCSV(LoanCollection);
    return 0;
}