#include <QCoreApplication>
#include "personal.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

void displaySortChoices();
void displayFindChoices();


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Personal list;
    list.loadPersonal();                                      //Loads input from text files into vectors
    int user_choice;
    int sortChoice;

    while(true)
    {
        cout << "1) Display the list" << endl
             << "2) Add a new person to the list" << endl
             << "3) Display the list sorted" << endl
             << "4) Search for a person in the list" << endl
             << "5) Exit the program" << endl;

        cout << "Pick a number: ";
        cin >> user_choice;
        cout << endl;
        cin.ignore();

        if(user_choice == 1)
        {
            list.displayPersonal();

            cout << "What do you want to do next?" << endl;
        }
        if(user_choice == 2)
        {
            list.addPersonal();
            cout << "What do you want to do next?" << endl;
        }
        if (user_choice == 3)
        {
            while(true)
            {
                 displaySortChoices();
                 cout << "Pick a number: ";
                 cin >> sortChoice;
                 cout << endl;
                 cin.ignore();

                 if((sortChoice < 1) || (sortChoice > 9))
                 {
                     cout <<"Wrong number!" << endl << endl;
                 }
                 else
                 {
                    list.sort(sortChoice);
                    break;
                 }
            }
        }
        if(user_choice == 4)
        {
            displayFindChoices();
            int choice;
            cout << "Pick a number: ";
            cin >> choice;
            cout << endl;
            cin.ignore(); //þessi lína kemur í veg fyrir að það sendist inn empty input

            if(choice == 1) {
                string name;
                string type = "name";

                cout << "Search for the name: ";
                getline(cin, name);
                name[0] = toupper(name[0]);


                cout << endl;
                list.findbytype(name, type);
                cout << endl;
             }

            if(choice == 2)
            {
                string gender;
                string type = "gender";

                cout << "Search for gender: ";
                cin >> gender;
                gender[0] = toupper(gender[0]);

                list.findbytype(gender, type);
            }

            if(choice == 3)
            {
                string birth_year;
                string type = "birth";

                cout << "Search for birth year: ";
                cin >> birth_year;

                list.findbytype(birth_year, type);
            }

            if(choice == 4)
            {
                string death_year;
                string type = "death";

                cout << "Search for death year: ";
                cin >> death_year;

                list.findbytype(death_year, type);
            }

            cout << "What do you want to do next?" << endl;
        }
        if (user_choice == 5)
        {
            cout <<"Thank you for using the program!" << endl
                 <<"Goodbye!" << endl;
            exit(0);
        }
        if ((user_choice < 1) || (user_choice > 4))
        {
            cout <<"Wrong number!" << endl;
        }
    }
    return a.exec();
}

void displaySortChoices()
{
    cout << "1) Sort by names in ascending order" << endl
         << "2) Sort by names in descending order" << endl
         << "3) Sort by gender: females" << endl
         << "4) Sort by gender: males" << endl
         << "5) Sort by year of birth in ascending order" << endl
         << "6) Sort by year of birth in descending order" << endl
         << "7) Sort by year of death in ascending order" << endl
         << "8) Sort by year of death in descending order" << endl;
}

void displayFindChoices()
{
    cout << "1) Search by name" << endl
         << "2) Search by gender" << endl
         << "3) Search by birth year" << endl
         << "4) Search by death year" << endl << endl;
}
