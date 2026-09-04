#include <iostream>
using namespace std;

int main()
{
    string password;
    cout << "Type your password: ";
    cin >> password;

    while (password != "admin")
    {
        cout << "Incorrect password. Please try again: ";
        cin >> password;
    }
    cout << "Password accepted." << endl;
    return 0;
}