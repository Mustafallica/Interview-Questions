// Find the smallest element in a BST

#include <iostream>
using namespace std;


struct node { /* A binary tree node has data, pointer to left child and a pointer to right child */
    int data;
    struct node* left;
    struct node* right;
};



/* Helper function that allocates a new node with the given data and NULL left and right pointers. */
struct node* newNode(int data) {
    struct node* node = (struct node*)
    malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}



/* Given a non-empty binary search tree, return the minimum data value found in that tree. Note that the entire tree does not need to be searched. */
int minValue(struct node* node) {
    struct node* current = node;
    
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) {
        current = current->left;}
    return(current->data);
}



int main() {
    struct node *root = newNode(4);
    root->left        = newNode(2);
    root->right       = newNode(5);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);
    
    cout << "Minimum value in BST is: " <<  minValue(root) << endl;
}
