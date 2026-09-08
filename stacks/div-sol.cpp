// this file contains my solutions to the question.md. 
// you may create a file in this same dir for your solutions.

#include <iostream>
#include <stack>

using namespace std;
 
void PrintStack (stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;
    
}


int main()
{
    stack<int> nums;

    nums.push(10);
    nums.push(20);
    nums.push(30);
    nums.push(40);
    nums.push(50);

    cout << "The full stack: ";
    PrintStack(nums);

    cout << nums.top() << endl;

    nums.pop();
    nums.pop();

    cout << "The full stack after pop ";
    PrintStack(nums);
    cout << nums.size() << endl;



}