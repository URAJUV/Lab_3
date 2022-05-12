#include <bits/stdc++.h>
using namespace std;

// A recursive function that find articulation
// points using DFS traversal
// adj[] --> Adjacency List representation of the graph
// u --> The vertex to be visited next
// visited[] --> keeps track of visited vertices
// disc[] --> Stores discovery times of visited vertices
// low[] -- >> earliest visited vertex (the vertex with minimum
// discovery time) that can be reached from subtree
// rooted with current vertex
// parent --> Stores the parent vertex in DFS tree
// isArt_point[] --> Stores articulation points
void Art_pointUtil(vector<int> adj[], int u, bool visited[],
			int disc[], int low[], int& time, int parent,
			bool isArt_point[])
{
	// Count of children in DFS Tree
	int children = 0;

	// Mark the current node as visited
	visited[u] = true;

	// Initialize discovery time and low value
	disc[u] = low[u] = ++time;

	// Go through all vertices adjacent to this
	for (auto v : adj[u]) {
		// If v is not visited yet, then make it a child of u
		// in DFS tree and recur for it
		if (!visited[v]) {
			children++;
			Art_pointUtil(adj, v, visited, disc, low, time, u, isArt_point);

			// Check if the subtree rooted with v has
			// a connection to one of the ancestors of u
			low[u] = min(low[u], low[v]);

			// If u is not root and low value of one of
			// its child is more than discovery value of u.
			if (parent != -1 && low[v] >= disc[u])
				isArt_point[u] = true;
		}

		// Update low value of u for parent function calls.
		else if (v != parent)
			low[u] = min(low[u], disc[v]);
	}

	// If u is root of DFS tree and has two or more children.
	if (parent == -1 && children > 1)
		isArt_point[u] = true;
}

void Art_point(vector<int> adj[], int V)
{
	int disc[V] = { 0 };
	int low[V];
	bool visited[V] = { false };
	bool isArt_point[V] = { false };
	int time = 0, par = -1;

	// Adding this loop so that the
	// code works even if we are given
	// disconnected graph
	for (int u = 0; u < V; u++)
		if (!visited[u])
			Art_pointUtil(adj, u, visited, disc, low,
				time, par, isArt_point);

	// Printing the Art_points
	for (int u = 0; u < V; u++)
		if (isArt_point[u] == true)
			cout << u << " ";
}

// Function to add an edge
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main()
{
	// Create graphs given in above diagrams
	cout << "\n Articulation points in first graph \n";
	int V = 5;
	vector<int> adj1[V];
	addEdge(adj1, 1, 0);
	addEdge(adj1, 0, 2);
	addEdge(adj1, 2, 1);
	addEdge(adj1, 0, 3);
	addEdge(adj1, 3, 4);
	Art_point(adj1, V);
	cout << "\n";

	cout << "\nArticulation points in second graph \n";
	V = 4;
	vector<int> adj2[V];
	addEdge(adj2, 0, 1);
	addEdge(adj2, 1, 2);
	addEdge(adj2, 2, 3);
	Art_point(adj2, V);
	cout << "\n";

	cout << "\nArticulation points in third graph \n";
	V = 7;
	vector<int> adj3[V];
	addEdge(adj3, 0, 1);
	addEdge(adj3, 1, 2);
	addEdge(adj3, 2, 0);
	addEdge(adj3, 1, 3);
	addEdge(adj3, 1, 4);
	addEdge(adj3, 1, 6);
	addEdge(adj3, 3, 5);
	addEdge(adj3, 4, 5);
	Art_point(adj3, V);
	cout << "\n";

	return 0;
}
