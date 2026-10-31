#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string exp;
    stack<char> st;

    cout << "Enter expression: ";
    cin >> exp;

    bool valid = true;

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty()) {
                valid = false;
                break;
            }

            char top = st.top();
            st.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                valid = false;
                break;
            }
        }
    }

    if (!st.empty())
        valid = false;

    if (valid)
        cout << "Parenthesis are Balanced";
    else
        cout << "Parenthesis are Not Balanced";

    return 0;
}
