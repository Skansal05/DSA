#include<iostream>
using namespace std;

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int lo = 0;
    int hi = size - 1;
    
    while(lo <= hi)
    {
    int mid = (lo + hi)/2;
    if(arr[mid] == target)
        {
            cout<<"Element is present at index "<<mid<<endl;
            break;
        }
        else if(arr[mid] < target)
        {
            lo = mid + 1;
        }   
        else hi = mid - 1;
    }
                return 0;
}