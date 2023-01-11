// IMPLEMENTATION OF A SINGLY LINKED LIST

/*
    A linked node is a collection of multiple nodes where each node stores a
    reference to a data, as well as a reference to the next node of the node

    Non-contiguous data structure
*/

#include <iostream>
using namespace std;

// Create the structure of the node - each node contains an item (data value)
// and a pointer to the next
struct node {
  int item;
  node *next;
};

// Create a class 'linkedList' containing all the functions and data members
// required for the linked node
struct linkedList {
  node *head;
  node *tail; // head and tail nodes of linked list 

  // Default constructor where there are no elements in the linked list
  linkedList() {
    head = NULL;
    tail = NULL;
  }

  // Constructor where you can add a node to the linked list
  void addNode(int n) {
    node *temp = new node;  // Allocating space for a new node. Temp points to a
                            // new node in the linked list.
    temp->item = n;         // Retrieving the value of the node.
    temp->next = NULL;

    /* Join the nodes and create the linked node */

    // If the head is NULL, there is no linked node yet so the current node must
    // now be the head and tail
    if (head == NULL) {
      head = temp;
      tail = temp;
    } else {
      // Have to add the node to the end of the linked node. New node is now the
      // tail.
      tail->next = temp;
      tail = tail->next;
    }
  }

  // Constructor to print the elements of the linked node.
  void printList() {
    node *temp = head;
    // Check for empty node.
    if (head == NULL) {
      cout << "Empty linked list" << endl;
    }

    // Traverse the node.
    while (temp != NULL) {
      cout << temp->item << " ";
      temp = temp->next;
    }
  }
};

// Implementing a linked list
int main() {
  linkedList structure;
  structure.addNode(2);
  structure.addNode(3);
  structure.addNode(4);

  cout << "The elements of the linked node are: ";
  structure.printList();
  cout << endl;

  return 0;
}

// BIG-O COMPLEXITY TIMES FOR A LINKED LIST
/*
SINGLY LINKED LIST -> only has a pointer to the next node

Sorted linked list:
Search, insert, delete, and predecessor: O(n)
Successor, minimum and maximum: O(1) - min, max will be at start/end of linked
list and successor can be found by using the pointer of node

Unsorted linked list:
Search, delete, successor, predecessor: O(n)
Insert, minimum, maximum: O(1) 
*/