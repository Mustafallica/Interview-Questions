/* Program to check if a linked list is palindrome */
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

void reverseList(ListNode **head) {
    ListNode *prev = NULL, *ptr = *head, *temp;
    while (ptr) {
        temp = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = temp;
    }
    *head = prev;
}

void printList(ListNode *ptr) {
    while(ptr) {
        cout << ptr->val << ", ";
        ptr = ptr->next;
    }
    cout << endl;
}

int isPalindromicLinkedList(ListNode* head) {
    if (head == NULL) {
        return 1;
    }
    ListNode *p1, *p2; // two pointer to struct List Node
    
    // find mid
    ListNode *mid = NULL;
    p1 = p2 = head;
    while (p2) {
        p2 = p2->next;
        if (p2) p2 = p2->next;
        if (p2) p1 = p1->next;
    }
    mid = p1;
    
    reverseList(&(mid->next)); // reverse list ahead of MID
    
    int ans = 1;
    p1 = head;
    p2 = mid->next;
    while (ans == 1 && p2) {
        if (p1->val != p2->val) ans = 0;
        p1 = p1->next;
        p2 = p2->next;
    }
    
    reverseList(&(mid->next)); // reset second half of list to original state.
    
    return ans;
}

ListNode *createListFromArray(int arr[], int n) {
    ListNode *head = new ListNode;
    ListNode *ptr = head;
    for (int i = 0; i < n; i++) {
        ptr->val = arr[i];
        ptr->next = (i == n-1 ? NULL : new ListNode);
        ptr = ptr->next;
    }
    return head;
}


int main() {
    
    cout << "'1' = Palindrome // '0' = Not Palindrome." << endl;
    cout << "=========================================" << endl;
    cout << endl;
    
    int arr[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    cout << "First Array: ";
    for (int i = 0; i < 9; i++) {
        cout << arr[i] << " ";}
    cout << endl;
    cout << "First array is: " << isPalindromicLinkedList(createListFromArray(arr, 9)) << endl;
    
    cout << endl;
    
    int arr2[] =  {1, 2, 2, 1};
    cout << "Seconnd Array: ";
    for (int i = 0; i < 9; i++) {
        cout << arr[i] << " ";}
    cout << endl;
    cout << "Second array is: " << isPalindromicLinkedList(createListFromArray(arr2, 4)) << endl;
    
    
    cout << endl;
    
    int arr3[] = {1, 2, 3, 4, 5};
    cout << "Third Array: ";
    for (int i = 0; i < 9; i++) {
        cout << arr[i] << " ";}
    cout << endl;
    cout << "Third array is: " << isPalindromicLinkedList(createListFromArray(arr3, 5)) << endl;
    
    cout << endl;
    cout << "=========================================" << endl;
    cout << endl;
}
