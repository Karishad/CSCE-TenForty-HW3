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
#include <ctime>
#include <math.h>

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

// Honestly I would have put these in a separate file...but oh well
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
        // For the number of books out
        toReadLines = toReadLines.substr(posOfDelim + 1);
        posOfDelim = toReadLines.find(',');
        temp = toReadLines.substr(0, posOfDelim);
        num_books_out = stoi(temp);
        tempPatron.setBooks(num_books_out);
        // Reset delim
        Collection.addPatron(tempPatron);
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
void ReadFromLoansCSV(Loans &Collection)
{
    string fileName = "DataFiles/Loans.csv";
    // Vars to read in things
    string toReadLines;
    string temp; // Used to read in the ints and floats before type conversions
    int tempint; // Used for time_t conversion
    int loanID;
    int bookID;
    int patronID;
    time_t duedate;
    string status;
    string recheck;
    int posOfDelim = 0;
    Loan tempLoan;
    ifstream file(fileName);
    // Error handling
    if (!file.is_open())
    {
        cout << "Error, Loans.csv file failed to open...closing application." << endl;
        exit(EXIT_FAILURE);
    }
    while (getline(file, toReadLines))
    {
        // For the loanID
        posOfDelim = toReadLines.find(',');
        temp = toReadLines.substr(0, posOfDelim);
        loanID = stoi(temp);
        tempLoan.setLoan_ID(loanID);
        // For the bookID
        toReadLines = toReadLines.substr(posOfDelim + 1);
        posOfDelim = toReadLines.find(',');
        temp = toReadLines.substr(0, posOfDelim);
        bookID = stoi(temp);
        tempLoan.setBook_ID(bookID);
        // For the patronID
        toReadLines = toReadLines.substr(posOfDelim + 1);
        posOfDelim = toReadLines.find(',');
        temp = toReadLines.substr(0, posOfDelim);
        patronID = stoi(temp);
        tempLoan.setPatron_ID(patronID);
        // For the duedate
        toReadLines = toReadLines.substr(posOfDelim + 1);
        posOfDelim = toReadLines.find(',');
        temp = toReadLines.substr(0, posOfDelim);
        tempint = stoi(temp);
        duedate = tempint; // Time in seconds last unix
        tempLoan.setDueDate(duedate);
        // For the status
        toReadLines = toReadLines.substr(posOfDelim + 1);
        posOfDelim = toReadLines.find(',');
        status = toReadLines.substr(0, posOfDelim);
        tempLoan.setStatus(status);
        // For the recheck
        toReadLines = toReadLines.substr(posOfDelim + 1);
        posOfDelim = toReadLines.find(',');
        recheck = toReadLines.substr(0, posOfDelim);
        tempLoan.setRecheck(recheck);
        //  Reset delim
        Collection.addLoan(tempLoan);
        posOfDelim = 0;
    }
}
void WriteToLoansCSV(Loans &Collection)
{
    string fileName = "DataFiles/Loans.csv";
    // Vars to read in things
    Loan tempLoan;
    ofstream file(fileName);
    // Error handling
    if (!file.is_open())
    {
        cout << "Error, Loans.csv file failed to open...closing application." << endl;
        exit(EXIT_FAILURE);
    }
    while (Collection.getSize() > 0)
    {
        tempLoan = Collection.FoundLoanID(0);
        file << tempLoan.getLoan_ID() << ",";
        file << tempLoan.getBook_ID() << ",";
        file << tempLoan.getPatron_ID() << ",";
        file << tempLoan.getDueDate() << ",";
        file << tempLoan.getStatus() << ",";
        file << tempLoan.getRecheck() << ",";
        file << endl;
        Collection.deleteLoan(0);
    }
}

