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

void display(node *head) {
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
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = createNode(data);
    return head;
}

node *reverse_ll(node *head) {
    node *prev = NULL;
    node *curr = head;
    while (curr != NULL) {
        node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

node *reverse_rec(node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    node *new_head = reverse_rec(head->next);
    node *front = head->next;
    front->next = head;
    head->next = NULL;
    return new_head;
}

int main() {
    node *head = NULL;
    // head = createNode(44);
    head = insertEnd(head, 55);
    head = insertEnd(head, 65);
    head = insertEnd(head, 75);
    head = insertEnd(head, 88);
    head = insertEnd(head, 38);
    head = insertEnd(head, 41);
    cout << "Linked List:" << endl;
    display(head);

    cout << "Reversed Linked List: " << endl;
    head = reverse_rec(head);
    display(head);
}