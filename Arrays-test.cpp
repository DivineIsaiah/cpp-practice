#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name;
    int size;
 
    int sum = 0;
    int average = 0;
    int largest = 0;
    int smallest = 0;
    int count = 0;


    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Welcome " << name << "!Enter the size of the array: ";
    cin >> size;
    int nums[size];

    for(int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << " Elements: ";
        cin >> nums[i];
    }

    cout << "Your full array is: ";
    for(int j = 0; j < size; j++)
    {
        cout << nums[j] << " ";
    }


    for( int k = 0; k < size; k++)
    {
        sum += nums[k];
        count++;
    }

    average = sum / count;

    cout << "\nYou have " << count << " elements in your array.\n";
    cout << "The sum of the array is: " << sum << "\n";
    cout << "The average of the array is: " << average << "\n";

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

    cout << "The largest element in the array is: " << largest << "\n";
    cout << "The smallest element in the array is: " << smallest << "\n";
    cout << "That's all for now, " << name << "! Thank you for using this program.\n";

}