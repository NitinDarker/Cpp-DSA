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

node *append(node *head, int data) {
    if (head == NULL) {
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

void display(node *head) {
    node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Optimized Approach
node *merge_in_sorted(node *headA, node *headB) {

    node *dNode = createNode(0); // Dummy Node
    node *temp1 = headA;         // Temporary pointer to traverse first list
    node *temp2 = headB;         // Temporary pointer to traverse second list
    node *temp = dNode;          // Temporary pointer to traverse new merged list

    while (temp1 != NULL && temp2 != NULL) {
        // Traversing both the list until one of them reaches the end

        // Comparing the data of first node of both the lists
        if (temp1->data < temp2->data) {
            // Node is from 1st list
            temp->next = temp1;
            temp = temp1;
            temp1 = temp1->next;
        } else {
            // Node is from 2nd list
            temp->next = temp2;
            temp = temp2;
            temp2 = temp2->next;
        }
        // Changing the links within the list rather than data in nodes
    }

    if (temp1 == NULL) { // If list 1 is shorter
        temp->next = temp2;
        // Appends the second list as it is
    } else { // If list 2 is shorter or equal
        temp->next = temp1;
        // Appends the first list as it is
    }

    // Dummy node points to the head of the newly merged list
    return dNode->next;
}
// Better Time complexity than Brute force approach using sort function

int main() {
    node *head = NULL;

    head = createNode(6);
    head = append(head, 25);
    head = append(head, 35);
    head = append(head, 45);
    head = append(head, 65);
    head = append(head, 85);

    node *head2 = NULL;
    head2 = createNode(5);
    head2 = append(head2, 20);
    head2 = append(head2, 30);
    head2 = append(head2, 40);
    head2 = append(head2, 60);
    head2 = append(head2, 80);
    head2 = append(head2, 90);
    head2 = append(head2, 100);

    display(head);
    display(head2);

    head = merge_in_sorted(head, head2);
    display(head);
}