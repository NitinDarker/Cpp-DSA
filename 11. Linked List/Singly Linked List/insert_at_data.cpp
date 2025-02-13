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

node *insertKey(node *head, int data, int key) {
    // Insertion takes place after the key node
    if (isEmpty(head)) {
        head = createNode(data);
        return head;
    }
    node *temp = head;
    while (temp->data != key) {
        if (temp->next == NULL) {
            cout << key << " is not found in the linked list!" << endl;
            cout << "Inserting at the end... " << endl;
            temp->next = createNode(data);
            return head;
        }
        temp = temp->next;
    }
    node *n = createNode(data);
    n->next = temp->next;
    temp->next = n;
    return head;
}

int main() {
    node *head = NULL;
    head = addNode(head, 15);
    head = addNode(head, 25);
    head = addNode(head, 35);
    head = addNode(head, 45);
    head = addNode(head, 55);

    cout << "Linked List: " << endl;
    traverse(head);
    cout << "Enter the key after which a new node is to be inserted: ";
    int key;
    cin >> key;
    cout << "Enter the data in the node: ";
    int data;
    cin >> data;
    head = insertKey(head, data, key);
    cout << "New Linked List: " << endl;
    traverse(head);
}