#include<iostream>
using namespace std;

int main()
{
    int arr[3][3] = {{0,0,2},{6,0,0},{0,0,9}};
    int brr[3][3] = {{0,0,2},{6,0,0},{0,0,9}};
    int r = 3;
    int c = 3;
    int crr[3][3];

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            crr[i][j] = arr[i][j] + brr[i][j];
        }
    }

    cout<<"Addition of array: "<<endl;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<crr[i][j]<<" ";
        }
            cout<<endl;
    }

    return 0;
}