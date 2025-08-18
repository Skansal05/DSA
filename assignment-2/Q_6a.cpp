#include<iostream>
using namespace std;

int main()
{
    int arr[3][3] = {{0,0,2},{6,0,0},{0,0,9}};
    int r = 3;
    int c = 3;
    cout<<"Original array: "<<endl;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<arr[i][j]<<" ";
        }
            cout<<endl;
    }
    cout<<"Transpose of array: "<<endl;

    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
            cout<<arr[j][i]<<" ";
        }
            cout<<endl;
    }
    return 0;
}