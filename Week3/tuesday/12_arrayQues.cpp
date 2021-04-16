#include<bits/stdc++.h>
using namespace std;

void tworepeat(int arr[], int n)
{
    int count[n-1];
    for(int i=0;i<n;i++)
    {
        if(count[arr[i]]==1)
        cout<<arr[i]<<" ";
        else
        ++count[arr[i]];
    }
    return;
}

int main()
{
    int arr[] = {4,6,2,1,4,5,2,3};
    int n = sizeof(arr)/sizeof(int);
    tworepeat(arr,n);
    return 1;
}