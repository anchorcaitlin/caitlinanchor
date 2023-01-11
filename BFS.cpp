// IMPLEMENTATION OF BREADTH FIRST SEARCH

/*
    Note: The worst case breath-first search has to consider all possible nodes.
    Each vertex is enqueued and dequeued at most once, which takes O(1) time for
   each, so the total time to queue operations is O(V)

   The algorithm scans the adjacency list of each vertex when the vertex is
   dequeued, so it scans the adjacency list at most once. The sum of the lengths
   of all adjacency lists is O(E)

   So, the worst case time complexity is O(V + E), V = number of nodes and E =
   number of edges
*/

#include <list>
#include <iostream>
using namespace std;

// Using struct instead of class to avoid private/public constructors and functions 
struct graph {
  int num_vertices;
  list<int> *adjList;  // Pointer to adjacency list

  graph(int v);
  void addEdge(int start, int end);

  // BFS given an initial source
  void BFS(int source);
};

// Implementation of the functions
graph::graph(int v) {
  // Set the number of vertices
  v = this->num_vertices;
  adjList = new list<int>[v]; // Initialising adjacency list based on the number of vertices
}

// Add edges - push_back adding a new element at the end of the vector
void graph::addEdge(int start, int end) { adjList[start].push_back(end); }

// BFS process
void graph::BFS(int source) {
  // Assign all vertices to be not visited
  bool *visited = new bool[num_vertices];

  for (int i = 0; i < num_vertices; i++) {
    visited[i] = false;
  }

  list<int> queue;  // Create a queue for BFS 

  // Mark start vertex as visited and add to queue
  visited[source] = true;
  queue.push_back(source);  // Add start vertex to the queue

  list<int>::iterator i; 

  cout << "BFS traversal: ";

  // Continue adding vertices to the queue - loop while queue is not empty
  while (!queue.empty()) {
    // Get front of queue
    source = queue.front();
    cout << source << " ";
    queue.pop_front(); // Dequeue from queue 

    for (i = adjList[source].begin(); i != adjList[source].end(); i++) {
      if (!visited[*i]) {
        // Mark as visited
        visited[*i] = true;  // *i are the pointers to the other nodes, mark that vertex as visited 
        queue.push_back(*i);
      }
    }
  }
}

int main() {
  graph g(4);  // Input represents the number of vertices
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);

  g.BFS(2);

  return 0;
}