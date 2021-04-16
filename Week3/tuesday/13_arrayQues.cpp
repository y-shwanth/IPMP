#include<bits/stdc++.h>
using namespace std;

void subsq3(int arr[], int n)
{
    int count=0;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i+1]>arr[i])
        {
            ++count;
            if(count == 2)
            {
                cout<<" "<<arr[i+1];
                break;
            }
            cout<<arr[i]<<" "<<arr[i+1];
        }
    }
}

int main()
{
    int arr[] = {12,11,10,5,6,2,30};
    int n = sizeof(arr)/sizeof(int);
    subsq3(arr,n);
    return 1;
}