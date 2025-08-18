#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of the lower triangular matrix: ";
    cin >> n;
    int size = n*(n + 1) / 2;
    int arr[size];

    cout << "Enter elements for lower triangular matrix (row-wise):\n";
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "Element at (" << i+1 << "," << j+1 << "): ";
            cin >> arr[k];
            k++;
        }
    }

    // Display the matrix
    cout << "\nLower triangular matrix is:\n";
    k = 0;
    for (int i = 0; i < n; i++)
    {
       for (int j = 0; j < n; j++)
        {
            if (j <= i) {
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
