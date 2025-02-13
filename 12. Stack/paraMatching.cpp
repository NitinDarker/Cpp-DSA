#include <iostream>
#include "stack.cpp"
using namespace std;

bool parenthesisMatch(string str) {
    Stack st;
    st.create(str.length());

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            st.push(str[i]);
        } else if (str[i] == ')') {
            if (st.isEmpty())
                return false;
            st.pop();
        }
    }
    if (st.isEmpty())
        return true;
    else
        return false;
}

int main() {
    cout << "Input a string: ";
    string str;
    cin >> str;
    cout << parenthesisMatch(str) << endl;
    return 0;
}