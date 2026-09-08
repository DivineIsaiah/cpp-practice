#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name;
    int size;
 
    int sum = 0;
    double average = 0;
    int largest = 0;
    int smallest = 0;
    int count = 0;


    cout << "Enter your name: ";
    getline(cin, name);
    cout << "\nWelcome " << name << "! Enter the size of the array: ";
    cin >> size;
    cout << "\n";
    int nums[size];

    for(int i = 0; i < size; i++)
    {
        cout << "Enter number " << i + 1 << " elements: ";
        cin >> nums[i];
    }

    cout << "\nYour full array is: ";
    for(int j = 0; j < size; j++)
    {
        cout << nums[j] << " ";
    }

    cout << "\n";
    for( int k = 0; k < size; k++)
    {
        sum += nums[k];
        count++;
    }

    average = (double)sum / (double)count;

    cout << "\nYou have " << count << " elements in your array.\n";
    cout << "\n";
    cout << "The sum of your array is: " << sum << "\n";
    cout << "\n";
    cout << "The average of your array is: " << average << "\n";
    cout << "\n";

    largest = nums[0];
    smallest = nums[0];

    for(int l = 0; l < size; l++)
    {
        if(nums[l] > largest)
        {
            largest = nums[l];
        }
        if(nums[l] < smallest)
        {
            smallest = nums[l];
        }
    }

    cout << "The largest element in your array is: " << largest << "\n";
    cout << "\nThe smallest element in your array is: " << smallest << "\n";
    cout << "\nWell that's all for now, " << name << "! Thank you for using this program." << endl;

    return 0;
}