#include <iostream>

using namespace std;

// Þórdís að prufa git.
int main()
{
    int input_val;

    cout << "1) Add a new person" << endl
         << "2) Show list of persons" << endl
         << "3) Search for a person" << endl;

    cout << "Pick a number: ";
    cin >> input_val;
    cout << endl;

    cout << "You picked the number: " << input_val << endl;

    return 0;
}
