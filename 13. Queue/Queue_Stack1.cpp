// Queue using Two Stacks (Push operation is costly)
#include <iostream>
#include <stack>
using namespace std;

class queue {
    stack<int> s1, s2;

  public:
    // Time Complexity -> O(2n) => Only 1 Costly operation
    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Time Complexity -> O(1)
    int pop() {
        if (s1.empty())
            return -1;
        int x = s1.top();
        s1.pop();
        return x;
    }

    // Time Complexity -> O(1)
    int front() {
        if (s1.empty())
            return -1;
        return s1.top();
    }

    int size() {
        return s1.size();
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {
    queue q;
    q.push(10); // 10
    q.push(20); // 10 20
    q.push(30); // 10 20 30
    q.push(40); // 10 20 30 40
    q.push(50); // 10 20 30 40 50
    cout << q.front() << endl;
    cout << q.size() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    q.push(69);
    cout << q.front() << endl;
    cout << q.size() << endl;
    return 0;
}