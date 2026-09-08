#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
    Node* prev;
};

Node* newNode (int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
};

int main ()
{
    Node* first = newNode(10);
    Node* second = newNode(20);
    Node* third = newNode(30); 
    Node* fourth = newNode(40);
    // i would prefer to call the function and all i have to
    //  do is tell it the data i want to add and it creates a number of node 
    // based on that and links them for instance, 
    // newNode(10,20,30,40) I dont know if this is exam ok but that is just what my head
    //  says should be neater

    cout << first->data << '\n';
    cout << second->data << '\n';
    cout << third->data << '\n';
    cout << fourth->data << "\n";
}