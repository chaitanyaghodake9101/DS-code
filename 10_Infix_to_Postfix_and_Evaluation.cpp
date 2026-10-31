#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;

int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (isdigit(ch)) {
            postfix += ch;
            postfix += ' ';
        } else if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }
            if (!st.empty())
                st.pop();
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            while (!st.empty() && st.top() != '(' &&
                   (priority(st.top()) > priority(ch) ||
                   (priority(st.top()) == priority(ch) && ch != '^'))) {
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        postfix += ' ';
        st.pop();
    }
    return postfix;
}

int evaluatePostfix(string postfix) {
    stack<int> st;

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            st.push(ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            if (st.size() < 2)
                return 0;

            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            switch (ch) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/':
                    if (b == 0) {
                        cout << "Division by zero\n";
                        return 0;
                    }
                    st.push(a / b);
                    break;
                case '^': st.push((int)pow(a, b)); break;
            }
        }
    }

    return st.empty() ? 0 : st.top();
}

int main() {
    string infix;
    cout << "Enter infix expression (single-digit operands): ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;
    cout << "Result: " << evaluatePostfix(postfix) << endl;

    return 0;
}
