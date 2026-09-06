#include <iostream>
#include <string>

using namespace std;

// this is binary search
int binarySearch(int array[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    int mid = (low + high) / 2;

    while (low <= high)
    {
        if (array[mid] == target)
        {
            return mid;
        }

        else if (target > array[mid])
        {
            low = mid + 1;
            mid = (low + high) / 2;
        }

        else if (target < array[mid])
        {
            high  = mid - 1;
            mid = (low + high) / 2;
        }
    }

    return -1;
}

int main ()
{
    int gollop[] {12, 23, 34, 45, 56, 67, 78, 89, 90};
    
    int SearchTarget = 0;
    int sizeOFarray = 9;

    cout << "Please enter an integer value to search:" << "\n";
    cin >> SearchTarget ;

    int result = binarySearch(gollop, sizeOFarray, SearchTarget);
    
    if (result >= 0)
    {
        cout << "I found " << SearchTarget << " at index " << result << '\n';
    }

    else if ( result < 0)
    {
        cout << "I didn't find that in the array" << endl;
    }

    return 0;
}