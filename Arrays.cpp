
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // 1. Modifying and Printing an Array

    string names[] = {
        "Philip",
        "joana",
        "Alex",
        "joana",
        "constantine",
        "Morpheus",
        "Siuan"
    };

    names[4] = "Abraham";
    names[0] = "cocaitus";

    for (int i = 0; i < 7; i++)
    {
        cout << names[i] << "\n";
    }

    // 2. Sum of Array Elements

    int nums[] = {5, 10, 15, 20, 25};

    int sum = 0;

    for (int i = 0; i < 5; i++)
    {
        sum += nums[i];
    }

    cout << "Sum: " << sum << "\n";

    // 3. Average of Array Elements

    int scores[] = {70, 80, 65, 90, 85};

    int total = 0;
    int count = 0;

    for (count = 0; count < 5; count++)
    {
        total += scores[count];
    }

    double average = static_cast<double>(total) / count;

    cout << "Average: " << average << "\n";

    // 4. Finding the Largest Element

    int numbers[] = {
        -912,
        894,
        72,
        9,
        31,
        88,
        -969,
        59,
        8887,
        95
    };

    int largest = numbers[0];

    for (int i = 1; i < 10; i++)
    {
        if (numbers[i] > largest)
        {
            largest = numbers[i];
        }
    }

    cout << "Largest: " << largest << "\n";


    // Print the numbers array
    cout << "Numbers: ";

    for (int i = 0; i < 10; i++)
    {
        cout << numbers[i] << " ";
    }

    cout << "\n";


    // 5. Bubble Sort - Ascending Order

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
    

    // Searching an array
    int target = 73;

    for (int l = 0; l < 10; l++)
    {
        if (guan[l] == target)
        {
            cout << "Found " << target << " at index " << l << '\n';
        }
        
        
    }
    

    return 0;
}

