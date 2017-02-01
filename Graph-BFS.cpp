#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
	int v;
	vector< vector<int> > adj;
	int *visited, *d; 
public:
	Graph(int);
	void addEdge(int,int);
	void display();
	void displayD();
	void BFS(int);
};

Graph::Graph(int v)
{
	this->v=v;
	adj.resize(v);
	visited=new int[v];
	d=new int[v];
}

void Graph::addEdge(int x,int y)
{
	adj[x].push_back(y);
	adj[y].push_back(x);
}

void Graph::display()
{
	vector<int>::iterator it;
	for (int i = 0; i < v; ++i)
	{
		cout<<i<<"->";
		for (it=adj[i].begin();it!=adj[i].end();it++)
			cout<<*it<<" ";
		cout<<endl;
	}
}

void Graph::BFS(int s)
{
	for(int i=0; i<v; i++)
	{
		visited[i]=0;
		d[i]=0;
	}
	visited[s]=1;
	queue<int> Q;
	Q.push(s);
	while(!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		vector<int> :: iterator i;
		for(i=adj[u].begin(); i!=adj[u].end(); i++)
			if(visited[*i]==0)
			{
				visited[*i]=1;
				d[*i]=d[u]+1;
				Q.push(*i);
			}
	}

}

void Graph::displayD()
{
	for (int i = 0; i < v; ++i)
	{
		cout<<d[i]<<" ";
	}
}

int main()
{
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.display();
	g.BFS(0);
	g.displayD();
	return 0;
}

