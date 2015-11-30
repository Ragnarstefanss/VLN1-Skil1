#include "personal.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;



Personal::Personal()
{
    vector<string> name;
    vector<string> gender;
    vector<string> birth;
    vector<string> death;
}

void Personal::loadPersonal()
{
    loadNames();
    loadGenders();
    loadBirths();
    loadDeaths();
}

void Personal::writePersonal()
{
    writeNames();
    writeGenders();
    writeBirths();
    writeDeaths();
}


void Personal::addPersonal()
{
    string name, sex, birth, death;
    char c;


    NAME_LOOP:
    cout << "Enter the name of the person you wish to add: ";
    getline(cin, name);
    if(name == "")
    {
        cout << "No entry found!" << endl;
        cout << "Try again!" << endl << endl;
        goto NAME_LOOP;
    }
    for (unsigned int i = 0; i < name.length(); i++)
    {
        c = name.at(i);
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == ' '))
        {
                   //Right input
        }
        else
        {
            cout << "Only alphabetic letters and spaces allowed!" << endl;
            cout << "Try again!" << endl << endl;
            goto NAME_LOOP;
        }
    }
    cout << endl;


    SEX_LOOP:
    cout << "Enter the gender: ";
    getline(cin, sex);
    while (sex == "")
    {
        cout << "No entry found!" << endl;
        cout << "Try again!" << endl << endl;
        goto SEX_LOOP;
    }
    while((sex != "Male") && (sex != "male") && (sex != "Female") && (sex != "female"))
    {
        cout << "Wrong input! Enter either male or female, no transsexuals allowed!" << endl;
        cout << "Try again!" << endl << endl;
        goto SEX_LOOP;
    }
    cout << endl;


    BIRTH_LOOP:
    cout << "Enter the year of birth: ";
    getline(cin, birth);
    while (birth == "")
    {
        cout << "No entry found!" << endl;
        cout << "Try again!" << endl << endl;
        goto BIRTH_LOOP;
    }
    if(birth.length() == 4)
    {
        for (unsigned int i = 0; i < birth.length(); i++)
        {
            c = birth.at(i);
            if ((c >= '0' && c <= '9'))
            {
                       //Right input
            }
            else
            {
                cout << "Wrong year input!" << endl;
                cout << "Input a year containing exactly four numbers!" << endl << endl;
                goto BIRTH_LOOP;
            }
        }
    }
    else
    {
        cout << "Wrong year input!" << endl;
        cout << "Input a year containing exactly four numbers!" << endl << endl;
        goto BIRTH_LOOP;
    }
    cout << endl;

    DEATH_LOOP:
    cout << "Enter the year of death (if person is alive enter a '-' instead): ";
    getline(cin, death);
    while (death == "")
    {
        cout << "No entry found!" << endl;
        cout << "Try again!" << endl << endl;
        goto DEATH_LOOP;
    }
    if(death.length() == 4)
    {
        for (unsigned int i = 0; i < death.length(); i++)
        {
            c = death.at(i);
            if ((c >= '0' && c <= '9'))
            {
                       //Right input
            }
            else
            {
                cout << "Wrong year input!" << endl;
                cout << "Input a year containing exactly four numbers or a '-' "
                        "if the person is alive" << endl << endl;
                goto DEATH_LOOP;
            }
        }
    }
    else if(death == "-")
    {
        //Right input
    }
    else
    {
        cout << "Wrong year input!" << endl;
        cout << "Input a year containing exactly four numbers or a '-' "
                "if the person is alive" << endl << endl;
        goto DEATH_LOOP;
    }
    cout << endl;

    pushNewPersonal(name, sex, birth, death);           //Pushes collected data to vectors
    writePersonal();                                    //Writes new vectors to text files
}

void Personal::pushNewPersonal(string nam, string sex, string birt, string deat)
{
    name.push_back(nam);
    gender.push_back(sex);
    birth.push_back(birt);
    death.push_back(deat);
}

void Personal::diplayPersonal()
{
    if(name.size() == 0)
    {
        cout << "No people to display!" << endl;
    }
    else
    {
        cout << "List of famous people: " << endl << endl;
        for(unsigned int i = 0; i < name.size();i++)
        {
            cout << "Name: " << name[i] << endl
                 << "Sex: " << gender[i] << endl
                 << "Born: " << birth[i] << endl
                 << "Died: " << death[i] << endl << endl;
        }
    }
}

void Personal::writeNames()
{
    ofstream writeNames("names.txt");
    if (writeNames.is_open())
    {
        for(unsigned int i = 0; i < name.size(); i++)
        {
            writeNames << name[i] << "\n";
        }
    writeNames.close();
    }
}

