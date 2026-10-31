#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;
    int ch, token;

    do {
        cout << "\n1.Add Emergency at Front\n2.Add Normal at Rear\n3.Serve Request\n4.Display Deque\n5.Exit\n";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter emergency token number: ";
                cin >> token;
                dq.push_front(token);
                cout << "Emergency request added\n";
                break;
            case 2:
                cout << "Enter normal token number: ";
                cin >> token;
                dq.push_back(token);
                cout << "Normal request added\n";
                break;
            case 3:
                if (dq.empty()) {
                    cout << "No requests to serve\n";
                } else {
                    cout << "Serving token: " << dq.front() << endl;
                    dq.pop_front();
                }
                break;
            case 4:
                if (dq.empty()) {
                    cout << "Deque is Empty\n";
                } else {
                    cout << "Deque: ";
                    for (int id : dq)
                        cout << id << " ";
                    cout << endl;
                }
                break;
            case 5: break;
            default: cout << "Invalid choice\n";
        }
    } while (ch != 5);

    return 0;
}
