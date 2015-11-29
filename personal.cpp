#include "personal.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

ifstream names("names.txt");
ifstream genders("genders.txt");
ifstream births("births.txt");
ifstream deaths("deaths.txt");

using namespace std;

Personal::Personal()
{

}

Personal::addPerson()
{
    Personal peronal;

    cout << "Name: ";
    cin >> peronal.name;

    cout << "Gender: ";
    cin >> peronal.gender;

    cout << "Birth: ";
    cin >> peronal.birth;

    cout << "Death: ";
    cin >> peronal.death;

    return peronal;
}

void Personal::loadPersonal()
{

}

void loadNames()
{
    if(!names) //Test if file open
    {
        cout << "Error opening names.txt file" << endl;
        exit(0);
    }
}

void loadGenders()
{
    if(!genders) //Test if file open
    {
        cout << "Error opening genders.txt file" << endl;
        exit(0);
    }

}

void loadBirths()
{

}

void loadDeaths()
{

}
