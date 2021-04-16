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
        if(arr[i] == 1)
        {
            while(j<n)
            {
                if(arr[j] == 0)
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
    int arr[] = {0, 1, 0, 1, 0, 0, 1, 1, 1, 0};
    int n = sizeof( arr)/sizeof(int);
    segEVENodd(arr,n);
    return 1;
}