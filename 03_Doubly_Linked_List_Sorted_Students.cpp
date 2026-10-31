#include <iostream>
#include <string>
using namespace std;

struct Node {
    int roll;
    string name;
    float cgpa;
    Node* prev;
    Node* next;
};

class StudentList {
    Node* head;

public:
    StudentList() {
        head = NULL;
    }

    void insertStudent() {
        Node* newNode = new Node();
        cout << "Enter Roll No, Name and CGPA: ";
        cin >> newNode->roll >> newNode->name >> newNode->cgpa;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else if (newNode->roll < head->roll) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL && temp->next->roll < newNode->roll)
                temp = temp->next;

            newNode->next = temp->next;
            newNode->prev = temp;

            if (temp->next != NULL)
                temp->next->prev = newNode;

            temp->next = newNode;
        }
        cout << "Student inserted\n";
    }

    void deleteStudent() {
        int roll;
        cout << "Enter Roll No to delete: ";
        cin >> roll;

        Node* temp = head;
        while (temp != NULL && temp->roll != roll)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Student not found\n";
            return;
        }

        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        delete temp;
        cout << "Student deleted\n";
    }

    void displayForward() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "List is empty\n";
            return;
        }
        while (temp != NULL) {
            cout << temp->roll << " " << temp->name << " " << temp->cgpa << endl;
            temp = temp->next;
        }
    }

    void displayBackward() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "List is empty\n";
            return;
        }
        while (temp->next != NULL)
            temp = temp->next;

        while (temp != NULL) {
            cout << temp->roll << " " << temp->name << " " << temp->cgpa << endl;
            temp = temp->prev;
        }
    }
};

int main() {
    StudentList obj;
    int ch;

    do {
        cout << "\n1.Insert\n2.Delete\n3.Forward Display\n4.Backward Display\n5.Exit\n";
        cin >> ch;

        switch (ch) {
            case 1: obj.insertStudent(); break;
            case 2: obj.deleteStudent(); break;
            case 3: obj.displayForward(); break;
            case 4: obj.displayBackward(); break;
            case 5: break;
            default: cout << "Invalid choice\n";
        }
    } while (ch != 5);

    return 0;
}
