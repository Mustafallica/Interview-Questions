/* Program to implement a queue using two stacks */

#include<iostream>
using namespace std;


struct sNode { /* structure of a stack node */
    int data;
    struct sNode *next;
};



void push(struct sNode** top_ref, int new_data); /* Function to push an item to stack */
int pop(struct sNode** top_ref); /* Function to pop an item from stack*/

struct queue { /* structure of queue having two stacks */
    struct sNode *stack1;
    struct sNode *stack2;
};



void enQueue(struct queue *q, int x) { /* Function to enqueue an item to queue */
    push(&q->stack1, x);
}



int deQueue(struct queue *q) { /* Function to dequeue an item from queue */
    
    int x;
    if (q->stack1 == NULL && q->stack2 == NULL) {     /* If both stacks are empty then error */
        cout << "Queue is empty";}
    
    if (q->stack2 == NULL) { /* Move elements from satck1 to stack 2 only if stack2 is empty */
        
        while (q->stack1 != NULL) {
            x = pop(&q->stack1);
            push(&q->stack2, x);}}

    x = pop(&q->stack2);
    return x;
}



void push(struct sNode** top_ref, int new_data) { /* Function to push an item to stack*/
    struct sNode* new_node = (struct sNode*) malloc(sizeof(struct sNode));     /* allocate node */
    
    if (new_node == NULL) {
        cout << "Stack overflow " << endl;}
    new_node->data = new_data;     /* put in the data  */
    new_node->next = (*top_ref);     /* link the old list off the new node */
    (*top_ref) = new_node;  /* move the head to point to the new node */
}



int pop(struct sNode** top_ref) { /* Function to pop an item from stack*/
    int res;
    struct sNode *top;
    
    if (*top_ref == NULL) { /*If stack is empty then error */
        cout << "Stack overflow " << endl;
        
    } else {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;}
    
    return 0;
}



int main() {
    
    /* Create a queue with items 1 2 3*/
    struct queue *q = (struct queue*) malloc(sizeof(struct queue));
    q->stack1 = NULL;
    q->stack2 = NULL;
    cout << "Enqueuing...";
    cout << endl;
    enQueue(q, 1);
    cout << "Enqueuing...";
    cout << endl;
    enQueue(q, 2);
    cout << "Enqueuing...";
    cout << endl;
    enQueue(q, 3);
    
    /* Dequeue items */
    cout << "Dequeuing...";
    cout << deQueue(q) << " ";
    cout << endl;
    cout << "Dequeuing...";
    cout << deQueue(q) << " ";
    cout << endl;
    cout << "Dequeuing...";
    cout << deQueue(q) << " ";
    cout << endl;
}
