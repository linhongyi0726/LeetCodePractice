// First time
/*
    Only need to have a carry when value >=5
    Just check the next node value to judge needing a carry or not
*/
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if (head->val>=5) head=new ListNode(0, head);
        ListNode *cur=head;
        while (cur) {
            cur->val=(cur->val*2)%10;
            if (cur->next && cur->next->val>=5) cur->val++;
            cur=cur->next;
        }
        return head;
    }
};

/*
    Recursion
*/
class Solution {
public:
    int multiply(ListNode *head) {
        if (!head) return 0;
        int tmp=head->val*2 + multiply(head->next);
        head->val=tmp%10;
        return tmp/10;
    }
    ListNode* doubleIt(ListNode* head) {
        int carry=multiply(head);
        if (carry) return new ListNode(carry, head);
        return head;
    }
};

/*
    Iteration
    Because of here we only need to multiply by two, carry will only be 1 at most
    Reverse list and double each node, then reverse it back
*/
class Solution {
public:
    ListNode *reverseList(ListNode* head) {
        ListNode *pre=nullptr, *cur=head;
        while (cur) {
            ListNode *tmp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=tmp;
        }
        return pre;
    }
    ListNode* doubleIt(ListNode* head) {
        head=reverseList(head);
        bool carry=false;
        ListNode *cur=head;
        while (cur) {
            int tmp=cur->val*2 + carry;
            cur->val=tmp%10;

            // carry=tmp/10;
            if (tmp >= 10) carry|=1;
            else carry&=~1;

            if (cur->next) cur=cur->next;
            else break;
        }
        // if (carry) cur->next=new ListNode(carry);
        if (carry) cur->next=new ListNode(1);
        head=reverseList(head);
        return head;
    }
};