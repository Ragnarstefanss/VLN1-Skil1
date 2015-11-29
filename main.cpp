#include <QCoreApplication>
#include "personal.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int input_val;

    cout << "1) Add a new person" << endl
         << "2) Show list of persons" << endl
         << "3) Search for a person" << endl;

    cout << "Pick a number: ";
    cin >> input_val;
    cout << endl;

    cout << "You picked the number: " << input_val << endl;

    return a.exec();
}

