#include <iostream>
using namespace std;

int main() {
    float a[100], b[100], temp;
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    if (n < 1 || n > 100) {
        cout << "Invalid number of students\n";
        return 0;
    }

    cout << "Enter percentages: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex])
                minIndex = j;
        }
        temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }

    cout << "\nSelection Sort (Ascending): ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (b[j] > b[j + 1]) {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }

    cout << "\nBubble Sort (Ascending): ";
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";

    cout << "\nTop Five Scores:\n";
    for (int i = n - 1; i >= 0 && i >= n - 5; i--)
        cout << b[i] << " ";

    return 0;
}
