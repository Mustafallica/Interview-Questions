// Implement a linked list (with insert and delete functions)


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head;

void Print() {
    Node* temp = head;
    while (temp != NULL) {
        cout << " " << temp->data;
        temp = temp->next;}
}

void Delete(int n) {
    if ( n == 1 ) {
        Node* temp = head;
        head = temp -> next;
        delete temp;
        return;}
    
    Node* temp1 = head;
    
    for(int i = 0; i < n-2; i++) {
        temp1 = temp1 -> next;}
    
    Node* temp2 = temp1 -> next;
    temp1 -> next = temp2 -> next;
    delete temp2;
}


void Insert(int x, int n) {
    Node* temp = new Node();
    temp -> data = x;
    temp -> next = NULL;
    
    if ( n == 1 ) {
        temp -> next = head;
        head = temp;
        return;}
    
    Node* temp1 = head;
    
    for (int i = 0; i < n-2; i++) {
        temp1 = temp1 -> next;}

    temp -> next = temp1 -> next;
    temp1 -> next = temp;
}


int main() {
    
    head = NULL;
    
    Insert(2,1);
    Insert(3,1);
    Insert(99,3);
    Insert(4,2);
    Insert(5,3); // 3, 4, 5, 99, 2
    
    cout << "List is: ";
    Print(); // 1st call
    cout << endl;
    
    Delete(2);
    Delete(3); // 3,5,2
    
    cout << "List is: ";
    Print(); // 2nd call
    cout << endl;

}
