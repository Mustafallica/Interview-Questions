// Find the minimum element in a stack in O(1) time

#include<iostream>
#include<string>
using namespace std;
#define STACK_SIZE 10000

class stac {
public:
    stac() : top(-1) {}
    
    void push(int item) {
        if(top>=STACK_SIZE-1) {
            cout<<"Full"<<endl;
            return;
        } else {
            cout << "Top is: " << top << endl;
            int currentmin = min[top];
            top ++;
            
            if(top == 0 || item < currentmin ) {
                min[top] = item; // New minimum
            } else {
                min[top] = currentmin; //keep current minimum
            }
            
            s[top]=item;
            return;}
    }
    
    void pop() {
        if(top==-1) {
            cout<<"Empty "<<endl;
            return;
            
        } else {
            top--;
            return;}
    }
    
    void mini() {
        if(top==-1) {
            cout<<"No minimum "<<endl;
            return;
            
        } else {
            cout << min[top] << endl;}
    }
    
    void display() {
        int i = top;
        cout << "elememt stack: ";
        
        while(i) {
            cout << s[i--] << " " ;}
        
        i = top;
        cout << endl << "Min stack: ";
        
        while(i) {
            cout << min[i--] << " " ;}
        cout << endl;
    }
    
private:
    int s[STACK_SIZE];
    int min[STACK_SIZE];
    int top = -1;
};


int main(){
    
    stac s1;
    
    s1.push(5);
    s1.push(2);
    s1.push(9);
    s1.push(1);
    s1.push(24);
    s1.push(-1);
    s1.push(-87);
    s1.push(23);
    s1.mini();
    s1.display();

}
