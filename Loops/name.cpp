#include <iostream>
using namespace std;

int main()
{
    string name;
    cout << "What is your name? " << endl;
    cin >> name;

    for (int i = 1; i <= 5; i++)
    {
        cout << "Hello, " << name << "! This is message number " << i << endl;
    }
    return 0;
}