//bellman ford

#include <bits/stdc++.h>
#include <vector>
#include <iterator>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

class Edge {
    int src, dest, weight;
};
 
class Graph {
    int V, E;
    Edge* edge;
};
 
Graph* createGraph(int V, int E)
{
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}
 
void printArr(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
    printf("%d \t\t %d\n", i, dist[i]);
}

void bellman_ford(Graph* g, int src)
{
	int V = g->V;
	int E = g->E;
	int dist[V];
	
	for(int i=0;i<V;i++)
	dist[i] = INT_MAX;
	
	dist[src] = 0;
	
	for(int i=1;i<=V-1;i++)
	{
		for(int j=0;i<E;j++)
		{
			int u = g->edge[j].src;
			int v = g->edge[j].dest;
			int weight = g->edge[j].weight;
			if(dist[u] != INT_MAX && dist[v] > dist[u] + weight)
			dist[v] = dist[u] + weight;
 		}
	}
	
	for(int i=0;i<E;i++)
	{
		int u = g->edge[i].src;
		int v = g->edge[i].dest;
		int weight = g->edge[i].weight;
		if(dist[u] != INT_MAX && dist[v] > dist[u] + weight)
		{
			cout<<"negative cycle";
			return;
		}
	}
	cout<<"hello";
	printArr(dist, V);
}

int main()
{
    int V = 5; 
    int E = 8; 
    Graph graph;
	graph.createGraph(V, E);
 
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;
 
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;
 
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;
 
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;
 
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;
    
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;
 
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;
 
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;
 
    bellman_ford(graph, 0);
 
    return 0;
}
