#include<bits/stdc++.h>
using namespace std;

void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    return;
}

void nexthighnumber(int arr[], int n)
{
    int x,i = n-1;
    while(i>0)
    {
        if(arr[i-1] < arr[i])
        {
            break;
        }
        --i;
    }
    if(i == 0)
    {
        cout<<"NOT POSSIBLE";
        return;
    }
    else
    {
        x = i-1;
        i = n-1;
        while(i != x)
        {
            if(arr[x] < arr[i])
            {
                break;
            }
            --i;
        }
        swap(&arr[x],&arr[i]);

        sort(arr + (x+1), arr + n);
        for(i=0;i<n;i++)
        {
            cout<<arr[i];
        }
        return;
    }
}

int main()
{
    // number is 8934172641
    int arr[] = {1,2,3,4,5,6,7,8,4,9,8,7,6,5,4,3,2,1}; 
    //{8,9,3,4,1,7,2,6,4,1};
    int n = sizeof(arr)/sizeof(int);
    nexthighnumber(arr,n);
    return 1;
}