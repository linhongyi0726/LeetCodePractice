// Third time
/*
    T: O(n)/S: O(1)
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *s = head, *f = head;
        while (f && f->next) {
            s = s->next;
            f = f->next->next;
            if (s == f) {
                s = head;
                while (s != f) {
                    s = s->next;
                    f = f->next;
                }
                return s;
            }
        }
        return nullptr;
    }
};


// Second time
/*
                     where l==r
         a         b    v
    O -> O -> O -> O -> O -
              ^           |
              |-----------|
                    c
    l (slow): a+b
    r (fast): a+b+c+b = a+2b+c
    2(a+b) = a+2b+c -> a=c

    T: O(n)/S: O(1)
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *l=head, *r=head;
        ListNode *ans=new ListNode();
        while (r && r->next) {
            l=l->next;
            r=r->next->next;
            if (l==r) {
                ans=head;
                while (ans!=r) {
                    ans=ans->next;
                    r=r->next;
                }
                return ans;
            }
        }
        return NULL;
    }
};


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