// First time
/*
    without hash map (3 pass):
    1. Let copied nodes link behind original nodes
        1 -> 2 -> 3
    =>  1 -> 1' -> 2 -> 2' -> 3 -> 3'
    2. Connect copied nodes' random node
        ____________
        |          |
        1 -> 1' -> 2 -> 2' -> 3 -> 3'
             |__________|
    3. Separate the copied nodes and the original nodes, then recover the next node
        ______          _______
        |    |          |     |
        1 -> 2 -> 3     1' -> 2' -> 3'
    T: O(n)/S: O(1)
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *cur = head, *tmp = nullptr;
        while (cur) {
            tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = cur->next->next;
        }
        cur = head;
        while (cur) {
            if (cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        Node *header = new Node(NULL);
        cur = header;
        while (head) {
            cur->next = head->next;
            head->next = head->next->next;
            head = head->next;
            cur = cur->next;
        }
        /*
        while (head) {
            cur->next = head->next;
            head->next = head->next->next;
            if(head->next) cur->next->next = head->next->next;
            head = head->next;
            cur = cur->next;
        }
        */
        return header->next;
    }
};

/*
    Use hash map to creat new node the link them
    T: (n)/S: O(n)
*/
// Recursion (1 pass)
class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        if (!mp.count(head)) {
            mp[head] = new Node(head->val);
            mp[head]->next = copyRandomList(head->next);
            mp[head]->random = copyRandomList(head->random);
        }
        return mp[head];
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *> mp;
        Node* cur = head;
        while (cur) {
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            mp[cur]->next = mp[cur->next];
            mp[cur]->random = mp[cur->random];
            cur = cur->next;
        }
        return mp[head];
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *> mp;
        Node *cur = head;
        // Make every nodes
        while (cur) {
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }
        Node *dummy = new Node(0);
        cur = dummy;
        // Link nodes
        while (head) {
            cur->next = mp[head];
            cur->next->next = mp[head->next];
            cur->next->random = mp[head->random];
            cur = cur->next;
            head = head->next;
        }
        cur = dummy->next;
        Node *tmp = dummy;
        delete tmp;
        return cur;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/