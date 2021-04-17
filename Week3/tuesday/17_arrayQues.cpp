#include<bits/stdc++.h>
using namespace std;

void differ(int arr[], int n)
{
    sort(arr,arr + n);
    int x,min = INT_MAX;
    for(int i=0;i<n-1;i++)
    {
        x = arr[i+1] - arr[i];
        if(x < min)
        min =x;
    }
    cout<<min;
}

int main()
{
    int arr[] = {7,9,5,6,3,2};
    int n = sizeof( arr)/sizeof(int);
    differ(arr,n);
    return 1;
}