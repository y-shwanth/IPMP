#include <iostream>
#include <vector>
#include <iterator>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

void add_edge(vector<int> e[], int u, int v)
{
    e[u].push_back(v);
    e[v].push_back(u);
}

void dfs(vector<int> e[], int root, vector<bool> &visited)
{
    cout<<root<<" ";
    visited[root] = true;
    for(auto it=e[root].begin();it != e[root].end();it++)
    {
        if(!visited[*it])
        {
            visited[*it] = true;
            dfs(e, *it, visited);
        }
    }
}

int main() {
    vector<int> e[6];
    add_edge(e, 0, 1);add_edge(e, 0, 3);add_edge(e, 0, 4);
    add_edge(e, 1, 2);add_edge(e, 1, 3);add_edge(e, 1, 5);
    add_edge(e, 2, 3);add_edge(e, 2, 4);
    add_edge(e, 3, 4);add_edge(e, 3, 5);
    add_edge(e, 4, 5);
    
    /*
    add_edge(e, 0, 1);
    add_edge(e, 0, 9);
    add_edge(e, 1, 2);
    add_edge(e, 2, 0);
    add_edge(e, 2, 3);
    add_edge(e, 9, 3);
    */
    
    vector<bool> visited(6, false);
    dfs(e, 2, visited);
    
    return 0;
}
