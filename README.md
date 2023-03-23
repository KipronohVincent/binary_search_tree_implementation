## Binary Search Tree Implementation

- This is an implementation of a binary search tree in C++. The program includes a Node class to represent nodes in the tree, and a BST class to represent the tree itself. The BST class has functions to `insert`, `remove`, and `search nodes` in the tree, as well as traverse the tree in `inorder`, `postorder`, and `preorder`.

#### Node Class
- The `Node class` has the following members:

    - `int data`: The data stored in the node.
    - `Node* parent`: A pointer to the parent node.
    - `Node* left`: A pointer to the left child node.
    - `Node* right`: A pointer to the right child node.
#### BST Class
- The BST class has the following members:

    - `Node* root`: A pointer to the root node of the tree.
- And the following public member functions:

### void insert(int value)
- Inserts a node with the given value into the tree.

### bool search(int value)
- Searches the tree for a node with the given value. Returns true if the node is found, false otherwise.

### void remove(int value)
- Removes the node with the given value from the tree.

### void inorderTraversal(Node* node)
- Prints the nodes in the tree in `inorder traversal`.

### void postorderTraversal(Node* node)
- Prints the nodes in the tree in `postorder traversal`.

### void preorderTraversal(Node* node)
- Prints the nodes in the tree in `preorder traversal`.

### void print()
- Prints the nodes in the tree in `inorder`, `postorder`, and `preorder traversal`.

## Main Function
- The `main()` function generates a sequence of random numbers and inserts them into the binary search tree using the `insert()` function. It then tests the `insert()`, `search()`, and `remove()` functions with a set of predetermined values. Finally, it calls the `print()` function to print the contents of the tree in `inorder`, `postorder`, and `preorder traversal`.

### Potential Issues
- This implementation of the `BST` does not handle duplicate values. If a value that already exists in the `BST` is inserted again, the behavior is `undefined`. This can be easily remedied by modifying the `insert()` method to handle duplicates appropriately.

### Conclusion
This implementation of a `BST` provides a simple and efficient data structure for `storing` and `retrieving` data in a `sorted order`. The BST is a versatile data structure that can be used for a wide range of applications, including `searching`, sorting, and `indexing data`.

### Compilation
`g++ binary_tree_search.cpp -o binary_tree_search`
### Executing
`./binary_tree_search`
