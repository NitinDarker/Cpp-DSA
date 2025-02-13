#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
    node *prev;

    node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

node *createNode(int data) {
    return new node(data);
}

void addNode(node *head, int data) {
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    node *n = createNode(data);
    temp->next = n;
    n->prev = temp;
}

node *reverse_dll(node *head) {
    node *temp = head;
    while (temp != nullptr) {
        node *tempNext = temp->next;
        swap(temp->prev, temp->next);
        if (tempNext == NULL) {
            break;
        }
        temp = tempNext;
    }
    return temp; // temp = new head
}

void display(node *head) {
    node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void display_reverse(node *head) {
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;

}

int main() {
    node *head = NULL;
    head = createNode(5);
    addNode(head, 15);
    addNode(head, 25);
    addNode(head, 35);
    addNode(head, 45);
    addNode(head, 55);
    addNode(head, 65);

    display(head);
    display_reverse(head);
    head = reverse_dll(head);
    cout << "After reverse function" << endl;
    display(head);
    display_reverse(head);
}