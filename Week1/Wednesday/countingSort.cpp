#include<bits/stdc++.h>
using namespace std;

int range = 9;

void countsort(int arr[],int n)
{
    int count[range + 1];
    int i,temp,j=0;
    for(i=0;i<(range + 1);i++)
    count[i] = 0;
    for(i=0;i<n;i++)
    {
        ++count[arr[i]];
    }
    
    for(i=0;i<(range + 1);i++)
    {
        temp = count[i];
        while(temp!=0)
        {
            arr[j] = i;
            ++j;
            --temp;
        }
    }

    for(i=0;i<n;i++)
    cout<<arr[i]<<" ";
}

int main()
{
    int arr[] = {3,5,1,2,0,9,6,0,2,5,3,7,1,8};
    int n = sizeof(arr)/sizeof(int);
    countsort(arr,n);
    return 1;
}