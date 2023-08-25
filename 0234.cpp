// First time
/*
    Find the mid of list and reverse left part of list at the same time
    Then compare left part (head: pre) and right part (head: s)
    [1 -> 2 -> 0 -> 2 -> 1] -> [1 <- 2 <- 0 -> 2 -> 1]
                                    pre   s         f
    T: O(n)/S: O(1)
*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *pre=nullptr, *s=head, *f=head;
        while (f && f->next) {
            f=f->next->next;
            ListNode *tmp=s->next;
            s->next=pre;
            pre=s;
            s=tmp;
        }
        if (f) s=s->next;
        while (s && pre) {
            if (s->val!=pre->val) return false;
            s=s->next;
            pre=pre->next;
        }
        return true;
    }
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Find mid
        ListNode *s=head, *f=head;
        while (f && f->next) {
            f=f->next->next;
            s=s->next;
        }
        // Reverse left part
        ListNode *pre=nullptr, *cur=head;
        while (cur!=s) {
            ListNode *tmp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=tmp;
        }
        // If numbers of list is odd
        if (f) s=s->next;
        // pre: head of left part, s: head of right part
        while (s && pre) {
            if (s->val!=pre->val) return false;
            s=s->next;
            pre=pre->next;
        }
        return true;
    }
};

/*
    Create a whole reverse list then compare
*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *rev=nullptr, *cur=head;
        while (cur) {
            ListNode *tmp=new ListNode(cur->val);
            tmp->next=rev;
            rev=tmp;
            cur=cur->next;
        }
        while (head) {
            if (head->val!=rev->val) return false;
            head=head->next;
            rev=rev->next;
        }
        return true;
    }
};