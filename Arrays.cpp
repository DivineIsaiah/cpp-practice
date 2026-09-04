#include <iostream>
using namespace std;

int main ()
{
   string names[] = {"Philip", "joana", "Alex", "joana", "constantine", "Morpheus", "Siuan"};
   names[4] = "Abraham";
   names[0] = "cocaitus";

   for (int i = 0; i < 7; i++)
   {
    cout << names[i] << "\n";
   }

   int nums[] {5, 10, 15, 20, 25};
   int sum = 0;
   for (int i = 0; i < 5; i++)
   {
     sum += nums[i];
   }
   cout << "Sum: " << sum << "\n";


   int scores[] {70, 80, 65, 90, 85};

   int average = 0;
   int k = 0;
   for (k = 0; k < 5; k++)
   {
        average += scores[k];
   }
   average /= k;
   cout << "Average: "
        << average
        << "\n";

    int numbers[] {-912, 894, 72, 9, 31, 88, -969, 59, 8887, 95};
    int largest = numbers[0];
    for (int i = 1; i < 10; i++)
    {
        if (numbers[i] > largest)
        {
            largest = numbers[i];
        }
    }
    cout << "Largest: " << largest << "\n";
    cout << numbers << endl;
}