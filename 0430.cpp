// First time
/*
    Treat it a binary tree, move right side behind left side
    child node -> left node
    next node -> right node
    But need to handle prev node
    T: O(n)/S: O(n)
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        Node *left=flatten(head->child);
        Node *right=flatten(head->next);
        Node *cur=head;
        // Move left side to right
        cur->next=left;
        if (left) left->prev=cur;
        cur->child=nullptr;
        // Connect original right side behind left side
        while (cur->next) cur=cur->next;
        cur->next=right;
        if (right) right->prev=cur;
        return head;
    }
};