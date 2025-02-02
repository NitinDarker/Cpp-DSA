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

bool isEmpty(node *head) { // To check if a linked list is empty or not
    if (head == NULL) {    // Head points to the first node in the list
        return true;
    }
    return false;
}

void display(node *head) { // To print the data in a linked list
    if (isEmpty(head)) {
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
    if (isEmpty(head)) {
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

int main() {
    // Head points to the first node of the linked list
    node *head = NULL; // Initially head points to NULL
    // An empty linked list is created...
    head = createNode(10);
    head = addNode(head, 25);
    head = addNode(head, 35);
    head = addNode(head, 45);
    head = addNode(head, 55);
    head = addNode(head, 65);

    display(head);
}