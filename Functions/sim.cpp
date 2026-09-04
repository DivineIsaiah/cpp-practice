#include <iostream>
using namespace std;

string name;
string sex;

void welcome()
{
    cout << "What's your name?" << '\n';
    cin >> name ;
    cout << "Hi " << name <<  " Welcome to my program" << '\n';
}

void goodbye()
{
    cout << "Program has retuned 0" << '\n';
    cout << "Goodbye " << name << '\n';
}

int main() {
    cout << "Oh Hello, program is starting" << '\n';
    cout << "Quick question are you a dude or a dudette?" << '\n';
    cin >> sex;
    
    welcome();
    cout << "Program running" << '\n';
    cout << "just a minute longer " << name << " Ps. " << sex << "s wait longer..." << '\n';
    cout << "Ok Done! " << " Btw i like " << sex << "s hehe!" << '\n';

    goodbye();
    cout << "get out my terminal " << name << '\n';  

    return 0;

}