#include<bits/stdc++.h>
using namespace std;

void find4elements(int arr[], int n, int x)
{
    unordered_map<int,pair <int,int>> mp;
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            mp[arr[i] + arr[j]] = {i,j};
        }
    }
    int sum;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            sum = arr[i] + arr[j];
            if(mp.find(x - sum) != mp.end())
            {
                pair<int,int> p = mp[x - sum];
                if(p.first != i && p.second != j && p.first != j && p.second != i)
                {
                    cout<<arr[i]<<" "<<arr[j]<<" "<<arr[p.first]<<" "<<arr[p.second];
                    return;
                }
            }
        }
    }
}

int main()
{
    int arr[] = {5,33,1,21,3,17,2};
    int n = sizeof(arr)/sizeof(int);
    find4elements(arr,n,11);
    return 1;
}