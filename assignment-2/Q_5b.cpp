#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of the tridiagonal matrix: ";
    cin >> n;

    int main_diag[n], upper_diag[n-1], lower_diag[n-1];

    cout << "Enter main diagonal elements:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Element at (" << i+1 << "," << i+1 << "): ";
        cin >> main_diag[i];
    }

    cout << "Enter upper diagonal elements:\n";
    for (int i = 0; i < n - 1; i++)
    {
        cout << "Element at (" << i+1 << "," << i+2 << "): ";
        cin >> upper_diag[i];
    }

    cout << "Enter lower diagonal elements:\n";
    for (int i = 0; i < n - 1; i++)
    {
        cout << "Element at (" << i+2 << "," << i+1 << "): ";
        cin >> lower_diag[i];
    }

    // Display the matrix
    cout << "\nThe tridiagonal matrix is:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << main_diag[i] << " ";
            else if (j == i + 1)
                cout << upper_diag[i] << " ";
            else if (i == j + 1)
                cout << lower_diag[j] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    return 0;
}