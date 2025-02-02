#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Initialize the Queue using STL
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    cout << "The Front element of the Queue is " << q.front() << endl;
    cout << "The Back element of the Queue is " << q.back() << endl;
    cout << "The Size of the Queue is " << q.size() << endl;
    q.pop();
    cout << "The Front element of the Queue is " << q.front() << endl;
    cout << "The Back element of the Queue is " << q.back() << endl;
    cout << "The Size of the Queue is " << q.size() << endl;
    cout << "Is the Queue Empty? " << q.empty() << endl;

    // Operations of Queue ->>
    // push
    // pop
    // front -> return the front element of queue
    // back -> return the back element of queue
    // size -> return the size of queue
    // empty -> return 1 if queue is empty
    // emplace -> similar to push but better for complex data types

    return 0;
}