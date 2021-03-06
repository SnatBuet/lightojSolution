#include<vector>
#include<iostream>
#include<queue>
#include <functional>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstdio>
#include<stack>
#include<cmath>
#include<utility>
#include<list>
#include<set>
#include <string>
#include<map>
#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define PI acos(-1.0)
#define inf 1<<30
#define EPS 1e-9
#define DI(n) int n;scanf("%d",&n)
#define DII(a,b) int a,b;scanf("%d %d",&a,&b)
#define DIII(a,b,c) int a,b,c;scanf("%d %d %d",&a,&b,&c)
using namespace std;
typedef pair<int, int> iPair;
class Graph {
	int V;
	list< pair<int, int> > *adj;
public:
	Graph(int v);
	void addEdge(int u, int v, int w);
	int shortestPath(int s);
};
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

int Graph::shortestPath(int src)
{
	priority_queue< iPair, vector <iPair>, greater<iPair> > pq;

	vector<int> dist(V, inf);
	pq.push(make_pair(0, src));
	dist[src] = 0;
	int f = 0;

	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		list< pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			int v = (*i).first;
			if (v == V - 1) {
				f = 1;
			}
			int weight = (*i).second;
			if (dist[v] > dist[u] + weight)
			{
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	if (f == 0) {
		return -1;
	}
	return dist[V-1];
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n, m;
		scanf("%d%d", &n, &m);
		Graph g(n);
		for (int j = 0; j < m; j++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			g.addEdge(u-1, v-1, w);
		}
		if (g.shortestPath(0) == -1) {
			printf("Case %d: Impossible\n", i + 1);
		}
		else {
			printf("Case %d: %d\n", i + 1, g.shortestPath(0));
		}
	}
	return 0;
}
