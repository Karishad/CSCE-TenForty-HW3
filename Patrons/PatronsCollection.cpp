/*
    CSCE 1040 Homework 3
    Section: 001
    Name: Kieron Yin
    UNT Email: kieronyin@my.unt.edu
    Date submitted: 04/23/2022

    File name: PatronsCollection.cpp
    Description:  Driver code for Collection of Patrons
*/

#include "PatronsCollection.h"

Patrons::Patrons()
{
    vector<Patron> PatronCollection;
}
int Patrons::getSize()
{
    return PatronCollection.size();
}
int Patrons::findPatronID(int ID)
{
    // Error checking if PatronCollection is empty to prevent errors
    if (PatronCollection.empty() == true)
        return -1;
    for (int i = 0; i < PatronCollection.size(); i++)
    {
        if (PatronCollection.at(i).getID() == ID)
        {
            return i;
        }
    }
    return -1;
}
Patron Patrons::FoundPatronID(int PatronPosition)
{
    return PatronCollection.at(PatronPosition);
}
void Patrons::addPatron(Patron newPatron)
{
    PatronCollection.push_back(newPatron);
}
void Patrons::editPatron(int PatronPosition, Patron newPatron)
{
    PatronCollection.at(PatronPosition) = newPatron;
}
void Patrons::deletePatron(int PatronPosition)
{
    PatronCollection.erase(PatronCollection.begin() + PatronPosition);
}
void Patrons::printOnePatron(int PatronPosition)
{
    cout << "Name: " << PatronCollection.at(PatronPosition).getName() << endl;
    cout << "ID: " << PatronCollection.at(PatronPosition).getID() << endl;
    cout << "Fines: $" << PatronCollection.at(PatronPosition).getFines() << endl;
    cout << "Number of Books Out: " << PatronCollection.at(PatronPosition).getBooks() << endl;
}
void Patrons::printAllPatrons()
{
    if (PatronCollection.empty() == true)
        cout << "There are no Patrons registered." << endl;
    else
    {
        for (int i = 0; i < PatronCollection.size(); i++)
        {
            cout << "Name: " << PatronCollection.at(i).getName() << endl;
            cout << "ID: " << PatronCollection.at(i).getID() << endl;
            cout << "Fines: $" << PatronCollection.at(i).getFines() << endl;
            cout << "Number of Books Out: " << PatronCollection.at(i).getBooks() << endl;
            cout << endl;
        }
    }
}