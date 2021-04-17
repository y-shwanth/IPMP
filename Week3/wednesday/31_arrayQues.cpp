#include<bits/stdc++.h>
using namespace std;

void move0toend(int arr[], int n)
{
    int zeroindex = -1;
    int i,count=0;
    for(i=0;i<n;i++)
    {
        if(arr[i] != 0)
        arr[count++] = arr[i];
    }
    for(i = count;i<n;i++)
    arr[i] = 0;

    for(i=0;i<n;i++)
    cout<<arr[i]<<" ";
}

int main()
{
    int arr[] = {8,9,0,2,7,1,0,0,19,87,0,23,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    move0toend(arr,n);
    return 1;
}