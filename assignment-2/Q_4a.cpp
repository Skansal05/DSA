#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str1 = "shourya ";
    string str2 = "kansal";

    str1 += str2;

    cout << "Concatenated string: " << str1 << endl;

    return 0;
}