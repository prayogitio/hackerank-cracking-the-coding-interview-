/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    Node* curr = head;
    int count = 0;
    while (head && count < 100) {
        head = head->next;
        count++;
    }
    if (count < 100) return false;
    else return true;
}