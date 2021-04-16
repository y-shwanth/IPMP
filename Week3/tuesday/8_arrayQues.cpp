#include<bits/stdc++.h>
using namespace std;

void find2number(int arr[], int n, int sum)
{
    unordered_set<int> s;
    int temp,i=0;
    while(i<n)
    {
        temp = sum - arr[i];
        if(s.find(temp) != s.end())
        {
            cout<<temp<<" "<<arr[i]<<"\n";
            break;
        }
        s.insert(arr[i]);
        ++i;
    }
    return;
}

int main()
{
    int arr[] = {4,2,3,9,1};
    int n = sizeof(arr)/sizeof(int);
    int sum = 6;
    find2number(arr,n,sum);
    return 1;
}