// Write a function that sorts a stack (bonus: sort the stack in place without extra memory)

#include <iostream>
using namespace std;


class sortedStack{
private:
    int *_mainStack;     // main ordered stack
    int *_auxStack;              // auxulary stack for ordering
    int _size;                       // the max size of stack for overflow checking
    int _top;                        // index of the top element of main stack
    int _aux_top;            // index of the top element of aux stack
    
public:
    sortedStack(int n);      // constructor
    ~sortedStack();             // destructor
    bool isEmpty();           // is the stack empty?
    bool isFull();            // is the stack full?
    void push(int data);       // ordered push
    void pop();                       // normal pop operation
    int peek();                       // peek function
    void print();             // print the main stack
};


sortedStack::sortedStack(int n) {
    _size = n;
    _top = -1;
    _aux_top = -1;
    _mainStack = (int*) malloc(sizeof(int) * _size);
    _auxStack  = (int*) malloc(sizeof(int) * _size);
}


sortedStack::~sortedStack() {
    free(_mainStack);
    free(_auxStack);
}


bool sortedStack::isEmpty() {
    return (_top == -1);
}


bool sortedStack::isFull() {
    return (_top == _size-1);
}


void sortedStack::push(int data) {
    // is full, not possible to push a new element
    if (isFull()) {
        cout << " stack overflow!" << endl;
        return;
    }
    // if the stack is empty or the new element is smaller
    //  than the top value just do simple push
    int top_data = peek();
    if ((data >= top_data) | (isEmpty())) {
        _mainStack[++_top] = data;
        return;
    }
    
    // otherwise, use aux-stack to push the new element in the right place
    while(~isEmpty() & (top_data > data )) {
        _auxStack[++_aux_top] = top_data;
        pop();
        top_data = peek();}
    
    _mainStack[++_top] = data;
    // re-push the lements in aux-stack back to the main stack
    while(_aux_top >= 0) {
        _mainStack[++_top] = _auxStack[_aux_top--];
    }
    return;
}


void sortedStack::pop() {
    if (isEmpty()) {
        cout << " stack unerflow!" << endl;
        return;
    }
    _top--;
}



int sortedStack::peek() {
    if (isEmpty()) {
        cout << " stack is empty!" << endl;
        return INT_MAX;
    }
    return _mainStack[_top];
}



void sortedStack::print() {
    
    if (isEmpty()) {
        cout << " stack is empty!" << endl;
        return;
    }
    cout << " the elemets of stack " << endl;
    for (int i=0; i<=_top; i++)
        cout << _mainStack[i] << " " ;
    cout << endl;
}


int main() {
    
    sortedStack myStack(10);
    myStack.push(1);
    myStack.push(15);
    myStack.push(32);
    myStack.push(4);
    myStack.push(1);
    myStack.print();
    myStack.pop();
    myStack.pop();
    myStack.push(77);
    myStack.push(10);
    myStack.pop();
    myStack.push(-15);
    myStack.print();
}
