#include <iostream>
using namespace std;

// Question 1
struct Node {
    int data;
    Node* next;
};

Node* createNode (int value)
    {
      Node* newNode = new Node();
      newNode->data = value;
      newNode->next = nullptr;

      return newNode;
    }


void insertEnd (Node*& head, int value)
{
    Node* newNode = createNode(value);

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

int countNode (Node* head)
{
    Node* temp = head;
    int sum = 0;
    
    while (temp != nullptr)
    {
        sum++;
        temp = temp->next;
    }

    return sum;
}




int search (Node* head, int value)
 {
    Node* temp = head;
    int position = 1;

    while (temp != nullptr)
    {
        if (temp->data == value)
        {
            return position;
        }
        temp = temp->next;
        position++;

    }

    return -1;

}

void searchNode (Node* head, int value)
 {
    int position = search(head, value);

    if(position != -1)

    {
        cout << value << " was found in Node " << position << '\n';
    }
    
    else
    {
        cout << value << " was not found" << endl;
    }
    
 }


 void insertAfter (Node* head, int target, int value )
 {
    Node* temp = head;

    while (temp != nullptr)
    {
        if (temp->data == target)
        {
            Node * newNode = createNode(value);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        
        temp = temp->next;
        
    }

    cout << "Target was not found" << endl;
 }

int delhelper (Node*& head, int value)
{
    if (head == nullptr)
    {
        return -1;
    }

    if (head->data == value)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return 1;
    }

    Node * curr = head->next;
    Node* prev = head;
    int position = 2;

    while (curr != nullptr)
    {
        if (curr->data == value)
        {
            prev->next = curr->next;
            delete curr;
            return position;
        }

        prev = curr;
        curr = curr->next;
        position++;
    }

   return -2;
}

void deleteNode (Node*& head, int value )
{
    int position = delhelper(head, value);
    
    if (position == -1)
    {
        cout << value  << " was not found because the list is empty" << '\n';
    }

    else if(position == -2)
    {
        cout << value << " does not exist in this list" << '\n';
    }

    else{
         cout 
         << value 
         << " was found at Node " 
         << position 
         << " and has been deleted" 
         << endl; 
    }
   
}

void reverse (Node*& head)
{
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

    }
    head = prev;

    traverse(head);
}


void deleteBegining (Node*& head)
{
    if (head == nullptr)
    {
        cout << "List is empty" << '\n';
        return;
    }

    Node* temp = head;
    head = head->next;

    delete temp;
    cout << "The first node has been deleted" << '\n';
    return;

}

void deleteEnd (Node*& head)
{
    if (head == nullptr)
    {
        cout << "No nodes to delete here" << '\n';
        return;
    }

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        cout << "There was only one node and it has been deleted" << '\n';
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    while (temp->next !=  nullptr)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = nullptr;
    delete temp;
    cout << "Found the last node and cut its thread" << endl;
    return;
}

void deleteList (Node*& head)
{
    Node* temp = head;
     while( temp != nullptr)
     {
        Node* next = temp->next;
        delete temp;
        temp = next;
        
     }

     head = nullptr;
     cout << "List has been destroyed by lord zeno" << endl;
     return;
}

void inserAtPosition (Node*& head, int position, int value)
{
    int local = 1;
    Node* temp = head;

    if (position == 1)
        {
            Node* newNode = createNode(value);
            newNode->next = head;
            head = newNode;
            return;
        }


    while(temp->next != nullptr)
    {
       
        if (local == position -1)
        {
            Node* newNode = createNode(value);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        
        temp = temp->next;
        local++;
    }

    if (local == position -1)
    {
        Node* newNode = createNode(value);
        newNode->next = nullptr;
        temp->next = newNode;
        return;
    }

    cout 
    << "I dont know what list you've got there but mine doesn't have any node at position "
    << position
    << endl;
}


int main ()
{
    Node* head = nullptr;
    
    // create a node
    // Insert 15, 30, 45, 60 and 75 at the end of the list.
    // Traverse the list and display all elements.
    // Count the total number of nodes without using a global variable.
    // Print
    // Number of nodes = 5
    // Restrictions
    // No arrays.
    // No vectors.
    // No recursion.


    insertEnd(head, 15);
    insertEnd(head, 30);
    insertEnd(head, 45);
    insertEnd(head, 60);
    insertEnd(head, 75);
    insertEnd(head, 55);
    insertEnd(head, 90);
    insertEnd(head, 98);
    insertEnd(head, 705);

    insertAfter(head, 90, 93);
    insertAfter(head, 90, 77);
    insertAfter(head, 90, 13);
    insertAfter(head, 90, 20);
    insertAfter(head, 90, 50);
    insertAfter(head, 900, 93);
   

    traverse(head);

    cout << "Number of nodes = " << countNode(head) << endl;

    searchNode(head, 98);
    deleteNode(head, 50);
    deleteNode(head, 60);
    deleteNode(head, 980);
    deleteNode(head, 550);
    deleteNode(head, 20);

    reverse(head);
    deleteBegining(head);
    deleteEnd(head);
    traverse(head);


    return 0;
}