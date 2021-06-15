#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[] = {80, 90, 60, 70, 60, 75, 85};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    vector<int> res;
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        while(!s.empty() && arr[s.top()] < arr[i])
        s.pop();
        
        if(s.empty())
        res.push_back(i+1);
        else
        res.push_back(i - s.top());
        
        s.push(i);
    }
    
    for(int i=0;i<res.size();i++)
    cout<<res[i]<<" ";
    return 0;
}
