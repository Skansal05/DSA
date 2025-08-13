#include<iostream>
using namespace std;

int main()
{
     int arr[7] = {64,34,25,12,22,11,90};
    for (int i = 0; i < 7-1; i++)
    {
        for (int j = 0; j <= 7-2; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < 7; i++)
    {
        cout<<"\t"<<arr[i];
    }
    return 0;
}