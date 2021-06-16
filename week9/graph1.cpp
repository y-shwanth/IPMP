#include <iostream>
#include <vector>
#include <iterator>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

void print_graph(vector<pair<int,int>> v[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"vertex "<<i;
        for(auto it=v[i].begin();it != v[i].end();it++)
        {
            cout<<" -> "<<(*it).first;
        }
        cout<<"\n\n";
    }
}

int main() {
    vector<pair<int,int>> v[6];
    pair<int,int> p;
    
    p = make_pair(1,5);
    v[0].push_back(p);
    p = make_pair(2,5);
    v[1].push_back(p);
    p = make_pair(5,5);
    v[1].push_back(p);
    p = make_pair(3,5);
    v[2].push_back(p);
    p = make_pair(4,5);
    v[2].push_back(p);
    p = make_pair(0,5);
    v[3].push_back(p);
    p = make_pair(1,5);
    v[3].push_back(p);
    p = make_pair(4,5);
    v[3].push_back(p);
    p = make_pair(0,5);
    v[4].push_back(p);
    p = make_pair(4,5);
    v[5].push_back(p);
    p = make_pair(3,5);
    v[5].push_back(p);
    
    print_graph(v,5);
    
    return 0;
}
