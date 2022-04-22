#ifndef LOANSCOLLECTION_H
#define LOANSCOLLECTION_H

/*
    CSCE 1040 Homework 3
    Section: 001
    Name: Kieron Yin
    UNT Email: kieronyin@my.unt.edu
    Date submitted: xx/xx/2022

    File name: LoansCollection.h
    Description:  Class definition for LoansCollection.cpp
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "LoansObject.h"

class Loans
{
public:
    Loans();
    int getSize();
    int findLoanID(int ID);             // Will search to see if the loan exists in the database: If found return position ID, else return -1
    Loan FoundLoanID(int LoanPosition); // Run findLoanID -> DO NOT RUN IF findLoanID == -1
    void addLoan(Loan newLoan);
    void editLoan(int LoanPosition, Loan newLoan); // Run findLoanID -> DO NOT RUN IF findLoanID == -1
    void deleteLoan(int LoanPosition);             // Run findLoanID -> DO NOT RUN IF findLoanID == -1
    void printOneLoan(int LoanPostition);          // Run findLoanID -> DO NOT RUN IF findLoanID == -1
    void printAllLoans();

private:
    vector<Loan> LoanCollection;
};

#endif