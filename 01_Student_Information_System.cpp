#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    float cgpa;
};

class StudentSystem {
    Student s[100];
    int n;

public:
    StudentSystem() {
        n = 0;
    }

    void insertStudent() {
        int pos;
        cout << "Enter position: ";
        cin >> pos;

        if (pos < 1 || pos > n + 1 || n == 100) {
            cout << "Invalid position\n";
            return;
        }

        for (int i = n; i >= pos; i--)
            s[i] = s[i - 1];

        cout << "Enter Roll No, Name and CGPA: ";
        cin >> s[pos - 1].roll >> s[pos - 1].name >> s[pos - 1].cgpa;
        n++;
        cout << "Student inserted successfully\n";
    }

    void deleteStudent() {
        int roll;
        cout << "Enter Roll No to delete: ";
        cin >> roll;

        for (int i = 0; i < n; i++) {
            if (s[i].roll == roll) {
                for (int j = i; j < n - 1; j++)
                    s[j] = s[j + 1];
                n--;
                cout << "Student deleted successfully\n";
                return;
            }
        }
        cout << "Student not found\n";
    }

    void searchStudent() {
        int roll;
        cout << "Enter Roll No to search: ";
        cin >> roll;

        for (int i = 0; i < n; i++) {
            if (s[i].roll == roll) {
                cout << s[i].roll << " " << s[i].name << " " << s[i].cgpa << endl;
                return;
            }
        }
        cout << "Student not found\n";
    }

    void display() {
        if (n == 0) {
            cout << "No students found\n";
            return;
        }
        for (int i = 0; i < n; i++)
            cout << s[i].roll << " " << s[i].name << " " << s[i].cgpa << endl;
    }
};

int main() {
    StudentSystem obj;
    int ch;

    do {
        cout << "\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n";
        cin >> ch;

        switch (ch) {
            case 1: obj.insertStudent(); break;
            case 2: obj.deleteStudent(); break;
            case 3: obj.searchStudent(); break;
            case 4: obj.display(); break;
            case 5: break;
            default: cout << "Invalid choice\n";
        }
    } while (ch != 5);

    return 0;
}
