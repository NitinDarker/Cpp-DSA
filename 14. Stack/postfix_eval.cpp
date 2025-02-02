#include "stack.cpp"
#include <iostream>
#include <math.h>
using namespace std;

float evaluate(string post) {
    Stack st;
    st.create(post.length());
    float result;
    for (char ch : post) {
        if ((ch != '+') && (ch != '-') && (ch != '*') && (ch != '/') && (ch != '^')) {
            st.push(ch - '0');
        } else {
            float a = st.pop();
            float b = st.pop();
            switch (ch) {
            case '+':
                st.push((b + a));
                break;
            case '-':
                st.push((b - a));
                break;
            case '*':
                st.push((b * a));
                break;
            case '/':
                st.push((b / a));
                break;
            case '^':
                st.push((pow(b, a)));
                break;
            default:
                cout << "Invalid Expression!" << endl;
                return -1;
            }
        }
    }
    return st.pop();
}

int main() {
    string exp;
    cout << "Enter an postfix expression to evaluate:" << endl;
    cin >> exp;
    cout << evaluate(exp) << endl;
    return 0;
}