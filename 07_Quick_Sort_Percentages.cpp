#include <iostream>
using namespace std;

int partition(float a[], int low, int high) {
    float pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            float temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    float temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;
    return i + 1;
}

void quickSort(float a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main() {
    float a[100];
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    if (n < 1 || n > 100) {
        cout << "Invalid number of students\n";
        return 0;
    }

    cout << "Enter percentages: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    quickSort(a, 0, n - 1);

    cout << "Sorted Percentages:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
