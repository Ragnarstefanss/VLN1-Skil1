#include <QCoreApplication>
#include "personal.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Personal list;
    list.loadPersonal();                        //Loads input from text files into vectors
    int user_choice;

    while(true)
    {
        cout << "1) Show list of people" << endl
             << "2) Add a new person to the list" << endl
             << "3) Search for a person in the list" << endl
             << "4) Exit the program" << endl;

        cout << "Pick a number: ";
        cin >> user_choice;
        cout << endl;
        cin.ignore(); //þessi lína kemur í veg fyrir að það sendist inn empty input

        if(user_choice == 1)
        {
            list.diplayPersonal();

            cout << "What do you want to do next?" << endl;
        }

        if(user_choice == 2)
        {
            list.addPersonal();
            cout << "What do you want to do next?" << endl;
        }

        if(user_choice == 3)
        {
            cout << "1) Search by name" << endl
                 << "2) Search by gender" << endl
                 << "3) Search by birth year" << endl
                 << "4) Search by death year" << endl << endl;
            int choice;

            cout << "Pick a number: ";
            cin >> choice;
            cout << endl;
            cin.ignore(); //þessi lína kemur í veg fyrir að það sendist inn empty input

            if(choice == 1) {
                string name;

                cout << "Search for the name: ";
                cin >> name;

                cout << endl;
                list.findbyname(name);
                cout << endl;
             }

            if(choice == 2)
            {
                string gender;

                cout << "Search for gender: ";
                cin >> gender;

                list.findbyname(gender);

            }

            cout << "What do you want to do next?" << endl;
        }

        if (user_choice == 4)
        {
            cout <<"Thank you for using the program!" << endl
                 <<"Goodbye!" << endl;
            exit(0);
        }

        if ((user_choice < 1) || (user_choice > 3))
        {
            cout <<"Wrong number!" << endl;
        }

    }

    return a.exec();
}