void Personal::writeGenders()
{
    ofstream writeGenders("genders.txt");
    if (writeGenders.is_open())
    {
        for(unsigned int i = 0; i < gender.size(); i++)
        {
            writeGenders << gender[i] << "\n";
        }
    writeGenders.close();
    }
}

void Personal::writeBirths()
{
    ofstream writeBirths("births.txt");
    if (writeBirths.is_open())
    {
        for(unsigned int i = 0; i < birth.size(); i++)
        {
            writeBirths << birth[i] << "\n";
        }
    writeBirths.close();
    }
}

void Personal::writeDeaths()
{
    ofstream writeDeaths("deaths.txt");
    if (writeDeaths.is_open())
    {
        for(unsigned int i = 0; i < death.size(); i++)
        {
            writeDeaths << death[i] << "\n";
        }
    writeDeaths.close();
    }
}

void Personal::loadNames()
{
    ifstream readNames("names.txt");
    string line;
    if(!readNames) //Tests if file open
    {
        cout << "Error opening names.txt file" << endl;
        exit(0);
    }

    while (getline(readNames, line))
    {
        name.push_back(line);
    }
}

void Personal::loadGenders()
{
    ifstream readGenders("genders.txt");
    string line;
    if(!readGenders) //Tests if file open
    {
        cout << "Error opening genders.txt file" << endl;
        exit(0);
    }

    while (getline(readGenders, line))
    {
        gender.push_back(line);
    }

}

void Personal::loadBirths()
{
    ifstream readBirths("births.txt");
    string line;
    if(!readBirths) //Test if file open
    {
        cout << "Error opening births.txt file" << endl;
        exit(0);
    }

    while (getline(readBirths, line))
    {
        birth.push_back(line);
    }
}

void Personal::loadDeaths()
{
    ifstream readDeaths("deaths.txt");
    string line;
    if(!readDeaths) //Test if file open
    {
        cout << "Error opening deaths.txt file" << endl;
        exit(0);
    }

    while (getline(readDeaths, line))
    {
        death.push_back(line);
    }
}

void Personal::findbyname(string input_name)
{
    bool name_found = false;
    if(name.size() == 0)
    {
        cout << "No person matched that search string!" << endl << endl;
    }
    else
    {

        for(unsigned int i = 0; i < name.size();i++)
        {
            if(input_name == name[i])
            {
               cout << "Name: " << name[i] << endl
                    << "Sex: " << gender[i] << endl
                    << "Born: " << birth[i] << endl
                    << "Died: " << death[i] << endl << endl;
                name_found = true;
            }
        }

        if(name_found == 0)
        {
            cout << "Person does not exist" << endl << endl;
        }

     }
}

void Personal::findbygender(string input_gender)
{
    bool gender_found = false;
    if(gender.size() == 0)
    {
        cout << "No person matched that search string!" << endl << endl;
    }
    else
    {
        for(unsigned int i = 0; i < gender.size();i++)
        {
            if(input_gender == gender[i])
            {
               cout << "Name: " << name[i] << endl
                    << "Sex: " << gender[i] << endl
                    << "Born: " << birth[i] << endl
                    << "Died: " << death[i] << endl << endl;
               gender_found = true;
            }
        }

        if(gender_found == false)
        {
            cout << "Person does not exist" << endl << endl;
        }

     }
}


void Personal::findbybirthyear(string input_byear)
{
    bool byear_found = false;
    if(birth.size() == 0)
    {
        cout << "No person matched that search string!" << endl << endl;
    }
    else
    {
        for(unsigned int i = 0; i < birth.size();i++)
        {
            if(input_byear == birth[i])
            {
               cout << "Name: " << name[i] << endl
                    << "Sex: " << gender[i] << endl
                    << "Born: " << birth[i] << endl
                    << "Died: " << death[i] << endl << endl;
               byear_found = true;
            }
        }

        if(byear_found == false)
        {
            cout << "Person does not exist" << endl << endl;
        }

     }

}

void Personal::findbydeathyear(string input_dyear)
{
    bool dyear_found = false;
    if(death.size() == 0)
    {
        cout << "No person matched that search string!" << endl << endl;
    }
    else
    {
        for(unsigned int i = 0; i < death.size();i++)
        {
            if(input_dyear == death[i])
            {
               cout << "Name: " << name[i] << endl
                    << "Sex: " << gender[i] << endl
                    << "Born: " << birth[i] << endl
                    << "Died: " << death[i] << endl << endl;
               dyear_found = true;
            }
        }

        if(dyear_found == false)
        {
            cout << "Person does not exist" << endl << endl;
        }

     }

}
