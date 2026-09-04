#include <iostream>
using namespace std;

int main()
{
    int num1, num2, num3;

    cout << "Enter three numbers  " << endl;
    cin >> num1 >> num2 >> num3;

    if (num1 > num2 && num1 > num3)
    {
        cout << "The largest number is: " << num1 << endl;
    }
    else if (num2 > num1 && num2 > num3)
    {
        cout << "The largest number is: " << num2 << endl;
    }
    else if (num3 > num1 && num3 > num2)
    {
        cout << "The largest number is: " << num3 << endl;
    }

    else 
    {
        cout << "That doesn't seem valid" << endl;
    }

    return 0;
}
