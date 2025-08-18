#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of the diagonal matrix: ";
    cin >> n;

    int A[n];

    cout << "Enter elements: \n";
    for (int i = 0; i < n; i++) {
        cout << "Element at (" << i+1 << "," << i+1 << "): ";
        cin >> A[i];
    }

    // Display the matrix
    cout <<"\nThe diagonal matrix is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cout << A[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    return 0;
}