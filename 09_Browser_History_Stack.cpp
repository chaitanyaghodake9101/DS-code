#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> history;
    string url;
    int ch;

    do {
        cout << "\n1.Visit New Page\n2.Go Back\n3.Current Page\n4.Show History\n5.Exit\n";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter URL: ";
                cin >> url;
                history.push(url);
                cout << "Page visited\n";
                break;
            case 2:
                if (history.empty())
                    cout << "No previous page\n";
                else {
                    history.pop();
                    cout << "Went back successfully\n";
                }
                break;
            case 3:
                if (history.empty())
                    cout << "No current page\n";
                else
                    cout << "Current Page: " << history.top() << endl;
                break;
            case 4: {
                stack<string> temp = history;
                while (!temp.empty()) {
                    cout << temp.top() << endl;
                    temp.pop();
                }
                break;
            }
            case 5: break;
            default: cout << "Invalid choice\n";
        }
    } while (ch != 5);

    return 0;
}
