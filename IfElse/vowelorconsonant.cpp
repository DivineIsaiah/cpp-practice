#include <iostream>
using namespace std;

int main() {
    string name;
    char alphabet;
    string response;

    cout << "What is your name? ";
    cin >> name;
    cout << "Hello, " << name << "! Are you ready to begin?" << endl;
    cin >> response;
    if (response == "yes" || response == "Yes" || response == "YES") {
        cout << "Great! Let's get started." << endl;
        cout << "Enter an alphabet: "<< endl;
    } else {
        cout << "Well, You're no fun!" << endl;
    }

    cin >> alphabet;

    if (alphabet == 'a' || alphabet == 'e' || alphabet == 'i' || alphabet == 'o' || alphabet == 'u' || alphabet == 'A' || alphabet == 'E' || alphabet == 'I' || alphabet == 'O' || alphabet == 'U')
    {
        cout << "The alphabet" << alphabet << "is a vowel." << endl; 
    }

    else
    {
        cout << "The alphabet" << alphabet << "is a consonant." << endl;
    }
    return 0;
}