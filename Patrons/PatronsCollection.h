#ifndef PATRONSCOLLECTION_H
#define PATRONSCOLLECTION_H

/*
    CSCE 1040 Homework 3
    Section: 001
    Name: Kieron Yin
    UNT Email: kieronyin@my.unt.edu
    Date submitted: xx/xx/2022

    File name: PatronsCollection.h
    Description:  Class definition for PatronsCollection.cpp
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "PatronsObject.h"

class Patrons
{
public:
    Patrons();
    int getSize();
    int findPatronID(int ID);                 // Will search to see if the patron exists in the database: If found return position ID, else return -1
    Patron FoundPatronID(int PatronPosition); // Run findPatronID -> DO NOT RUN IF findPatronID == -1
    void addPatron(Patron newPatron);
    void editPatron(int PatronPosition, Patron newPatron); // Run findPatronID -> DO NOT RUN IF findPatronID == -1
    void deletePatron(int PatronPosition);                 // Run findPatronID -> DO NOT RUN IF findPatronID == -1
    void printOnePatron(int PatronPosition);               // Run findPatronID -> DO NOT RUN IF findPatronID == -1
    void printAllPatrons();

private:
    vector<Patron> PatronCollection;
};

#endif