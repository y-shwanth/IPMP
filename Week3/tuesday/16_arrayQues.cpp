#include<bits/stdc++.h>
using namespace std;

void differ(int arr[], int n)
{
    int min = INT_MAX,dif;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]< min)
        min = arr[i];
        if(arr[i] > arr[i+1])
        {
            if(dif < arr[i]-min)
            dif = arr[i] - min;
        }
    }
    cout<<dif;
}

int main()
{
    int arr[] = {7,9,5,6,3,2};
    int n = sizeof( arr)/sizeof(int);
    differ(arr,n);
    return 1;
}