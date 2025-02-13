#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class queue {
  public:
    Node *start;
    Node *end;
    int currSize;

    queue() {
        start = NULL;
        end = NULL; // empty queue
        currSize = 0;
    }

    bool isEmpty();
    bool isFull();
    void push(int data);
    int pop();
    int front();
    int back();
    int size();
    void display();
};

int main() {

    return 0;
}