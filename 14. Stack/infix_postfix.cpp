// #include "charStack.cpp"     // File for the declaration of character Stack
// #include "operatorTable.cpp" // File for the declaration of operator Table
#include <iostream>
using namespace std;

string infixToPostfix(string str) {
    string result = "";
    Stack st;
    st.create(str.length());
    opTable table;
    table.create(5);
    setOperators(table);

    for (char ch : str) {
        if ((ch != '+') && (ch != '-') && (ch != '*') && (ch != '/') && (ch != '^') && (ch != '(') && (ch != ')')) {
            result += ch;
        } else {
            if (st.isEmpty()) {
                st.push(ch);
                continue;
            }
            if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                while (st.topElement() != '(') {
                    result += st.topElement();
                    st.pop();
                }
                st.pop();
            } else if ((ch != '^') && (table.getPrecedence(ch) > table.getPrecedence(st.topElement()))) {
                st.push(ch);
            } else if ((ch != '^') && (table.getPrecedence(ch) <= table.getPrecedence(st.topElement()))) {
                while (table.getPrecedence(ch) <= table.getPrecedence(st.topElement())) {
                    result += st.topElement();
                    st.pop();
                }
                st.push(ch);
            } else if ((ch == '^') && (table.getPrecedence(ch) >= table.getPrecedence(st.topElement()))) {
                st.push(ch);
            } else if ((ch == '^') && (table.getPrecedence(ch) < table.getPrecedence(st.topElement()))) {
                while (table.getPrecedence(ch) < table.getPrecedence(st.topElement())) {
                    result += st.topElement();
                    st.pop();
                }
                st.push(ch);
            }
        }
    }
    while (!st.isEmpty()) {
        result += st.topElement();
        st.pop();
    }
    return result;
}

int main() {
    // string exp = "a+b*c+d";
    string exp;
    cout << "Enter an infix expression: " << endl;
    cin >> exp;
    cout << "Infix to Postfix: \n"
         << infixToPostfix(exp) << endl;
    return 0;
}