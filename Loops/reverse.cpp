#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int p = 10; p >= i; p--)
        {
            cout << p << " ";
        }
        cout << endl;
    }
}
