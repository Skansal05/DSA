#include<iostream>
using namespace std;

int main()
{
    int arr[2][3] = {{1,2,3},{4,5,6}};

    // Calculate sum of each row
    cout << "Sum of each row:\n";
    for (int i = 0; i < 2; i++) {
        int rowSum = 0;
        for (int j = 0; j < 3; j++) {
            rowSum += arr[i][j];
        }
        cout << "Row " << i+1 << ": " << rowSum << "\n";
    }

    // Calculate sum of each column
    cout << "Sum of each column:\n";
    for (int j = 0; j < 3; j++) {
        int colSum = 0;
        for (int i = 0; i < 2; i++) {
            colSum += arr[i][j];
        }
        cout << "Column " << j+1 << ": " << colSum << "\n";
    }
    return 0;
}