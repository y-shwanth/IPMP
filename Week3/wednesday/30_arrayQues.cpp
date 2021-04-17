#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort_012(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    int mid = 0;
    
    while(mid <= high)
    {
        if(arr[mid] == 0)
        {
            swap(&arr[low++],&arr[mid++]);
        }
        else if(arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(&arr[mid],&arr[high--]);
        }
    }
}

int main()
{
    int arr[] = {2,1,0,1,0,0,1,2,2,0,1,1,1,2,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort_012(arr,n);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    return 1;
}