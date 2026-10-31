#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int q[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    void insert(int id) {
        if ((rear + 1) % SIZE == front) {
            cout << "Queue is Full\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear = (rear + 1) % SIZE;
        q[rear] = id;
        cout << "Student ID inserted\n";
    }

    void remove() {
        if (front == -1) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Pass issued to Student ID: " << q[front] << endl;

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is Empty\n";
            return;
        }

        int i = front;
        while (true) {
            cout << q[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int ch, id;

    do {
        cout << "\n1.Insert Student ID\n2.Issue Bus Pass\n3.Display Queue\n4.Exit\n";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter Student ID: ";
                cin >> id;
                q.insert(id);
                break;
            case 2: q.remove(); break;
            case 3: q.display(); break;
            case 4: break;
            default: cout << "Invalid choice\n";
        }
    } while (ch != 4);

    return 0;
}
