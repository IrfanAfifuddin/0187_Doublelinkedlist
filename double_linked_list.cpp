#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int noMhs;
    string name;
    Node* next;
    Node* prev;
};

Node* START = NULL;

void addNode() {
    Node* newNode = new Node(); // step 1: create new node
    cout << "\nEnter the roll number of the student: ";
    cin >> newNode->name; // assign value to the data field of the new node
    cout << "\Enter the name of the student: ";
    cin >> newNode->name;// assign value to the data field of the new node


    // insert the new node in the list 
    if (START == NULL || newNode->noMhs == START->noMhs) { // step 2: insert to the new node
        if (START != NULL && newNode->noMhs == START->noMhs) {
            cout << "\033[31mDuplicate roll numbers not allowed\033[0m" << endl;
            return;
        }
        // if the list is empty make the new node to START
        newNode->next = START; // step 3: make the new node point to the first node
        if (START != NULL) {
            START->prev = newNode; // step 4: make the first node point to the new node
        }
        newNode->prev = NULL; // step 5: make the new node point to NULL
        START = newNode; // step 6: make the new node the first node
    }
    else {
        // insert the new node inthe middle or at the end
        Node* current = START; // step 1.a: start from first node
        Node* previous = NULL; // step 1.b: previous node is NULL initially

        while (current != NULL && current->noMhs < newNode->noMhs) { // setp 1.c: 
            previous = current; // step 1.d: move the previous to current node
            current = current->next; // step 1.e: move the current to next node
        }

        newNode->next = current; // step 4: make the next field of the new node point
        newNode->prev = previous; // step 5: make the previous field of the new node

        if (current != NULL) {
            current->next = newNode; // step 6: make the previous of the current
        }

        if (previous != NULL) {
            previous->next = newNode; // step 7: Make the next field of the previous 
        }
        else {
            // if previous is still NULL, it means newNode is now the first node
            START = newNode;
        }
    }
}

int main()
{

}