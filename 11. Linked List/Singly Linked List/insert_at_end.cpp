#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

node* createNode(int data) {
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

node *insertEnd(node *head, int data) {
    if (isEmpty(head)) {
        head = createNode(data);
        return head;
    }
    node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = createNode(data);
    return head;
}

int main() {
    node *head = NULL;
    // head = createNode(44);
    head = insertEnd(head, 55);
    head = insertEnd(head, 65);
    head = insertEnd(head, 75);
    head = insertEnd(head, 88);
    traverse(head);
}