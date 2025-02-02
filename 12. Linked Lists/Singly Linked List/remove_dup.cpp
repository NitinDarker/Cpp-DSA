// Write a C++ Program to remove duplicates in a sorted Linked List
#include <iostream>
using namespace std;

struct node { // Structure for a node in a linked list
    int data;
    node *next;
};

node *createNode(int data) { // To create a new node structure
    node *n = new node;
    n->data = data;
    n->next = NULL;
    return n; // Returns the pointer pointing this newly created node
}

void traverse(node *head) { // To print the data in a linked list
    if (head == NULL) {
        cout << "Linked List is Empty!" << endl;
        return;
    }
    node *temp = head; // Creating a temporary pointer
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next; // Traversing the temp till the last node of the list
    }
    cout << endl;
}

node *addNode(node *head, int data) { // To add a new node in the list
    if (head == NULL) {
        head = createNode(data); // If the list is empty, then creates first node
        return head;
    }

    node *temp = head; // Creating a temporary pointer to a node
    while (temp->next != NULL) {
        temp = temp->next;
    } // Temp points to the last node of the linked list

    temp->next = createNode(data); // Linking last node to the newly created node
    return head;
}

void remove_duplicates(node *head) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    node *temp = head;
    node *tempNext = head->next;
    while (temp->next != NULL) {
        if (tempNext->data == temp->data) {
            temp->next = tempNext->next;
            delete tempNext;
            tempNext = temp->next;
        }
        else {
            temp = tempNext;
            tempNext = temp->next;
        }
    }
}

int main() {
    // Head points to the first node of the linked list
    node *head = NULL; // Initially head points to NULL
    // An empty linked list is created...
    head = createNode(10);
    head = addNode(head, 25);
    head = addNode(head, 25);
    head = addNode(head, 25);
    head = addNode(head, 35);
    head = addNode(head, 35);
    head = addNode(head, 45);
    head = addNode(head, 55);
    head = addNode(head, 55);
    head = addNode(head, 65);
    head = addNode(head, 65);
    head = addNode(head, 65);
    head = addNode(head, 85);

    traverse(head);
    remove_duplicates(head);
    traverse(head);
}