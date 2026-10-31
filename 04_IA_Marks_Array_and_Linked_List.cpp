#include <iostream>
using namespace std;

struct Node {
    int roll;
    float marks;
    Node* next;
};

int main() {
    int n, roll[100], count = 0;
    float marks[100];
    Node* head = NULL;
    Node* tail = NULL;

    cout << "Enter number of students: ";
    cin >> n;

    if (n < 1 || n > 100) {
        cout << "Invalid number of students\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter Roll No and Marks: ";
        cin >> roll[i] >> marks[i];

        Node* newNode = new Node();
        newNode->roll = roll[i];
        newNode->marks = marks[i];
        newNode->next = NULL;

        if (head == NULL)
            head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "\nArray Representation\n";
    for (int i = 0; i < n; i++) {
        cout << "Index " << i << ": Roll No = " << roll[i]
             << ", Marks = " << marks[i] << endl;
        if (marks[i] > 80)
            count++;
    }

    cout << "\nLinked List Representation\n";
    Node* temp = head;
    int i = 0;
    while (temp != NULL) {
        cout << "Node " << i++ << ": Roll No = " << temp->roll
             << ", Marks = " << temp->marks
             << ", Address = " << temp << endl;
        temp = temp->next;
    }

    cout << "Students scoring above 80: " << count << endl;

    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
