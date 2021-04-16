#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void segEVENodd(int arr[], int n)
{
    int i=0,j=0;
    while(i<n && j<n)
    {
        if(arr[i]%2 != 0)
        {
            while(j<n)
            {
                if(arr[j]%2 == 0)
                {
                    swap(&arr[i],&arr[j]);
                    break;
                }
                ++j;
            }
        }
        ++i;
        ++j;
    }
    for(i=0;i<n;i++)
    cout<<arr[i]<<" ";
}

int main()
{
    int arr[] = {12, 34, 45, 9, 8, 90, 3};
    int n = sizeof( arr)/sizeof(int);
    segEVENodd(arr,n);
    return 1;
}