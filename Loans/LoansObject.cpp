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
    time(&DueIn2Weeks); // Currently set to current time
    DueIn2Weeks += 864000;
    DueDate = DueIn2Weeks;
    Status = "";
    Recheck = false;
};
Loan::Loan(int loan, int book, int patron, time_t time, string status, string recheck)
{
    Loan_ID = loan;
    Book_ID = book;
    Patron_ID = patron;
    DueDate = time;
    Status = status;
    Recheck = recheck;
};
void Loan::setLoan_ID(int loan)
{
    Loan_ID = loan;
};
int Loan::getLoan_ID()
{
    return Loan_ID;
};
void Loan::setBook_ID(int book)
{
    Book_ID = book;
};
int Loan::getBook_ID()
{
    return Book_ID;
};
void Loan::setPatron_ID(int patron)
{
    Patron_ID = patron;
};
int Loan::getPatron_ID()
{
    return Patron_ID;
};
void Loan::setDueDate(time_t time)
{
    DueDate = time;
};
time_t Loan::getDueDate()
{
    return DueDate;
};
void Loan::setStatus(string status)
{
    Status = status;
}
string Loan::getStatus()
{
    return Status;
}
void Loan::setRecheck(string recheck)
{
    Recheck = recheck;
}
string Loan::getRecheck()
{
    return Recheck;
}