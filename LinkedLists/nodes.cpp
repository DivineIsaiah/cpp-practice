#include <iostream>
using namespace std;

// first we create a new type called Node and define its characteristics
struct Node{
    int data;
    Node* next;
    Node* prev;
};

// function to create new node
Node* createNode (int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode; 
}

// now to add infrontog the list
void insertEnd (Node*& head, int value)
{
    Node* newNode = createNode (value);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

}

void insertStart(Node*& head, int value)
{
    Node* newNode = createNode(value);

    if(head != nullptr)
    {
        head->prev = newNode;
    }

    newNode->next = head;

    head = newNode;
}

void traverse (Node* head)
{
    Node* temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}


// the main function where we call the prev functions we write to work
int main()
{
    Node* head = nullptr;

    insertEnd(head, 8);
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 49);
    insertEnd(head, 50);

    cout << "The list after insetion at end:";

    traverse(head);

    insertStart(head, 12);
    insertStart(head, 813);
    insertStart(head, 14);
    insertStart(head, 895);
    insertStart(head, 16);
    insertStart(head, 136);
    insertStart(head, 98);
    insertStart(head, 68);

    cout << "After insertion at start:";
    traverse(head);

    return 0;


}