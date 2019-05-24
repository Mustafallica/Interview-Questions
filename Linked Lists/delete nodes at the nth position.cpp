/*
 program to add and delete nodes at the nth position
 */


#include <iostream>
using namespace std;

struct node { // node structure to add nodes
    int data; // she might ask for char or double not just int.
    node *next;}; // pointer link of type node to link the nodes.


node* head = nullptr; // global var. of the head so all the func. can access it.


void insert(int data, int n){ // a func. that takes 2 parameters, data and the nth position of the node.
    node *temp = new node; // creating new node.
    temp->data = data; // assigning where to store the input data.
    temp->next = nullptr;
    
    if (n==1) { // if we want to insert in the head, or at the beginning
        temp->next = head; // assigning the new created node to point at the head.
        head = temp; // storing the value of head in temp var.
        return;} // stop at here if n == 1 and we dont excute the for loop
    
    node *temp1 = head; // storing the value of head at temp1 var. so we dont change the value of the actual head and we start from head.
    for (int i = 0; i < n-2; i++) { // for loop to go and points to the (n-1)th node. (n-1) points to the head node. (n-2)th points to the node after.
        temp1 = temp1->next;} // pointing head to the (n-1)th node.
    
    temp->next = temp1->next; // old node link to new created node
    temp1->next = temp;} // pointing to the new node.



void deleteNode(int n){ // Delete func to delete at any nth position
    node *temp = head; // saving the head in a temp. var so we dont change the actual head.
    if (n == 1) { // if statment if we want to delete the first node or the head node.
        head = temp->next; // head pointing to the second node after we remove the first node.
        free(temp); // freeing the memory of the deleted first node.
        return;} // return; so we dont excute the for loop.
    
    for (int i = 0; i < n-2; i++) { // for loop to go and points to the (n-1)th node
        temp = temp->next;}
    node *temp1 = temp->next; // var to point to the nth node.
    temp->next = temp1->next; // adjust the link from  (n-1)th node (deleted one) to point to the new node (n+1)th node after the removed one.
    free(temp1);} // free memory of the deleted node.



void print(){ // Print func. to print the linked list
    node *current = head; // saving the head in a temp. var so we dont change the actual head.
    while (current!=nullptr) { // print all the nodes Data that untill it reaches the last node which has the nullptr link.
        cout << current->data << " "; // printing the linked list DATA.
        current = current->next;}} // incrementing the head until it reaches the nullptr, so we stop.



int main(int argc, const char * argv[]) {
    
    insert(5, 1); // adding first node at the head or 1st nth position
    insert(7, 2); // adding second node at the 2nth position
    insert(6, 3); // adding third node at the 3nth position
    print(); // printing the nodes.
    cout << endl; // new line lol :P
    
    deleteNode(2); // calling the delete function to remove the 2nth position node which is insert(7,2)
    print(); // printing the nodes after removing the node at the 2nth position
    cout << endl; // new line :P
    
    
    
    /*
     - You can just insert nodes and remove nodes as much as you want.
     - You cant skip nth posiotion.
     * You CANNOT write insert(5,1) then jump to insert(6,3).. you should have insert(WriteAnyNumber,2)
     - the deleteNode() will make you delete any node at any nth position you want.
     */
    
}
