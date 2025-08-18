#include <iostream>
using namespace std;

void reverseArray(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << " " << arr[i];
    }
    cout << endl;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;

    cout << "Original array: ";
    display(arr, n);

    reverseArray(arr, n);

    cout << "Reversed array: ";
    display(arr, n);

    return 0;
}
