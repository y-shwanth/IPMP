#include<bits/stdc++.h>
#include<vector>
using namespace std;

void ksort(int arr[], int n, int k)
{
    priority_queue<int,vector<int>,greater<int>> pq(arr, arr + k + 1);
    int i=k+1,j=0;
    while(i<n)
    {
        arr[j] = pq.top();
        pq.pop();
        pq.push(arr[i]);
        ++i;
        ++j;
    }
    while(j<n)
    {
        arr[j] = pq.top();
        pq.pop();
        ++j;
    }

    for(i=0;i<n;i++)
    cout<<arr[i]<<" ";
}

int main()
{
    int arr[] = {6,5,3,2,8,10,9};
    int n = sizeof(arr)/sizeof(int);
    int k=3;
    ksort(arr,n,k);
}