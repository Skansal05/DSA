#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int total_elements = n + 1;
    int sum = total_elements*(total_elements+1) / 2;
    int actual_sum = 0;

    for (int i = 0; i < n; i++)
    {
        actual_sum += arr[i];
    }
    int mising_number = sum - actual_sum;
    cout<<"Missing number is "<<mising_number;

    return 0;
}