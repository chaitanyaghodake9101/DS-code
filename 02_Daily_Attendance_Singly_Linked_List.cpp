#include <iostream>
#include <cctype>
using namespace std;

struct Node {
    int day;
    char status;
    Node* next;
};

class AttendanceSystem {
    Node* head;
    int dayCounter;

public:
    AttendanceSystem() {
        head = NULL;
        dayCounter = 1;
    }

    void insertAttendance(char status) {
        status = toupper(status);
        if (status != 'P' && status != 'A') {
            cout << "Invalid status\n";
            return;
        }

        Node* newNode = new Node();
        newNode->day = dayCounter++;
        newNode->status = status;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Attendance recorded\n";
    }

    void updateAttendance(int day, char status) {
        status = toupper(status);
        if (status != 'P' && status != 'A') {
            cout << "Invalid status\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            if (temp->day == day) {
                temp->status = status;
                cout << "Attendance updated\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Day not found\n";
    }

    void calculateAttendance() {
        int p = 0, a = 0;
        Node* temp = head;
        while (temp != NULL) {
            if (temp->status == 'P')
                p++;
            else
                a++;
            temp = temp->next;
        }
        cout << "Present Days: " << p << endl;
        cout << "Absent Days: " << a << endl;
    }

    void displayAttendance() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "No attendance records\n";
            return;
        }
        while (temp != NULL) {
            cout << "Day " << temp->day << ": " << temp->status << endl;
            temp = temp->next;
        }
    }
};

int main() {
    AttendanceSystem obj;
    int ch, day;
    char status;

    do {
        cout << "\n1.Insert Attendance\n2.Update Attendance\n3.Calculate Attendance\n4.Display\n5.Exit\n";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter P or A: ";
                cin >> status;
                obj.insertAttendance(status);
                break;
            case 2:
                cout << "Enter day: ";
                cin >> day;
                cout << "Enter new status: ";
                cin >> status;
                obj.updateAttendance(day, status);
                break;
            case 3: obj.calculateAttendance(); break;
            case 4: obj.displayAttendance(); break;
            case 5: break;
            default: cout << "Invalid choice\n";
        }
    } while (ch != 5);

    return 0;
}
