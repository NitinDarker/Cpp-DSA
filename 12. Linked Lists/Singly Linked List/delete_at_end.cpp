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

node *deleteEnd(node *head) {
    if (head == NULL) {
        cout << "Cannot delete from an empty linked list!" << endl;
        return head;
    }
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
    node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    node *del = temp->next;
    temp->next = NULL;
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
    head = deleteEnd(head);
    traverse(head);
}