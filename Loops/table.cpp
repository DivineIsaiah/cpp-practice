#include <iostream>
using namespace std;

int num;

int main()
{
    cout << "Enter a number: ";
    cin >> num;
    
    for (int i = 1; i <= 12; ++i)
    {
        cout << num << " x " << i << " = " << num * i << endl;
    }
    return 0;
}
