#include <iostream>
using namespace std;

struct Node { // Structure for a Node in a linked list
    int data;
    Node *next;
};

Node *createNode(int data) { // To create a new Node structure
    Node *n = new Node;
    n->data = data;
    n->next = NULL;
    return n; // Returns the pointer pointing this newly created Node
}

bool isEmpty(Node *head) { // To check if a linked list is empty or not
    if (head == NULL) {    // Head points to the first Node in the list
        return true;
    }
    return false;
}

void display(Node *head) { // To print the data in a linked list
    if (isEmpty(head)) {
        cout << "Linked List is Empty!" << endl;
        return;
    }
    Node *temp = head; // Creating a temporary pointer
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next; // Traversing the temp till the last Node of the list
    }
    cout << endl;
}

Node *addNode(Node *head, int data) { // To add a new Node in the list
    if (isEmpty(head)) {
        head = createNode(data); // If the list is empty, then creates first Node
        return head;
    }

    Node *temp = head; // Creating a temporary pointer to a Node
    while (temp->next != NULL) {
        temp = temp->next;
    } // Temp points to the last Node of the linked list

    temp->next = createNode(data); // Linking last Node to the newly created Node
    return head;
}

int main() {
    // Head points to the first Node of the linked list
    Node *head = NULL; // Initially head points to NULL
    // An empty linked list is created...
    head = createNode(10);
    head = addNode(head, 25);
    head = addNode(head, 35);
    head = addNode(head, 45);
    head = addNode(head, 55);
    head = addNode(head, 65);
    display(head);
}