int main()
{
    cout << "CSCE 1040 HW3 - Kieron Yin" << endl;
    // cout << "Hello World!" << endl; -> "Hello World" indeed my friend
    // Functions as library database
    Books LibraryCollection;
    // Functions to read in the library database from the Books.csv file
    ReadFromBooksCSV(LibraryCollection);
    Patrons PatronCollection;
    ReadFromPatronsCSV(PatronCollection);
    Loans LoanCollection;
    ReadFromLoansCSV(LoanCollection);

    string userInput = "";
    /*
        Key:
        b - adds new book
        p - adds new patron
        br - removes a book
        pr - removes a patron
        out - checks out a book
        in - checks in a book
        fines - to pay fines
        over - print list of overdue books
        q - quit
        repeat if invalid input
    */
    // Creating the application loop
    Book tempBook;
    Patron tempPatron;
    Loan tempLoan;
    string tempString;
    int tempInt;
    int tempInt2;
    float tempFloat;
    while (userInput != "q")
    {
        // Display message
        cout << "\nWelcome to the library interface, enter the following keys to continue..." << endl;
        cout << "Enter 'b' to add a book.\nEnter 'p' to add a new patron." << endl;
        cout << "Enter 'br' to remove a book.\nEnter 'pr' to remove a patron." << endl;
        cout << "Enter 'out' to check out a book.\nEnter 'in' to check in a book." << endl;
        cout << "Enter 'fine' to pay a fine.\nEnter 'over' to print a list of all overdue books." << endl;
        cout << "Enter 'q' to quit." << endl;
        cin >> userInput;
        cout << "\nYou have entered: " << userInput << endl;
        if (userInput == "b")
        {
            tempString = "";
            tempInt = 0;
            tempFloat = 0.0;
            cout << "\nYou have decided to add a book." << endl;
            cout << "Enter the author of the book." << endl;
            cin.ignore();
            getline(cin, tempString);
            tempBook.setAuthor(tempString);
            cout << "Enter the title of the book." << endl;
            getline(cin, tempString);
            tempBook.setTitle(tempString);
            cout << "Enter the ISBN of the book." << endl;
            cin >> tempInt;
            tempBook.setISBN(tempInt);
            // In case there are no books present
            if (LibraryCollection.getSize() == 0)
            {
                tempBook.setID(0);
            }
            else
            {
                // BookID will be the ID of the last book in the library collection + 1
                tempInt = LibraryCollection.FoundBookID(LibraryCollection.getSize() - 1).getID() + 1;
                tempBook.setID(tempInt);
            }
            cout << "Enter the cost of the book." << endl;
            cin >> tempFloat;
            tempBook.setCost(tempFloat);
            tempBook.setStatus("In");
            LibraryCollection.addBook(tempBook);
            // Testing
            // cout << "\nBook Information:" << endl;
            // cout << tempBook.getAuthor() << tempBook.getTitle() << tempBook.getISBN() << tempBook.getID() << tempBook.getCost() << tempBook.getStatus();
        }
        else if (userInput == "p")
        {
            tempString = "";
            tempInt = 0;
            tempFloat = 0.0;
            cout << "\nYou have decided to add a patron." << endl;
            cout << "Enter the name of the patron." << endl;
            cin.ignore();
            getline(cin, tempString);
            tempPatron.setName(tempString);
            if (PatronCollection.getSize() == 0)
            {
                tempPatron.setID(0);
            }
            else
            {
                tempInt = PatronCollection.FoundPatronID(PatronCollection.getSize() - 1).getID() + 1;
                tempPatron.setID(tempInt);
            }
            tempPatron.setFines(0.0);
            tempPatron.setBooks(0);
            PatronCollection.addPatron(tempPatron);
        }
        else if (userInput == "br")
        {
            tempInt = 0;
            cout << "\nYou have decided to remove a book." << endl;
            cout << "Here is the current library:" << endl;
            LibraryCollection.printAllBooks();
            cout << "Enter the book ID to remove." << endl;
            cin >> tempInt;
            int bookPosition = LibraryCollection.findBookID(tempInt);
            if (bookPosition == -1)
            {
                cout << "This book does not exist." << endl;
            }
            else
            {
                if (LibraryCollection.FoundBookID(bookPosition).getStatus() != "In")
                {
                    cout << "This book cannot be removed since it is not 'In'" << endl;
                    continue;
                }
                cout << LibraryCollection.FoundBookID(bookPosition).getTitle() << " has been removed." << endl;
                LibraryCollection.deleteBook(bookPosition);
            }
        }
        else if (userInput == "pr")
        {
            tempInt = 0;
            cout << "\nYou have decided to remove a patron." << endl;
            cout << "Here is the current patrons:" << endl;
            PatronCollection.printAllPatrons();
            cout << "Enter the patron ID to remove." << endl;
            cin >> tempInt;
            int patronPosition = PatronCollection.findPatronID(tempInt);
            if (patronPosition == -1)
            {
                cout << "This patron does not exist." << endl;
            }
            else
            {
                cout << PatronCollection.FoundPatronID(patronPosition).getName() << " has been removed." << endl;
                PatronCollection.deletePatron(patronPosition);
            }
        }
        else if (userInput == "out")
        {
            tempInt = 0;
            tempInt2 = 0;
            int tempPatronPosition = 0;
            int tempBookPosition = 0;
            int tempLoanID;
            cout << "\nYou have decided to check out a book." << endl;
            cout << "Here is the list of Patrons." << endl;
            PatronCollection.printAllPatrons();
            cout << "Enter the patron ID that would like to check out a book." << endl;
            cin >> tempInt;
            if (PatronCollection.findPatronID(tempInt) == -1)
            {
                cout << "This patron does not exist..." << endl;
                continue;
            }
            tempPatronPosition = PatronCollection.findPatronID(tempInt);
            // Ensures that the selected patron does not have too many books out
            if (PatronCollection.FoundPatronID(tempPatronPosition).getBooks() > 5)
            {
                cout << "This patron has checked out too many books..." << endl;
                continue;
            }
            cout << "Here is the current library:" << endl;
            LibraryCollection.printAllBooks();
            cout << "What is the book that " << PatronCollection.FoundPatronID(tempPatronPosition).getName() << " will check out?" << endl;
            cin >> tempInt2;
            if (LibraryCollection.findBookID(tempInt2) == -1)
            {
                cout << "That book does not exist..." << endl;
                continue;
            }
            tempBookPosition = LibraryCollection.findBookID(tempInt2);
            if (LibraryCollection.FoundBookID(tempBookPosition).getStatus() != "In")
            {
                cout << "This current book cannot be checked out..." << endl;
                continue;
            }
            // Now we search in the loans collection to see if the patron has a overdue book
            if (LoanCollection.getSize() == 0)
            {
                // Here there are no books checked out, can create a new loan
                tempLoanID = 0; // This will be the first loan
            }
            else
                tempLoanID = LoanCollection.FoundLoanID(LoanCollection.getSize() - 1).getLoan_ID() + 1;
            time_t duedate;
            time(&duedate);    // Gets current time
            duedate += 864000; // Sets duedate for exactly 10 days from now
            tempLoan.setLoan_ID(tempLoanID);
            tempLoan.setBook_ID(tempInt2);
            tempLoan.setPatron_ID(tempInt);
            tempLoan.setDueDate(duedate);
            tempLoan.setStatus("Normal");
            tempLoan.setRecheck("False");
            // Adds to the amount the patron has checked out
            int tempBookNum = 0;
            tempBookNum = PatronCollection.FoundPatronID(tempPatronPosition).getBooks() + 1;
            Patron updatedPatron = PatronCollection.FoundPatronID(tempPatronPosition);
            updatedPatron.setBooks(tempBookNum);
            PatronCollection.editPatron(tempPatronPosition, updatedPatron);
            // Changes the status of a checked-out book to out
            Book updatedBook = LibraryCollection.FoundBookID(tempBookPosition);
            updatedBook.setStatus("Out");
            LibraryCollection.editBook(tempBookPosition, updatedBook);
            // Finally adds the new loan
            LoanCollection.addLoan(tempLoan);
        }
        else if (userInput == "in")
        {
            tempInt = 0;
            tempInt2 = 0;
            cout << "\nYou have decided to check in a book." << endl;
            cout << "Here is the list of patrons." << endl;
            PatronCollection.printAllPatrons();
            cout << "Enter the patron ID that would like to check in a book." << endl;
            cin >> tempInt;
            // Error checking
            if (PatronCollection.findPatronID(tempInt) == -1)
            {
                cout << "This is not a valid patron..." << endl;
                continue;
            }
            // This will contain the patron position
            int patronPosition;
            patronPosition = PatronCollection.findPatronID(tempInt);
            // More error checking
            if (PatronCollection.FoundPatronID(patronPosition).getBooks() == 0)
            {
                cout << "This patron has no books checked out..." << endl;
                continue;
            }
            int tempPatronID = PatronCollection.findPatronID(tempInt) + 1;
            int bookIDToGrab;
            int bookPositionToGrab;
            vector<Book> BooksOfPatron;
            for (int i = 0; i < LoanCollection.getSize(); i++)
            {
                bookIDToGrab = 0;
                bookPositionToGrab = 0;
                if (LoanCollection.FoundLoanID(i).getPatron_ID() == tempInt)
                {
                    bookIDToGrab = LoanCollection.FoundLoanID(i).getBook_ID();
                    bookPositionToGrab = LibraryCollection.findBookID(bookIDToGrab);
                    tempBook = LibraryCollection.FoundBookID(bookPositionToGrab);
                    BooksOfPatron.push_back(tempBook);
                }
            }
            cout << "Here are the books that this patron has checked out." << endl;
            for (int i = 0; i < BooksOfPatron.size(); i++)
            {
                cout << BooksOfPatron.at(i).getTitle() << " ID: " << BooksOfPatron.at(i).getID() << endl;
            }
            cout << "Enter the book ID to check in the book." << endl;
            cin >> tempInt;
            bool isFound = false;
            for (int i = 0; i < BooksOfPatron.size(); i++)
            {
                if (BooksOfPatron.at(i).getID() == tempInt)
                {
                    isFound = true;
                    // Check to see if any fines need to be applied
                    int tempLoanIDCheckIn;
                    for (int i = 0; i < LoanCollection.getSize(); i++)
                    {
                        // It has found the correct Loan
                        if (LoanCollection.FoundLoanID(i).getPatron_ID() == tempPatronID && LoanCollection.FoundLoanID(i).getBook_ID() == tempInt)
                        {
                            // Check if any fines are needed
                            time_t currentTime;
                            time(&currentTime);
                            // If overdue
                            if (currentTime > LoanCollection.FoundLoanID(i).getDueDate())
                            {
                                float timeRemainder = currentTime - LoanCollection.FoundLoanID(i).getDueDate();
                                tempFloat = ceil(timeRemainder / 86400) * 0.25; // Cost of a loan  in a 24 hour period
                                Patron FinedPatron = PatronCollection.FoundPatronID(patronPosition);
                                FinedPatron.setFines(tempFloat);
                                PatronCollection.editPatron(patronPosition, FinedPatron);
                            }
                            bookPositionToGrab = LibraryCollection.findBookID(tempInt);
                            Book FinedBook = LibraryCollection.FoundBookID(bookPositionToGrab);
                            FinedBook.setStatus("In");
                            LibraryCollection.editBook(bookPositionToGrab, FinedBook);
                            Patron FinedPatron = PatronCollection.FoundPatronID(patronPosition);
                            int newBookAmount = FinedPatron.getBooks() - 1;
                            FinedPatron.setBooks(newBookAmount);
                            PatronCollection.editPatron(patronPosition, FinedPatron);
                            LoanCollection.deleteLoan(i);
                        }
                    }
                }
            }
            if (isFound == false)
                cout << "No book with that ID found..." << endl;
        }
        else if (userInput == "fine")
        {
            //  Error handling
            if (PatronCollection.getSize() == 0)
            {
                cout << "There are no patrons..." << endl;
                continue;
            }
            tempInt = 0;
            cout << "\nYou have decided to pay a fine." << endl;
            cout << "Here is the list of patrons." << endl;
            PatronCollection.printAllPatrons();
            cout << "Enter the ID of the patron that would like to pay a fine." << endl;
            cin >> tempInt;
            if (PatronCollection.findPatronID(tempInt) == -1)
            {
                cout << "There is no patron with that ID..." << endl;
                continue;
            }
            // If no fines
            int thePatronPosition = PatronCollection.findPatronID(tempInt);
            if (PatronCollection.FoundPatronID(thePatronPosition).getFines() == 0)
            {
                cout << "This patron has no fines." << endl;
                continue;
            }
            cout << "This patron has: $" << PatronCollection.FoundPatronID(thePatronPosition).getFines() << "  in fines." << endl;
            int finePayAmount = 0;
            cout << "How much would the patron like to pay?" << endl;
            cin >> finePayAmount;
            Patron PayingPatron = PatronCollection.FoundPatronID(thePatronPosition);
            int PaymentAmount = PayingPatron.getFines();
            if (finePayAmount >= PaymentAmount)
                PayingPatron.setFines(0);
            else
            {
                PaymentAmount -= finePayAmount;
                PayingPatron.setFines(PaymentAmount);
            }
            PatronCollection.editPatron(thePatronPosition, PayingPatron);
        }
        else if (userInput == "over")
        {
            cout << "\nYou have decided to print a list of all overdue books." << endl;
            if (LoanCollection.getSize() == 0)
            {
                cout << "There are no books checkedout..." << endl;
                continue;
            }
            for (int i = 0; i < LoanCollection.getSize(); i++)
            {
                time_t currentTime;
                time(&currentTime);
                if (LoanCollection.FoundLoanID(i).getDueDate() < currentTime)
                {
                    cout << LibraryCollection.FoundBookID(LibraryCollection.findBookID(LoanCollection.FoundLoanID(i).getBook_ID())).getTitle() << " is overdue." << endl;
                }
            }
        }
        else if (userInput != "q")
        {
            cout << "\nYou have entered an invalid input, please try again..." << endl;
        }

        // break;
    }
    // We will pass in the reference simply as a way to free space when writing to the CSV's
    WriteToBooksCSV(LibraryCollection);
    WriteToPatronsCSV(PatronCollection);
    WriteToLoansCSV(LoanCollection);
    return 0;
}