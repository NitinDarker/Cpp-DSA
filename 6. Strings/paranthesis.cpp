#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st; // Creating a stack of char
    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            if (st.empty()) {
                return false;
            }
            switch (ch) {
            case ')':
                if (st.top() != '(') {
                    return false;
                }
                st.pop();
                break;

            case '}':
                if (st.top() != '{') {
                    return false;
                }
                st.pop();
                break;

            case ']':
                if (st.top() != '[') {
                    return false;
                }
                st.pop();
                break;
            }
        }
    }

    if (st.empty()) {
        return true;
    }
    return false;
}

int main() {
    string s = "{[()]}()[";
    cout << isValid(s) << endl;
    return 0;
}