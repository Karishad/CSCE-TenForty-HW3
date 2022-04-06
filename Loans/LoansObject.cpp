/*
    CSCE 1040 Homework 3
    Section: 001
    Name: Kieron Yin
    UNT Email: kieronyin@my.unt.edu
    Date submitted: xx/xx/2022

    File name: LoansObject.cpp
    Description:  Driver code for Loan Object
*/
#include "LoansObject.h"

Loan::Loan()
{
    Loan_ID = 0;
    Book_ID = 0;
    Patron_ID = 0;
    time_t DueIn2Weeks;
    time(&DueIn2Weeks); // Sets DueIn2Weeks to current time
    DueDate = DueIn2Weeks;
    Status = "";
}