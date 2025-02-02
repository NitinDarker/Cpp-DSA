// Stack using Array
#include <iostream>
using namespace std;

struct stack { // Stack data structure
  private:
    int *arr; // Stack Array
    int size; // Size of the stack Array
    int top;  // Points to index of top element

  public:
    // Constructor
    stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    // Member functions
    bool isEmpty();
    bool isFull();
    void push(int data);
    int pop();
    void display();      // Display the elements in a stack
    int peek(int index); // Peek at any index of the stack
    int topElement();    // Peek the top element of stack
};

bool stack::isEmpty() {
    if (top == -1) {
        return true;
    }
    return false;
}

bool stack::isFull() {
    if (top == size - 1) {
        return true;
    }
    return false;
}

void stack::push(int data) {
    if (isFull()) {
        cout << "Cannot Push! Stack is Full" << endl;
        return;
    }
    arr[++top] = data;
}

int stack::pop() {
    if (isEmpty()) {
        cout << "Cannot Pop! Stack is Empty" << endl;
        return -1;
    }
    return arr[top--];
}

void stack::display() {
    for (int i = top; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int stack::peek(int index) {
    if (index >= size || index < 0) {
        cout << "Invalid index" << endl;
        return -1;
    }
    if (index > top) {
        cout << "Empty" << endl;
        return -1;
    }
    return arr[index];
}

int stack::topElement() {
    if (isEmpty()) {
        cout << "Stack is Empty!" << endl;
        return -1;
    }
    return arr[top];
}

int main() {
    int stack_size = 6;
    stack s(stack_size);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(1);
    s.push(0);
    s.display();
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    s.display();
}