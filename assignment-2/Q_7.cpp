#include<iostream>
using namespace std;

int main()
{
    int arr[] = {1,4,6,7,8,5,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                count++;
            }
        }
    }
    cout<<"Total inversion: "<<count;
    
    return 0;
}