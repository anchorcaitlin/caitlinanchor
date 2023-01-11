// IMPLEMENTATION OF A GRAPH USING AN ADJACENCY LIST 

/*
    Recall: An adjacency list represents a graph as an array of linked lists.
    Adjacency list - representation of a graph
    An array of lists are used. The size of the array is equal to the number of vertices.
    Adjacency list -> may save space 
    Time complexity for searching is O(n), may need to traverse through the entire linked list
*/

#include <iostream>
using namespace std;

// Store adjacency list nodes
struct adjNode {
  int value;
  adjNode* next;
};

// Structure to store edges
struct Edge {
  int start;
  int end;
};

struct Graph {
  // Allocating (adding) a new node for the adjacency list
  adjNode* AdjListNode(int end, adjNode* head) {
    adjNode* new_node = new adjNode;
    new_node->value = end;

    // Point new node to the current head
    new_node->next = head;

    return new_node;
  }

  int num_nodes;  // Number of nodes in the graph

  // An array of pointers to adjNode to represent the
  // adjacency list
  adjNode** head;

  Graph(Edge edges[], int n, int num_nodes) {
    // Allocate memory
    head = new adjNode*[num_nodes];
    this->num_nodes = num_nodes; // GET A SEGMENTATION FAULT WHEN ASSIGNING IT THE OTHER WAY

    // Initialize head pointer for all vertices (needs to be nullptr)
    for (int i = 0; i < num_nodes; i++) {
      head[i] = NULL;
    }

    // Add edges to the directed graph
    for (int i = 0; i < n; i++) {
      int start = edges[i].start;
      int end = edges[i].end;

      // Insert at the beginning. Call previous function
      adjNode* new_node = AdjListNode(end, head[start]); 

      // Point head pointer to the new node
      head[start] = new_node;
    }

  }
};

// Function to print all neighboring vertices of a given vertex
void printList(adjNode* ptr) {
  while (ptr != NULL) {
    cout << " —> " << ptr->value;
    ptr = ptr->next;
  }
  cout << endl; 
}

int main() {
  // Each set of coordinates represents an edge from two nodes
  Edge edges[] = {{0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}};

  // Number of nodes in the graph
  int num_nodes = 6;

  // Calculating the number of edges
  int num_edges = sizeof(edges) / sizeof(edges[0]);

  // Creating graph
  Graph graph(edges, num_edges, num_nodes);

  // Print adjacency list representation of a graph
  for (int i = 0; i < num_nodes; i++) {
    // Print index 
    cout << i;

    // Print all its vertices
    printList(graph.head[i]);
  }
}