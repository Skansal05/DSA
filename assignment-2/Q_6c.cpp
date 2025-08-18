#include<iostream>
using namespace std;

int main()
{
    int arr[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    int brr[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    int r = 3;
    int c = 3;
    int crr[3][3];

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            crr[i][j] = 0;

            for (int k = 0; k < 3; k++)
            {
                crr[i][j] += arr[i][k] * brr[k][j];
            }
        }
    }

    cout<<"Multiplication of array: "<<endl;
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