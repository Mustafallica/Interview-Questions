
/*

Q) Construct a BST given the pre-order and in-order traversal Strings
 
 We can optimize the above solution using hashing (unordered_map in C++).
 We store indexes of inorder traversal in a hash table. So that search can be done O(1) time.
 
 
 */

#include <iostream>
#include <unordered_map>
using namespace std;



struct Node { /* A binary tree node has data, pointer to left child and a pointer to right child */
    char data;
    struct Node* left;
    struct Node* right;
};



struct Node* newNode(char data) {
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}



/* Recursive function to construct binary of size
 len from Inorder traversal in[] and Preorder traversal
 pre[]. Initial values of inStrt and inEnd should be
 0 and len -1. The function doesn't do any error
 checking for cases where inorder and preorder
 do not form a tree */
struct Node* buildTree(char in[], char pre[], int inStrt, int inEnd, unordered_map<char, int>& mp) {
    static int preIndex = 0;
    if (inStrt > inEnd) return NULL;
    
    int curr = pre[preIndex++]; /* Pick current node from Preorder traversal using preIndex and increment preIndex */
    struct Node* tNode = newNode(curr);
    
    if (inStrt == inEnd) return tNode; /* If this node has no children then return */
    
    int inIndex = mp[curr]; /* Else find the index of this node in Inorder traversal */
    
    /* Using index in Inorder traversal, construct left and right subtress */
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1, mp);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd, mp);
    
    return tNode;
}


struct Node* buldTreeWrap(char in[], char pre[], int len) { // This function mainly creates an unordered_map, then calls buildTree()
    
    // Store indexes of all items so that we we can quickly find later
    unordered_map<char, int> mp;
    for (int i = 0; i < len; i++)
        mp[in[i]] = i;
    
    return buildTree(in, pre, 0, len - 1, mp);
}



void printInorder(struct Node* node) { /* This funtcion is here just to test buildTree() */
    if (node == NULL) return;
    printInorder(node->left);
    printf("%c ", node->data);
    printInorder(node->right);
}





int main() {
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    int len = sizeof(in) / sizeof(in[0]);
    
    struct Node* root = buldTreeWrap(in, pre, len);
    
    /* Let us test the built tree by printing Insorder traversal */
    cout << "Inorder traversal of the constructed tree is: ";
    printInorder(root);
    cout << endl;
}
