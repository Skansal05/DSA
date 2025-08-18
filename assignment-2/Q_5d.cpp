#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of the upper triangular matrix: ";
    cin >> n;
    int size = n*(n + 1) / 2;
    int arr[size];

    cout << "Enter elements for upper triangular matrix (row-wise):\n";
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout << "Element at (" << i+1 << "," << j+1 << "): ";
            cin >> arr[k];
            k++;
        }
    }

    // Display the matrix
    cout << "\nUpper triangular matrix is:\n";
    k = 0;
    for (int i = 0; i < n; i++)
    {
       for (int j = 0; j < n; j++)
        {
            if (i <= j) {
                cout << arr[k] << " ";
                k++;
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    return 0;
}