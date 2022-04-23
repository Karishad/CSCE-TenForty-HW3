#ifndef LOANSOBJECT_H
#define LOANSOBJECT_H

/*
    CSCE 1040 Homework 3
    Section: 001
    Name: Kieron Yin
    UNT Email: kieronyin@my.unt.edu
    Date submitted: 04/23/2022

    File name: LoansObject.h
    Description:  Class definition for LoansObject.cpp
    Class Parameters
        int loan, int book, int patron, time_t time, string status
    Sets/Gets for each parameter
*/
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Loan
{
public:
    Loan();
    Loan(int loan, int book, int patron, time_t time, string status, string recheck);
    void setLoan_ID(int loan);
    int getLoan_ID();
    void setBook_ID(int book);
    int getBook_ID();
    void setPatron_ID(int patron);
    int getPatron_ID();
    void setDueDate(time_t time);
    time_t getDueDate();
    void setStatus(string status);
    string getStatus();
    void setRecheck(string recheck);
    string getRecheck();

private:
    int Loan_ID;
    int Book_ID; // Will be the Book.Library_ID
    int Patron_ID;
    time_t DueDate; // Due date in 10 days
    string Status;  // Overdue/Normal
    string Recheck; // True/False (True if rechecked one, false if not)
};

#endif