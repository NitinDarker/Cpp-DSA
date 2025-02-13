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

node *insertIndex(node *head, int data, int index) {
    // Assuming linked list of base index 1
    // Head node/First node has an index/position = 1
    if (isEmpty(head)) {
        head = createNode(data);
        return head;
    }
    int base = 1;
    if (index == base) {
        // If node is to be added at base position
        node *n = createNode(data);
        n->next = head;
        head = n;
        return head;
    }
    node *temp = head;
    while (base != index - 1 && base < index) {
        if (temp->next == NULL) {
            // Index got out of bounds
            // Adding node at the end of the list
            temp->next = createNode(data);
            return head;
        }
        temp = temp->next;
        base++;
    }
    // temp->next points where new node is to be created
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
    cout << "Enter the position where a new node is to be inserted: ";
    int index;
    cin >> index;
    if (index < 1) {
        cout << "Index is not valid!" << endl;
        exit(0);
    }
    cout << "Enter the data in the node: ";
    int data;
    cin >> data;
    head = insertIndex(head, data, index);
    cout << "New Linked List: " << endl;
    traverse(head);
}