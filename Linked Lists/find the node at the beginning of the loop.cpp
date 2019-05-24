// Given a circular linked list, find the node at the beginning of the loop.


#include<iostream>
#include<cstdlib>
using namespace std;

/* Link list node */
struct Node
{
    int data;
    Node* next;
};

/* Function to remove loop. Used by detectAndRemoveLoop() */
Node* getFirstNode( Node *, Node *);

/* This function detects and return start node of loop in */
Node* detectAndGetStartLoop( Node *list) {
    Node *slow_p = list, *fast_p = list;
    
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        
        /* If slow_p and fast_p meet at some point then there
         is a loop */
        if (slow_p == fast_p) { return getFirstNode(slow_p, list);}
    }
    return NULL; // no loop
}

/* Function to remove loop.
 loop_node --> Pointer to one of the loop nodes
 head --> Pointer to the start node of the linked list */
Node* getFirstNode( Node *loop_node, Node *head) {
    Node *ptr1;
    Node *ptr2;
    
    /* Set a pointer to the beging of the Linked List and
     move it one by one to find the first node which is
     part of the Linked List */
    ptr1 = head;
    while (true) {
        /* Now start a pointer from loop_node and check if it ever
         reaches ptr2 */
        ptr2 = loop_node;
        while (ptr2->next != loop_node && ptr2->next != ptr1)
            ptr2 = ptr2->next;
        
        /* If ptr2 reahced ptr1 then there is a loop. So break the
         loop */
        if (ptr2->next == ptr1)
            break;
        
        /* If ptr2 did't reach ptr1 then try the next node after ptr1 */
        ptr1 = ptr1->next;
    }
    
    /* After the end of loop ptr2 is the last node of the loop. So
     next of ptr2 is first ndoe of loop */
    return ptr2->next;
}

Node *newNode(int key) {
    Node *temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}


int main() {
    
    Node *head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
    
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
    
    Node *start = detectAndGetStartLoop(head);
    
    if(start == NULL) {
        cout << "No loop" << endl;
        
    } else {
        cout << start->data << " is starting of the loop" << endl;
    }
}

