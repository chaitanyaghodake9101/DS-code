#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    float cgpa;
};

int main() {
    Student s[100], temp;
    int n, shifts = 0;

    cout << "Enter number of students: ";
    cin >> n;

    if (n < 1 || n > 100) {
        cout << "Invalid number of students\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter Roll No, Name and CGPA: ";
        cin >> s[i].roll >> s[i].name >> s[i].cgpa;
    }

    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (s[j].cgpa > s[maxIndex].cgpa)
                maxIndex = j;
        }
        temp = s[i];
        s[i] = s[maxIndex];
        s[maxIndex] = temp;
    }

    cout << "\nSelection Sort Result\n";
    for (int i = 0; i < n; i++)
        cout << s[i].roll << " " << s[i].name << " " << s[i].cgpa << endl;

    for (int i = 1; i < n; i++) {
        temp = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].cgpa < temp.cgpa) {
            s[j + 1] = s[j];
            j--;
            shifts++;
        }
        s[j + 1] = temp;
    }

    cout << "\nInsertion Sort Result\n";
    for (int i = 0; i < n; i++)
        cout << s[i].roll << " " << s[i].name << " " << s[i].cgpa << endl;

    cout << "Total Shifts: " << shifts << endl;
    cout << "\nTop 5 Students\n";
    for (int i = 0; i < n && i < 5; i++)
        cout << s[i].roll << " " << s[i].name << " " << s[i].cgpa << endl;

    return 0;
}
