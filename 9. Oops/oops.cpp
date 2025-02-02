#include <iostream>
using namespace std;

class parent {
  public:
    int name;
    int age;

    parent() {
        cout << "This is a parent constructor.." << endl;
    }

    ~parent() {
        cout << "This is a parent destructor.." << endl;
    }

    virtual void greet() {
        cout << "Hello from parent" << endl;
    }
};

class child : public parent {
  public:
    int rollNo;

    child() {
        cout << "This is a child constructor.." << endl;
    }

    ~child() {
        cout << "This is a child destructor.." << endl;
    }

    void greet() {
        cout << "Hello from child" << endl;
    }
};

int main() {
    child a;
    a.greet();

    return 0;
}