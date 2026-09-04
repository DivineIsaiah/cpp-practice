#include <iostream>
using namespace std;

int main()
{
    int score;
    string name;
    string subject;

    cout << "Hi, What is your name?" << endl;
    cin >> name; 
    cout << "Hi " << name << " What exam subject did you write?" << endl;
    cin >> subject;
    cout << "What did you score?" << endl;
    cin >> score;

    if (score <= 100 )
    {
        if (score >= 70)
        {
            cout << "You're " << subject << " grade is A" << endl;
        }

        else if (score >= 60 && score < 70)
        {
            cout << "You're " << subject << " grade is B" << endl;
        }

        else if (score >= 50 && score < 60)
        {
            cout << "You're " << subject << " grade is C" << endl;
        }

        else if (score >= 45 && score < 50)
        {
            cout << "You're " << subject << " grade is D" << endl;
        }

        else if (score >= 40 && score < 45)
        {
            cout << "You're " << subject << " grade is E" << endl;
        }

        else if (score < 40)
        {
            cout << "You're " << subject << " grade is F" << endl;
        }

        else if (score <0)
        {
            cout << "That is an invalid score. Meet your grading office." << endl;
        }
        
        else
        {
            cout << "That is an invalid score. Meet your grading office." << endl;
        }
       
    }

    else
    {
        cout << "That is an invalid score. Meet your grading office." << endl;
    }
    
    return 0;
}


