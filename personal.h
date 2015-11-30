#ifndef PERSONAL_H
#define PERSONAL_H

#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Personal
{
public:
    Personal();
    void loadPersonal();                                                     //Loads input from files into vector
    void loadNames();                                                        //Loads names.txt into name vector
    void loadGenders();                                                      //Loads genders.txt into gender vector
    void loadBirths();                                                       //Loads births.txt into birth vector
    void loadDeaths();                                                       //Loads deaths.txt into death vector

    void diplayPersonal();                                                   //Displays the list of people

    void addPersonal();                                                      //Adds new person to the list
    void pushNewPersonal(string nam, string sex, string birt, string deat);  //Pushes new person into vectors

    void findbyname(string input_name);                                      // Search for a specific name
    void findbygender(string input_gender);                                  // Search for a specific gender
    void findbybirthyear(string input_byear);                                // Search for a specific birth year
    void findbydeathyear(string input_dyear);                                // Search for a specific dearh year

    void writePersonal();                                                    //Writes all vectors into text files
    void writeNames();                                                       //Writes name vector into names.txt
    void writeGenders();                                                     //Writes gender vector into genders.txt
    void writeBirths();                                                      //Writes births vector into births.txt
    void writeDeaths();                                                      //Writes deaths vector into deaths.txt

private:
    vector<string> name;
    vector<string> gender;
    vector<string> birth;
    vector<string> death;
};

#endif // PERSONAL_H
