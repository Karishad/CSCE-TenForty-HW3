#ifndef PATRONSOBJECT_H
#define PATRONSOBJECT_H

/*
    CSCE 1040 Homework 3
    Section: 001
    Name: Kieron Yin
    UNT Email: kieronyin@my.unt.edu
    Date submitted: xx/xx/2022

    File name: PatronsObject.h
    Description:  Class definition for PatronsObject.cpp
    Class Parameters
        string name, int id, float fines, int books
    Sets/Gets for each Parameter
*/
#include <iostream>
#include <string>

using namespace std;

class Patron
{
public:
    Patron();
    Patron(string name, int id, float fines, int books);
    void setName(string name);
    string getName();
    void setID(int id);
    int getID();
    void setFines(float fines);
    float getFines();
    void setBooks(int books);
    int getBooks();

private:
    string Name;
    int ID;
    float Fines;
    int Num_Books_Out; // This number cannot exceed 6
};

#endif PATRONSOBJECT_H