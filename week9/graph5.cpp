#include <bits/stdc++.h>
#include <vector>
#include <iterator>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

class graph {
    int size;
    vector<int> *adj;
    
    public :
    graph(int size);
    void add_edge(int u, int v);
    bool path_exist(int u, int v);
};

graph::graph(int size)
{
    this->size = size;
    adj = new vector<int>[size];
}

void graph::add_edge(int u, int v)
{
    adj[u].push_back(v);
}

bool graph::path_exist(int u, int v)
{
    bool *visited = new bool[size];
    for(int i=0;i<size;i++)
    visited[i] = false;
    
    vector<int>::iterator it;
    queue<int> q;
    q.push(u);
    visited[u] = true;
    
    while(!q.empty())
    {
        if(q.front() == v)
        return true;
        
        for(it=adj[q.front()].begin();it != adj[q.front()].end();it++)
        {
            if(!visited[*it])
            q.push(*it);
        }
        
        q.pop();
    }
    return false;
}

int main()
{
    graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
    
    if(g.path_exist(1,3))
    cout<<"Yes :)\n";
    else
    cout<<"No :(\n";
    
    if(g.path_exist(3,1))
    cout<<"Yes :)\n";
    else
    cout<<"No :(\n";
    return 0;
}
