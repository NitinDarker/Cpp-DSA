#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

node *createNode(int data) {
    node *n = new node;
    n->data = data;
    n->next = NULL;
    return n;
}

bool isEmpty(node *head) {
    if (head == NULL) {
        return true;
    }
    return false;
}

node *addNode(node *head, int data) {
    if (isEmpty(head)) {
        head = createNode(data);
        return head;
    }
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = createNode(data);
    return head;
}

void traverse(node *head) {
    if (isEmpty(head)) {
        cout << "Linked List is Empty!" << endl;
        return;
    }
    node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node *deleteData(node *head, int key) {
    if (isEmpty(head)) {
        // Case for an empty linked list
        cout << "Cannot delete from an empty linked list!" << endl;
        return head;
    }

    if (head->next == NULL) {
        // If the linked list has only one node
        if (head->data == key) {
            // If key data is on that node
            delete head;
            return NULL;
        }
        cout << "Element not found!" << endl;
        return head;
    }
    // If the linked list has more than one node

    node *temp = head;

    if (temp->data == key) {
        // If key data is on the head node/ Delete from the beginning
        head = head->next;
        delete temp;
        return head;
    }

    while (temp->next->data != key) {
        if (temp->next->next == NULL) {
            cout << "Element not found!" << endl;
            return head;
        }
        temp = temp->next;
    }

    node *del = temp->next;
    temp->next = del->next;
    delete del;
    return head;
}

int main() {
    node *head = NULL;
    head = addNode(head, 5);
    head = addNode(head, 15);
    head = addNode(head, 25);
    head = addNode(head, 35);
    head = addNode(head, 45);
    head = addNode(head, 55);
    head = addNode(head, 100);

    traverse(head);
    head = deleteData(head, 5);
    traverse(head);
}