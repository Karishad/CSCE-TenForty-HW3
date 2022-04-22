/*
    CSCE 1040 Homework 3
    Section: 001
    Name: Kieron Yin
    UNT Email: kieronyin@my.unt.edu
    Date submitted: xx/xx/2022

    File name: LoansCollection.cpp
    Description:  Driver code for Collection of Loans
*/

#include "LoansCollection.h"

Loans::Loans()
{
    vector<Loan> LoanCollection;
}
int Loans::getSize()
{
    return LoanCollection.size();
}
int Loans::findLoanID(int ID)
{
    // Error checking if LoanCollection is empty to prevent errors
    if (LoanCollection.empty() == true)
        return -1;
    for (int i = 0; i < LoanCollection.size(); i++)
    {
        if (LoanCollection.at(i).getLoan_ID() == ID)
        {
            return i;
        }
    }
    return -1;
}
Loan Loans::FoundLoanID(int LoanPosition)
{
    return LoanCollection.at(LoanPosition);
}
void Loans::addLoan(Loan newLoan)
{
    LoanCollection.push_back(newLoan);
}
void Loans::editLoan(int LoanPosition, Loan newLoan)
{
    LoanCollection.at(LoanPosition) = newLoan;
}
void Loans::deleteLoan(int LoanPosition)
{
    LoanCollection.erase(LoanCollection.begin() + LoanPosition);
}
void Loans::printOneLoan(int LoanPosition)
{
    cout << "Loan ID: " << LoanCollection.at(LoanPosition).getLoan_ID() << endl;
    cout << "Book ID: " << LoanCollection.at(LoanPosition).getBook_ID() << endl;
    cout << "Patron ID: " << LoanCollection.at(LoanPosition).getPatron_ID() << endl;
    cout << "Due Date: " << LoanCollection.at(LoanPosition).getDueDate() << endl;
    cout << "Status: " << LoanCollection.at(LoanPosition).getStatus() << endl;
    cout << "Recheck: " << LoanCollection.at(LoanPosition).getRecheck() << endl;
}
void Loans::printAllLoans()
{
    if (LoanCollection.empty() == true)
        cout << "There are no Loans registered." << endl;
    else
    {
        for (int i = 0; i < LoanCollection.size(); i++)
        {
            cout << "Loan ID: " << LoanCollection.at(i).getLoan_ID() << endl;
            cout << "Book ID: " << LoanCollection.at(i).getBook_ID() << endl;
            cout << "Patron ID: " << LoanCollection.at(i).getPatron_ID() << endl;
            cout << "Due Date: " << LoanCollection.at(i).getDueDate() << endl;
            cout << "Status: " << LoanCollection.at(i).getStatus() << endl;
            cout << "Recheck: " << LoanCollection.at(i).getRecheck() << endl;
        }
    }
}