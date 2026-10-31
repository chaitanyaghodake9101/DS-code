#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    string division;
};

int main() {
    Student s[100], temp;
    int n, comparisons = 0;

    cout << "Enter number of students: ";
    cin >> n;

    if (n < 1 || n > 100) {
        cout << "Invalid number of students\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter Roll No, Name and Division: ";
        cin >> s[i].roll >> s[i].name >> s[i].division;
    }

    string searchName;
    cout << "Enter name to search: ";
    cin >> searchName;

    bool found = false;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (s[i].name == searchName) {
            cout << "Student Found\n";
            cout << s[i].roll << " " << s[i].name << " " << s[i].division << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Student not found\n";
    cout << "Linear Search Comparisons: " << comparisons << endl;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].roll > s[j + 1].roll) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    int roll, low = 0, high = n - 1;
    comparisons = 0;
    found = false;

    cout << "Enter Roll No to search: ";
    cin >> roll;

    while (low <= high) {
        int mid = (low + high) / 2;
        comparisons++;

        if (s[mid].roll == roll) {
            cout << "Student Found\n";
            cout << s[mid].roll << " " << s[mid].name << " " << s[mid].division << endl;
            found = true;
            break;
        } else if (s[mid].roll < roll) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found)
        cout << "Student not found\n";
    cout << "Binary Search Comparisons: " << comparisons << endl;

    return 0;
}
