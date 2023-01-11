// IMPLEMENTATION OF DEPTH FIRST SEARCH

/*
    Start at the root node and transverses as far as possible along each branch
   before backtracking

    Mark each vertex as visited while avoiding cycles

    Start by putting any one of the graph's vertices on top of a stack.
    Take the top item of the stack and add it to the visited list.
    Create a list of that vertex's adjacent nodes. Add the ones which aren't in
   the visited list to the top of the stack.

    Time complexity: O(V+E), where V is the number of vertices and E is the
   number of edges
*/

#include <iostream>
#include <list>

using namespace std;

// Using struct instead of class to avoid private/public constructors and functions 
struct graph {
  int num_vertices;
  list<int>* adjLists;  // Pointer to adjacency list
  bool* visited;

  graph(int v);
  void addEdge(int start, int end);

  // DFS given an initial source
  void DFS(int vertex);
};

// Initialise graph
graph::graph(int v) {
  num_vertices = v;
  adjLists = new list<int>[v];  // Initialising adjacency list based on the
                                // number of vertices
  visited = new bool[v];
}

// Add edges to graph
void graph::addEdge(int start, int end) { adjLists[start].push_front(end); }

// DFS algorithm
void graph::DFS(int vertex) {
  // Mark current vertex as visited
  visited[vertex] = true;
  list<int> adjList = adjLists[vertex];
  // Print the vertex
  cout << vertex << " ";

  // Traverse the adjacent and unmarked vertices and call the recursive function
  // with the index of the adjacent vertex.
  list<int>::iterator i;
  for (i = adjList.begin(); i != adjList.end(); i++) {
    // Recursive algorithm (if node not visited, go back and set visited to
    // true)
    if (!visited[*i]) {  // *i are the pointers to the other nodes
      DFS(*i);
    }
  }
}

int main() {
  graph binary_tree(4);
  binary_tree.addEdge(0, 1);
  binary_tree.addEdge(0, 2);
  binary_tree.addEdge(1, 2);
  binary_tree.addEdge(2, 3);

  cout << "DFS: ";
  binary_tree.DFS(2);
}