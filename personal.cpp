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

}

void loadBirths()
{

}

void loadDeaths()
{

}
