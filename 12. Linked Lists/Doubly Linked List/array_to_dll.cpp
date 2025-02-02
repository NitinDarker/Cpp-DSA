#include <iostream>
using namespace std;

struct dNode {
    int data;
    dNode *prev;
    dNode *next;

    dNode(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

    dNode(int data, dNode *next, dNode *prev) {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
} typedef node;

struct dll {
    node *front;
    node *rear;

    dll() {
        this->front = nullptr;
        this->rear = nullptr;
    }

    dll(node *front, node *rear) {
        this->front = front;
        this->rear = rear;
    }
} typedef list;

node *createNode(int data) {
    return new node(data);
}

dll *array_to_dll(int *arr, int size) {
    dll *l = new list;
    l->front = createNode(arr[0]);
    l->rear = l->front;
    for (int i=1; i<size; i++) {
        node *n = createNode(arr[i]);
        l->rear->next = n;
        n->prev = l->rear;
        l->rear = n;
    }
    return l;
}

void display(list *l) {
    node *temp = l->front;
    while (temp != l->rear->next) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void display_reverse(list *l) {
    node *temp = l->rear;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    int size = 8;
    int *arr = new int[size]{3,7,1,9,0,3,5,2};

    list *l = array_to_dll(arr, size);
    display(l);
    display_reverse(l);
}
