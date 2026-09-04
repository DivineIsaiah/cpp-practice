#include <iostream>
using namespace std;

int main() {
    string name;
    int age;
    int number;
    char alphabet;
    string response;
    string time;

    cout << "What is your name? " << endl;
    cin >> name;
    cout << "Hello, " << name << "! Are you ready to begin?" << endl;
    cin >> response ;

    if (response == "yes" || response == "YES" || response == "Yes" || response == "yeS") 
    {
        cout << "I like you already " << name << "!" << endl;
        cout << "Ok " << name << ", quick one, how old are you? " << endl;
        cout << "Type a number like 78" << endl;
    }

    else if (response == "no" || response == "NO" || response == "No")
    {
        cout << "C'mon, lets have a little fun" << endl;
        cout << "How old are you?" << endl;
    }

    else {
        cout << "Just tell me how old you are" << endl;
    }
    

    cin >> age;

    if (age < 19)
    {
        cout << "so you're " << age << " years old" << endl;
        cout << "That means you're still a child in Nigeria." << endl;
    } 

    else if (age > 18 && age < 80)
    {
        cout << name << " you are a proper adult aready." << endl;   
    }

    else if (age > 79)
    {
        cout << "Wow, you're really old" << endl;
    }

    else
    {
        cout << "I don't know what to say" << endl;
        cout << "I guess you're a child" << endl;

    }


    cout << name << " Please tell me if its morning or afternoon or evening right now." << endl;
    cout << "Just type either Morning, or afternoon or evening so i understand" << endl;

    cin >> time;
    cout << "Good " << time << " " << name << " ! I hope you're feeling good" << endl;

    cout << "Hey wanna see a trick?" << endl;
    cin >> response;

    if (response == "YES" || response == "Yes" || response == "yes")
    {
        cout << "Ok, pick any one alphabet from A - Z" << endl;
    }
    else if (response == "NO" || response == "No" || response == "no")
    {
        cout << "Alright, maybe next time." << endl;
    }
    else
    {
        cout << "I didn't understand your answer." << endl;
    }


    cin >> alphabet;

    if (alphabet == 'a' || alphabet == 'e' || alphabet == 'i' || alphabet == 'o' || alphabet == 'u' || alphabet == 'A' || alphabet == 'E' || alphabet == 'I' || alphabet == 'O' || alphabet == 'U')
    {
        cout << "The alphabet " << alphabet << " is a vowel." << endl; 
    }

    else
    {
        cout << "The alphabet " << alphabet << " is a consonant." << endl;
    }

    cout << "lets play another one. Pick a number between 1 - 10" << endl;

    cin >> number;

    if (number % 2 == 0) 
    {
        cout << "You chose " << number << " which is an even number" << endl;
    }
    else
    {
        cout << "You chose " << number << " which is an odd number" << endl;
    }

    cout << "Thanks for playing with me" << endl;
    cout << "I hope you had fun" << endl;
    cout << "Seriously go and do something else i need to sleep. " << "good " << time << endl;
    return 0;


  


}