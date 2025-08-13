#include<iostream>
using namespace std;

int main()
{
    int arr[3][3] ={{1,2,0},{6,1,0},{7,5,1}};
    int brr[3][3] ={{1,3,4},{1,3,0},{8,4,1}};

    int crr[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            crr[i][j]=0;
            for(int k=0;k<3;k++)
            {
                crr[i][j]+=arr[i][k]*brr[k][j];
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<crr[i][j]<<" ";
        }
            cout<<endl;
    }

    return 0;
}