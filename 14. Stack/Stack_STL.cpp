// Stack from inbuilt C++ STL
#include <iostream>
#include <stack>
using namespace std;

int main() {
    // Initialize the stack
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.top() << endl;
    st.pop();
    st.pop();
    cout << st.size() << endl;
    cout << st.empty() << endl;
    st.emplace(40);
    cout << st.top() << endl;

    // Operations on stack ->>
    // push
    // pop
    // top -> returns the top element of the stack
    // size -> return the size os stack
    // empty -> return 1 if stack is empty
    // emplace -> similar to push but better for complex data types
    
    return 0;
}