/*
    CSCE 1040 Homework 3
    Section: 001
    Name: Kieron Yin
    UNT Email: kieronyin@my.unt.edu
    Date submitted: xx/xx/2022

    File name: PatronsObject.cpp
    Description:  Driver code for Patron Object
*/

#include "PatronsObject.h"

Patron::Patron()
{
    Name = "";
    ID = 000000;
    Fines = 0.0;
    Num_Books_Out = 0;
};
Patron::Patron(string name, int id, float fines, int books)
{
    Name = name;
    ID = id;
    Fines = fines;
    Num_Books_Out = books;
};
void Patron::setName(string name)
{
    Name = name;
}
string Patron::getName()
{
    return Name;
}
void Patron::setID(int id)
{
    ID = id;
}
int Patron::getID()
{
    return ID;
}
void Patron::setFines(float fines)
{
    Fines = fines;
}
float Patron::getFines()
{
    return Fines;
}
void Patron::setBooks(int books)
{
    Num_Books_Out = books;
}
int Patron::getBooks()
{
    return Num_Books_Out;
}
void Patron::payFines(float amount)
{
    if (amount > Fines)
        Fines = 0;
    Fines -= amount;
}