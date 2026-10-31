#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    cout << "\nConversion Stack:\n";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
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
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!st.empty() && st.top() != '(' && priority(st.top()) >= priority(ch)) {
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }
            st.push(ch);
        }

        cout << "After " << ch << ": ";
        stack<char> temp = st;
        string contents = "";
        while (!temp.empty()) {
            contents = temp.top() + contents;
            temp.pop();
        }
        cout << contents << endl;
    }

    while (!st.empty()) {
        postfix += st.top();
        postfix += ' ';
        st.pop();
    }

    return postfix;
}

int evaluatePostfix(string postfix, double tuition, double hostel,
                    double examFee, double scholarship) {
    stack<double> st;

    cout << "\nEvaluation Stack:\n";

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        if (ch == 'T') st.push(tuition);
        else if (ch == 'H') st.push(hostel);
        else if (ch == 'E') st.push(examFee);
        else if (ch == 'S') st.push(scholarship);
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (st.size() < 2)
                return 0;

            double b = st.top();
            st.pop();
            double a = st.top();
            st.pop();

            if (ch == '+') st.push(a + b);
            else if (ch == '-') st.push(a - b);
            else if (ch == '*') st.push(a * b);
            else {
                if (b == 0) {
                    cout << "Division by zero\n";
                    return 0;
                }
                st.push(a / b);
            }
        }

        cout << "After " << ch << ": ";
        stack<double> temp = st;
        string contents = "";
        while (!temp.empty()) {
            contents = to_string(temp.top()) + " " + contents;
            temp.pop();
        }
        cout << contents << endl;
    }

    return st.empty() ? 0 : (int)st.top();
}

int main() {
    string infix;
    double tuition, hostel, examFee, scholarship;

    cout << "Use T=Tuition, H=Hostel, E=ExamFee, S=Scholarship\n";
    cout << "Enter fee formula: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "\nPostfix Expression: " << postfix << endl;

    cout << "Enter Tuition: ";
    cin >> tuition;
    cout << "Enter Hostel: ";
    cin >> hostel;
    cout << "Enter ExamFee: ";
    cin >> examFee;
    cout << "Enter Scholarship: ";
    cin >> scholarship;

    double total = evaluatePostfix(postfix, tuition, hostel, examFee, scholarship);
    cout << fixed << setprecision(2);
    cout << "\nFinal Payable Fees: " << total << endl;

    return 0;
}
