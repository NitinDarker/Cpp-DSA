#include "stack.cpp"
#include <iostream>
using namespace std;

bool parenthesisMatch(string str) {
    Stack st;
    st.create(str.size());
    for (char ch : str) { // Using for each loop
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.isEmpty())
                return false;
            switch (ch) {
            case ')':
                if (st.topElement() != '(')
                    return false;
                st.pop();
                break;

            case '}':
                if (st.topElement() != '{')
                    return false;
                st.pop();
                break;

            case ']':
                if (st.topElement() != '[')
                    return false;
                st.pop();
                break;
            }
        }
    }
    if (st.isEmpty()) {
        return true;
    }
    return false;
}

int main() {
    cout << "Input a string: ";
    string str;
    cin >> str;
    cout << parenthesisMatch(str) << endl;
    return 0;
}