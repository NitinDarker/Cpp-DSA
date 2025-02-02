#include <iostream>
using namespace std;

struct node {
    string name;
    node *nextName;
    int age;
    node *nextAge;
};

node *createNode(string name, int age) {
    node *n = new node;
    n->name = name;
    n->age = age;
    n->nextAge = NULL;
    n->nextName = NULL;
    return n;
}

node *addNode(node *head, string name, int age) {
    if (head == NULL) {
        head = createNode(name, age);
        return head;
    }
    node *n = createNode(name, age);
    node *tempName = head;
    node *tempName2 = NULL;
    node *tempAge = head;
    node *tempAge2 = NULL;

    while ((tempAge != NULL) && (tempAge->age < age)) {
        tempAge2 = tempAge;
        tempAge = tempAge->nextAge;
    }
    if (tempAge2 != NULL)
        tempAge2->nextAge = n;
    n->nextAge = tempAge;

    while ((tempName != NULL) && (tempName->name < name)) {
        tempName2 = tempName;
        tempName = tempName->nextName;
    }
    if (tempName2 != NULL)
        tempName2->nextName = n;
    n->nextName = tempName;
    
    return head;
}

void displayName(node *head) {
    node *temp = head;
    while (temp != NULL) {
        cout << temp->name << " ";
        temp = temp->nextName;
    }
    cout << endl;
}

void displayAge(node *head) {
    node *temp = head;
    while (temp != NULL) {
        cout << temp->age << " ";
        temp = temp->nextAge;
    }
    cout << endl;
}

int main() {
    node *head = NULL;
    head = addNode(head, "Alice", 2);
    head = addNode(head, "Nitin", 20);
    head = addNode(head, "Trevor", 45);
    head = addNode(head, "Franklin", 27);
    head = addNode(head, "Michael", 50);
    head = addNode(head, "Mohit", 20);
    displayName(head);
    displayAge(head);
}