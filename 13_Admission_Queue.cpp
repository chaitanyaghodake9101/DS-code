#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int ch, token;

    do {
        cout << "\n1.Enqueue\n2.Dequeue\n3.Display Front and Rear\n4.Display Queue\n5.Exit\n";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter student token number: ";
                cin >> token;
                q.push(token);
                cout << "Student added\n";
                break;
            case 2:
                if (q.empty())
                    cout << "Queue is Empty\n";
                else {
                    cout << "Processed Token: " << q.front() << endl;
                    q.pop();
                }
                break;
            case 3:
                if (q.empty())
                    cout << "Queue is Empty\n";
                else {
                    cout << "Front: " << q.front() << endl;
                    cout << "Rear: " << q.back() << endl;
                }
                break;
            case 4: {
                queue<int> temp = q;
                while (!temp.empty()) {
                    cout << temp.front() << " ";
                    temp.pop();
                }
                cout << endl;
                break;
            }
            case 5: break;
            default: cout << "Invalid choice\n";
        }
    } while (ch != 5);

    return 0;
}
