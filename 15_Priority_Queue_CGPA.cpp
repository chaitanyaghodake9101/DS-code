#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    float cgpa;
};

class PriorityQueue {
    Student s[100];
    int n;

public:
    PriorityQueue() {
        n = 0;
    }

    void insert() {
        if (n == 100) {
            cout << "Queue is Full\n";
            return;
        }

        cout << "Enter Roll No, Name and CGPA: ";
        cin >> s[n].roll >> s[n].name >> s[n].cgpa;
        n++;
        cout << "Student inserted\n";
        display();
    }

    bool remove() {
        if (n == 0) {
            cout << "Queue is Empty\n";
            return false;
        }

        int maxIndex = 0;
        for (int i = 1; i < n; i++) {
            if (s[i].cgpa > s[maxIndex].cgpa)
                maxIndex = i;
        }

        cout << "Processed Student: " << s[maxIndex].name << endl;
        for (int i = maxIndex; i < n - 1; i++)
            s[i] = s[i + 1];
        n--;
        display();
        return true;
    }

    void display() {
        if (n == 0) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "\nPriority Queue\n";
        for (int i = 0; i < n; i++)
            cout << s[i].roll << " " << s[i].name << " " << s[i].cgpa << endl;
    }
};

int main() {
    PriorityQueue q;
    int ch, count = 0;

    do {
        cout << "\n1.Insert Student\n2.Delete Highest CGPA\n3.Display Queue\n4.Count Processed Students\n5.Exit\n";
        cin >> ch;

        switch (ch) {
            case 1: q.insert(); break;
            case 2:
                if (q.remove())
                    count++;
                break;
            case 3: q.display(); break;
            case 4: cout << "Students Processed: " << count << endl; break;
            case 5: break;
            default: cout << "Invalid choice\n";
        }
    } while (ch != 5);

    return 0;
}
