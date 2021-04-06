#include<bits/stdc++.h>
using namespace std;

void odd(int arr[], int n)
{
    int i=2,a;
    a = arr[0]^arr[1];
    while(i<n)
    {
        a = a^arr[i];
        ++i;
    }
    cout<<"\n"<<a<<"\n\n";
}

int main()
{
    int arr[] = {5,6,6,8,9,6,9,5,8};
    int n = sizeof(arr)/sizeof(int);
    odd(arr,n);
    return 1;
}