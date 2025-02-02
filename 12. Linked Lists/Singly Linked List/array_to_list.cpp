#include <iostream>
#include <vector>
using namespace std;

struct node {
    int data;
    node *next;
};

node *createNode(int data) {
    node *n = new node;
    n->data = data;
    n->next = nullptr;
    return n;
}

node *addNode(node *head, int data) {
    if (head == NULL) {
        return createNode(data);
    }
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = createNode(data);
    return head;
}

void display(node *head) {
    node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node *array_to_linkedList(vector<int> &v) {
    node *head = nullptr;
    for (int i = 0; i < v.size(); i++) {
        head = addNode(head, v[i]);
    }
    return head;
}

node *array_to_linkedList(int *arr, int size) {
    node *head = nullptr;
    for (int i = 0; i < size; i++) {
        head = addNode(head, arr[i]);
    }
    return head;
}

int main() {
    int size = 6;
    int *arr = new int[size]{4, 7, 1, 9, 2, 5};

    vector<int> v = {4, 7, 1, 9, 2, 5, 5};
    node *head = nullptr;

    head = array_to_linkedList(arr, size);
    // head = array_to_linkedList(v);

    display(head);
}