#include <iostream>

using namespace std;

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (number > 0) {
        cout << "Positive number it is." << endl;
    }

    cout << "This is automatically executed anyway." << endl;

    return 0;
}
