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

node *insertStart(node *head, int data) {
    if (isEmpty(head)) {
        head = createNode(data);
        return head;
    }
    node *n = createNode(data);
    n->next = head;
    head = n;
    return head;
}

int main() {
    node *head = NULL;
    // head = createNode(44);
    head = insertStart(head, 55);
    head = insertStart(head, 65);
    head = insertStart(head, 75);
    head = insertStart(head, 85);
    head = insertStart(head, 105);
    traverse(head);
}