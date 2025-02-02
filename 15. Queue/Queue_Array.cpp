#include <iostream>
using namespace std;

class queue {
  private:
    int *arr;     // Queue Array
    int maxSize;  // Maximum capacity of the queue
    int currSize; // No. of elements in the queue
    int start;    // Points to the first element
    int end;      // Points to the last element

  public:
    // Constructor
    queue(int size) {
        maxSize = size;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }

    bool isEmpty();
    bool isFull();
    void push(int n); // Pushes an element at the end
    int pop();        // Pops an element from the front
    int front();      // Returns the element at the start
    int back();       // Returns the element at the end
    int size();       // Returns the size of the queue
    void display();   // Displays the elements in the queue
};

bool queue::isEmpty() {
    if (currSize == 0) {
        return true;
    }
    return false;
}

bool queue::isFull() {
    if (currSize == maxSize) {
        return true;
    }
    return false;
}

// Enqueue operation on queue
void queue::push(int n) {
    if (isFull()) {
        cout << "Cannot Push! Queue is full" << endl;
        return;
    }
    end = (end + 1) % maxSize;
    arr[end] = n;
    if (start == -1) {
        start = 0;
    }
    currSize++;
}

// Dequeue operation on queue
int queue::pop() {
    if (isEmpty()) {
        cout << "Cannot Pop! Queue is empty" << endl;
        return -1;
    }
    int n = arr[start];
    start = (start + 1) % maxSize;
    currSize--;
    return n;
}

int queue::front() {
    if (isEmpty()) {
        cout << "Queue is empty" << " ";
        return -1;
    }
    return arr[start];
}

int queue::back() {
    if (isEmpty()) {
        cout << "Queue is empty" << " ";
        return -1;
    }
    return arr[end];
}

int queue::size() {
    return currSize;
}

void queue::display() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    int i = start;
    while (i != end) { // Traversing the array
        cout << arr[i] << " ";
        i = (i + 1) % maxSize;
    }
    cout << arr[end] << endl;
}

int main() {

    // Initialize the queue using array
    queue q(5);
    q.push(10); // 10
    q.push(20); // 10 20
    q.push(30); // 10 20 30
    q.push(40); // 10 20 30 40
    q.push(50); // 10 20 30 40 50
    q.display();
    cout << "The Front element of the Queue is " << q.front() << endl;
    cout << "The Back element of the Queue is " << q.back() << endl;
    cout << "The Size of the Queue is " << q.size() << endl;
    q.pop();
    cout << "The Front element of the Queue is " << q.front() << endl;
    cout << "The Back element of the Queue is " << q.back() << endl;
    cout << "The Size of the Queue is " << q.size() << endl;
    cout << "Is the Queue Empty? " << q.isEmpty() << endl;
    cout << "Is the Queue Full? " << q.isFull() << endl;
    q.pop();
    q.pop();
    q.display();

    return 0;
}