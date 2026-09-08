#include <iostream> 
#include <string>
using namespace std; 

int main ()
{
     int numz[] = {64, 25, 12, 22, 11};

    int n = 5;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (numz[j] > numz[j + 1])
            {
                int temp = numz[j];

                numz[j] = numz[j + 1];

                numz[j + 1] = temp;
            }
        }
    }

    // Print sorted array
    cout << "Sorted: ";

    for (int i = 0; i < n; i++)
    {
        cout << numz[i] << " ";
    }

    cout << "\n";


    int guan[]{699, 57, 97, 783, 98, 568, 73, -32, 0, -91};
    int qnt = 10;

    for (int i = 0; i < qnt - 1; i++)
    {
        for (int j = 0; j < qnt - i - 1; j++)
        {
            if (guan[j] > guan[j + 1])
            {
                int temp = guan[j];
                guan[j] = guan[j + 1];
                guan[j + 1] = temp;
            }
        }
        
    }

    cout << "The guan array is now sorted to: ";
    
    for (int p = 0; p < qnt; p++)
    {
        cout << guan[p] << " ";
    }

    cout << '\n';

    int target = 73;

    for (int l = 0; l < 10; l++)
    {
        if (guan[l] == target)
        {
            cout << "Found " << target << " at index " << l << '\n';
        }
        
        
    }

}
   