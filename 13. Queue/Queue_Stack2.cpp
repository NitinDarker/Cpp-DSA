// Queue using Two Stacks (Push operation is cheaper)
#include <iostream>
#include <stack>
using namespace std;

class queue {
    stack<int> s1, s2;

  public:
    // Time Complexity -> O(1) => Very cheap
    void push(int x) {
        s1.push(x);
    }

    // Time Complexity -> O(n) => Costly
    int pop() {
        if (!s2.empty()) {
            int x = s2.top();
            s2.pop();
            return x;
        }
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int x = s2.top();
        s2.pop();
        return x;
    }

    // Time Complexity -> O(n) => Costly
    int front() {
        if (!s2.empty())
            return s2.top();
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }

    int size() {
        return (s1.size() + s2.size());
    }

    bool empty() {
        return (s1.empty() && s2.empty());
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