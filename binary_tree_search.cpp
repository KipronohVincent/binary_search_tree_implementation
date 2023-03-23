#include <iostream>
#include <cstdlib>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);

        if (root == nullptr) {
            root = newNode;
        } else {
            Node* temp = root;
            while (temp != nullptr) {
                if (value <= temp->data) {
                    if (temp->left == nullptr) {
                        temp->left = newNode;
                        newNode->parent = temp;
                        break;
                    } else {
                        temp = temp->left;
                    }
                } else {
                    if (temp->right == nullptr) {
                        temp->right = newNode;
                        newNode->parent = temp;
                        break;
                    } else {
                        temp = temp->right;
                    }
                }
            }
        }
    }

    Node* search(int value) {
        Node* temp = root;

        while (temp != nullptr) {
            if (value == temp->data) {
                return temp;
            } else if (value < temp->data) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }

        return nullptr;
    }

    void remove(int value) {
        Node* nodeToRemove = search(value);

        if (nodeToRemove == nullptr) {
            cout << "Node not found" << endl;
            return;
        }

        if (nodeToRemove->left == nullptr && nodeToRemove->right == nullptr) {
            if (nodeToRemove == root) {
                root = nullptr;
            } else {
                if (nodeToRemove->parent->left == nodeToRemove) {
                    nodeToRemove->parent->left = nullptr;
                } else {
                    nodeToRemove->parent->right = nullptr;
                }
            }
            delete nodeToRemove;
        } else if (nodeToRemove->left == nullptr) {
            if (nodeToRemove == root) {
                root = nodeToRemove->right;
            } else {
                if (nodeToRemove->parent->left == nodeToRemove) {
                    nodeToRemove->parent->left = nodeToRemove->right;
                } else {
                    nodeToRemove->parent->right = nodeToRemove->right;
                }
                nodeToRemove->right->parent = nodeToRemove->parent;
            }
            delete nodeToRemove;
        } else if (nodeToRemove->right == nullptr) {
            if (nodeToRemove == root) {
                root = nodeToRemove->left;
            } else {
                if (nodeToRemove->parent->left == nodeToRemove) {
                    nodeToRemove->parent->left = nodeToRemove->left;
                } else {
                    nodeToRemove->parent->right = nodeToRemove->left;
                }
                nodeToRemove->left->parent = nodeToRemove->parent;
            }
            delete nodeToRemove;
        } else {
            Node* temp = nodeToRemove->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }

            nodeToRemove->data = temp->data;
            if (temp->parent->left == temp) {
                temp->parent->left = temp->right;
                if (temp->right != nullptr) {
                    temp->right->parent = temp->parent;
                }
            } else {
                temp->parent->right = temp->right;
                if (temp->right != nullptr) {
                 temp->right->parent = temp->parent;
            }
        }
        delete temp;
    }
}

void inorderTraversal(Node* node) {
    if (node != nullptr) {
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }
}

void postorderTraversal(Node* node) {
    if (node != nullptr) {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }
}

void preorderTraversal(Node* node) {
    if (node != nullptr) {
        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

void print() {
    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorderTraversal(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preorderTraversal(root);
    cout << endl;
}
};

int main() {
BST tree;
// Insert random numbers
srand(time(NULL));
for (int i = 0; i < 10; i++) {
    int value = rand() % 100;
    tree.insert(value);
}

// Test insert, search, and remove
tree.insert(50);
tree.insert(25);
tree.insert(75);
tree.insert(10);
tree.insert(30);
tree.insert(60);
tree.insert(80);
tree.print();

tree.remove(50);
tree.remove(75);
tree.remove(10);
tree.print();
// Node not found
tree.remove(100); 

return 0;
}