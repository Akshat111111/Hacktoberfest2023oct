
#include <bits/stdc++.h>
using namespace std;

// Class to represent a graph
class Graph {
	// No. of vertices'
	int V;
	list<int>* adj;

public:
	// Constructor
	Graph(int V);

	// Function to add an edge to graph
	void addEdge(int u, int v);

	// prints a Topological Sort of
	// the complete graph
	void topologicalSort();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
}
void Graph::topologicalSort()
{
	
	vector<int> in_degree(V, 0);
	for (int u = 0; u < V; u++) {
		list<int>::iterator itr;
		for (itr = adj[u].begin();
			itr != adj[u].end(); itr++)
			in_degree[*itr]++;
	}
	queue<int> q;
	for (int i = 0; i < V; i++)
		if (in_degree[i] == 0)
			q.push(i);

	// Initialize count of visited vertices
	int cnt = 0;
	vector<int> top_order;
	while (!q.empty()) {
		
		int u = q.front();
		q.pop();
		top_order.push_back(u);

		
		list<int>::iterator itr;
		for (itr = adj[u].begin();
			itr != adj[u].end(); itr++)

			// If in-degree becomes zero,
			// add it to queue
			if (--in_degree[*itr] == 0)
				q.push(*itr);

		cnt++;
	}

	// Check if there was a cycle
	if (cnt != V) {
		cout << "There exists a cycle in the graph\n";
		return;
	}

	// Print topological order
	for (int i = 0; i < top_order.size(); i++)
		cout << top_order[i] << " ";
	cout << endl;
}

// Driver program to test above functions
int main()
{
	// Create a graph given in the
	// above diagram
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	cout << "Following is a Topological Sort of\n";
	g.topologicalSort();

	return 0;
}
