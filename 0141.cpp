// Third time
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *l=head, *r=head;
        while (r && r->next) {
            l=l->next;
            r=r->next->next;
            if (l==r) return true;
        }
        return false;
    }
};

// Brute-force
class Solution {
public:
    bool hasCycle(ListNode *head) {
        for (int i = 0; i < 20000; ++i) {
            if (!head) return false;
            head = head->next;
        }
        return true;
    }
};

// Second time
/*
    Similar and advanced problem: 142
    T: O(n)/S: O(1)
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *s=head, *f=head;
        while(f&&f->next) {
            s=s->next;
            f=f->next->next;
            if(s==f) return true;
        }
        return false;
    }
};

/*
    Also can use set to store the node visited then check it
    T: O(n)/S: (n)
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        while(head) {
            if(s.count(head)) return true;
            s.insert(head);
            head=head->next;
        }
        return false;
    }
};

// First time
/*
    Use Floyd Cycle Detection Algorithm (Tortoise and Hare Algorithm)
    If there is a cycle, two pointer will be together
    T: O(n)/S: O(1)
    * Notice the while condition to avoid null pointer
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};