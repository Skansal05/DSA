#include<iostream>
using namespace std;

int main()
{
    int arr[2][3]= {{1,2,3},{4,5,6}};
    cout<<"Transpose of matrix is:\n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<arr[j][i]<<" ";
        }
            cout<<"\n";
    }
    // if matrix of n*n then do it by swapping(temp variable)

    return 0;
}