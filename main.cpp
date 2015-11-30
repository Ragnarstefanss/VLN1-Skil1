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
             << "3) Exit the program" << endl;

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

        if (user_choice == 3)
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
