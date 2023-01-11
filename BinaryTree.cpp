// IMPLEMENTATION OF A BINARY TREE

/*
  Traversing through the nodes requires O(n) time complexity, need to traverse
  through ALL nodes. Allocating the node and linking it into the tree has O(1)
  time complexity. Search is performed in O(n) time, where n = the height of
  the tree.
*/

#include <iostream>
using namespace std;

class BST {
 private:
  struct node {
    int value;
    node *left;
    node *right;
  };

  node *root;  // pointer to the root of a node

  void add_leaf_private(int value, node *ptr);  // function to insert nodes
  void inorder_print(node *ptr);

 public:
  BST();                     // default constructor
  void add_leaf(int value);  // function is called from the main

  node *create_leaf(int value); 
  void inorder_print();
};

// IMPLEMENTATION OF FUNCTIONS FROM CLASS
// Create a NULL pointer as the root of the tree for the default
// constructor
BST::BST() { root = NULL; }

// Function to create a leaf
BST::node *BST::create_leaf(int value) {
  node *n = new node;
  n->value = value;
  n->left = NULL;
  n->right = NULL;

  return n;
}

void BST::add_leaf(int value) {
  // Want to call the add leaf private function. When in main function you only
  // want to worry about the value, not the location.
  add_leaf_private(value, root);  // this function searches for the right location
}

void BST::add_leaf_private(int value, node *ptr) {
  if (root == NULL) {
    root = create_leaf(value);
    /* For left side */
  } else if (value < ptr->value) {

    // Want to go to left. Is there a node connected to this node's pointer?
    if (ptr->left != NULL) {
      // Want to traverse down the left pointer. Recursively move down the left
      // pointer.
      add_leaf_private(value, ptr->left);
    } else {
      ptr->left = create_leaf(value);
    }
  }

  /* For right side */
  else if (value > ptr->value) {
    // want to go to right. Is there a node connected to this node's pointer?
    if (ptr->right != NULL) {
      // Want to traverse down the right pointer. Recursively move down the
      // right pointer
      add_leaf_private(value, ptr->right);
    } else {
      ptr->right = create_leaf(value);
    }
  }
}

void BST::inorder_print() {
  inorder_print(root);
  cout << endl;
}

void BST::inorder_print(node *ptr) {
  if (ptr != NULL) {
    inorder_print(ptr->left);
    cout << ptr->value << " ";
    inorder_print(ptr->right);
  }
}

int main(){
  
  BST *tree = new BST();

  tree->add_leaf(11);
  tree->add_leaf(5);
  tree->add_leaf(12);

  cout << "In-order traversal of the binary search tree is: ";
  tree->inorder_print();
  cout << endl;
}