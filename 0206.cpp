// Second time
/*
    Recursion
    T: O(n)/S: O(n)
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *tmp=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return tmp;
    }
};

class Solution {
public:
    ListNode* reverseNode(ListNode *cur, ListNode *pre) {
        if (!cur) return pre;
        ListNode *tmp=cur->next;
        cur->next=pre;
        return reverseNode(tmp, cur);
    }
    ListNode* reverseList(ListNode* head) {
        return reverseNode(head, nullptr);
    }
};

/*
    Iteration
    T: O(n)/S: O(1)
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre=nullptr;
        while (head) {
            ListNode *tmp=head->next;
            head->next=pre;
            pre=head;
            head=tmp;
        }
        return pre;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre=new ListNode();
        pre->next=head;
        while (head && head->next) {
            ListNode *tmp=pre->next;
            pre->next=head->next;
            head->next=head->next->next;
            pre->next->next=tmp;
        }
        return pre->next;
    }
};


// First time
/*
    Iteration
    Need to save prev and cur pointer
    Try recursion?
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        struct ListNode* prev = NULL;
        struct ListNode* cur = head;
        struct ListNode* next;

        while (cur) {
	        next = cur->next;
	        cur->next = prev;
	        prev = cur;
	        cur = next;
        }
        return prev;
    }
};