// First time
/*
    Use set to check duplicated node
    T: O(n)/S: O(n)
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        while(head) {
            if(s.count(head)) return head;
            s.insert(head);
            head=head->next;
        }
        return NULL;
    }
};

/*
    a: start to cycle begin
    b: cycle begin to where slow ptr meet fast ptr
    r: length of cycle
    slow = a+b
    fast = a+b+nr
    2(a+b)=a+b+nr
    a+b=nr -> a=nr-b
    so a=r-b

         a           b
    O -> O -> O -> O -> O -
              ^           |
              |-----------
                   r-b

    T: O(n)/S: O(1)
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow) {
                while(fast!=head) {
                    fast=fast->next;
                    head=head->next;
                }
                return head;
            };
        }
        return NULL;
    }
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow) break;
        }
        if(!fast || !fast->next) return NULL;
        slow=head;
        while(slow!=fast) {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        bool cycle=false;
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow) {
                cycle=true;
                break;
            }
        }
        slow=head;
        while(slow!=fast&&cycle) {
            slow=slow->next;
            fast=fast->next;
        }
        return cycle?slow:NULL;
    }
};