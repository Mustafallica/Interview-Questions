
// program to find 2nd largest element in BST

#include<iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
};


// A utility function to create a new BST node
Node *newNode(int item) {
    Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}



void secondLargestUtil(Node *root, int &c) { // A function to find 2nd largest element in a given tree.
    
    // Base cases, the second condition is important to
    // avoid unnecessary recursive calls
    if (root == NULL || c >= 2) return;
    
    // Follow reverse inorder traversal so that the
    // largest element is visited first
    secondLargestUtil(root->right, c);
    
    // Increment count of visited nodes
    c++;
    
    // If c becomes k now, then this is the 2nd largest
    if (c == 2) {
        cout << "2nd largest element is: "
        << root->key << endl;
        return;}
    
    // Recur for left subtree
    secondLargestUtil(root->left, c);
}




void secondLargest(Node *root) { // Function to find 2nd largest element
    
    // Initialize count of nodes visited as 0
    int c = 0;
    
    // Note that c is passed by reference
    secondLargestUtil(root, c);
}


Node* insert(Node* node, int key) { /* A utility function to insert a new node with given key in BST */
    
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
    
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    
    /* return the (unchanged) node pointer */
    return node;
}



int main() {
    
    /* Let us create following BST
             50
        /         \
      30          70
     /  \        /  \
     20   40  60   80 */
    
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    secondLargest(root);
}
