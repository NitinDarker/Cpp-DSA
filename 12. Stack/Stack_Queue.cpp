// Stack using only one Queue
#include <iostream>
#include <queue>
using namespace std;

class stack {
    queue<int> q;

  public:
    // Time Complexity -> O(n)
    void push(int x) {
        // Adjust the queue according to stack working
        int size = q.size();
        q.push(x);

        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    // Time Complexity -> O(1)
    int pop() {
        if (q.empty())
            return -1;
        int x = q.front();
        q.pop();
        return x;
    }

    // Time Complexity -> O(1)
    int top() {
        if (q.empty())
            return -1;
        return q.front();
    }

    // Time Complexity -> O(1)
    int size() {
        return q.size();
    }
};

int main() {
    stack s;
    cout << s.pop() << endl;
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(1);
    s.push(0);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;
    return 0;
}