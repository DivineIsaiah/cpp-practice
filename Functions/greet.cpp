#include <iostream>
using namespace std;

void greet(string name)
    {
        cout << "Good day " << name << '\n';
    }

void times (int x, int y, int z)
{
    cout << x*y*z << '\n';
}

int cube(int number)
{
    return number * number;
}

int bigger (int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }

}

void showMarks (int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " " << '\n';
    }
}


int main ()
{
    greet("Divine");
    times(34,89,75);
    cout << cube(56) << '\n';
    cout << "For the numbers 958 and 876, " << bigger(958, 876) << " is bigger" << '\n';

    int marks[]={75,68,90,82,95};
    showMarks(marks, 4);

   return 0;
}
