#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int*y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int segNegative(int arr[], int n)
{
    int i,j=0;
    for(i=0;i<n;i++)
    {
        if(arr[i] <= 0)
        {
            swap(&arr[i],&arr[j]);
            j++;
        }
    }
    return j;
}

void findpos(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(abs(arr[i]) - 1 < n && arr[abs(arr[i]) - 1] > 0)
        arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
    }
    for(i=0;i<n;i++)
    {
        if(arr[i] > 0)
        {
            cout<<"\nmissing "<<i+1;
            return;
        }
    }
    cout<<"\nmissing "<<n+1;
    return;
}

int main()
{
    int arr[] = {-9,4,2,-6,1,5};
    int n = sizeof(arr)/sizeof(int);
    int start = segNegative(arr,n);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

    findpos(arr + start,n - start);
    return 1;
}