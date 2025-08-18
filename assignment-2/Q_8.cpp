#include<iostream>
using namespace std;

int main()
{
    int arr[] = {1,1,2,2,3,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int found = 0;

        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                found = 1;
                break;
            }
        }
        if (found == 0) count++;
    }
    cout<<"Total distinct elements: "<<count;
    
    return 0;
}