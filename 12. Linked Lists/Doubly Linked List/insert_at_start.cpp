#include <iostream>
using namespace std;

struct dNode {
    int data;
    dNode *prev;
    dNode *next;
} typedef node;

struct dll {
    node *front, *rear;
};

node *createNode(int data) {
    node *n = new node;
    n->next = NULL;
    n->prev = NULL;
    n->data = data;
    return n;
}

dll createDLL() {
    dll list;
    list.front = NULL;
    list.rear = NULL;
    return list;
}

void updateDLL(dll &list, node *front, node *rear) {
    list.front = front;
    list.rear = rear;
}

bool isEmpty(dll &list) {
    if (list.front == NULL) {
        return true;
    }
    return false;
}

dll addNode(dll &list, int data) {
    if (isEmpty(list)) {
        node *n = createNode(data);
        updateDLL(list, n, n);
        return list;
    }
    node *n = createNode(data);  // Creating a new node
    list.rear->next = n;         // Linking next of rear to new node
    n->prev = list.rear;         // Linking prev of new node to rear
    list.rear = list.rear->next; // Updating the rear
    return list;                 // Returning the list
}

void traverse(dll &list) {
    node *temp = list.front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

dll insertStart(dll &l, int data) {
    if(isEmpty(l)) {
        node *n = createNode(data);
        updateDLL(l, n, n);
        return l;
    }
    node *n = createNode(data);
    l.front->prev = n;
    n->next = l.front;
    l.front = n;
    return l;
}

int main() {
    dll list = createDLL();
    list = addNode(list, 5);
    list = addNode(list, 15);
    list = addNode(list, 25);
    list = addNode(list, 35);
    list = addNode(list, 45);
    list = addNode(list, 55);

    traverse(list);
    list = insertStart(list, 100);
    traverse(list);
}