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
    void loadPersonal();

private:

    vector<string> name;
    vector<string> gender;
    vector<int> birth;
    vector<int> death;

};

#endif // PERSONAL_H
