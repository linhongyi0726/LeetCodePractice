// Second time
/*
    Use original linked list
    T: O(n)/S: O(1)
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum = 0;
        ListNode *cur = new ListNode();
        cur->next = l1;
        while (cur->next || l2) {
            if (!cur->next) {
                sum = l2->val + carry;
            } else if (!l2) {
                sum = cur->next->val + carry;
            } else {
                sum = cur->next->val + l2->val + carry;
            }
            carry = sum / 10;
            if (cur->next)
                cur->next->val = sum % 10;
            else
                cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (l2)
                l2 = l2->next;
        }
        if (carry) {
            cur->next = new ListNode(1);
            cur = cur->next;
        }
        cur = nullptr;
        return l1;
    }
};


// First time
/*
    If we modify one of list and return, the SC can be reduced to O(1)
    T: O(n)/S: O(n)
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans=new ListNode();
        ListNode *cur=ans;
        int sum=0, carry=0;
        while (l1 || l2) {
            if (!l1) l1=new ListNode(0);
            else if (!l2) l2=new ListNode(0);
            sum=l1->val+l2->val+carry;
            carry=sum/10;
            cur->next=new ListNode(sum%10);
            cur=cur->next;
            l1=l1->next;
            l2=l2->next;
        }
        if (carry) cur->next=new ListNode(1);
        else cur->next=nullptr;
        // To avoid memory leak
        ListNode *tmp=ans;
        ans=ans->next;
        delete tmp;
        return ans;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans=new ListNode();
        ListNode *cur=ans;
        int sum=0, carry=0;
        while (l1 || l2) {
            if (l1 && l2) {
                sum=l1->val+l2->val+carry;
                cur->next=new ListNode(sum%10);
                l1=l1->next;
                l2=l2->next;
            } else if (l1) {
                sum=l1->val+carry;
                cur->next=new ListNode(sum%10);
                l1=l1->next;
            } else {
                sum=l2->val+carry;
                cur->next=new ListNode(sum%10);
                l2=l2->next;
            }
            carry=sum/10;
            cur=cur->next;
        }
        if (carry) cur->next=new ListNode(1);
        else cur->next=nullptr;
        return ans->next;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans=new ListNode();
        ListNode *cur=ans;
        int sum=0, carry=0;
        while (l1 && l2) {
            sum=l1->val+l2->val+carry;
            carry=sum/10;
            cur->next=new ListNode(sum%10);
            cur=cur->next;
            l1=l1->next;
            l2=l2->next;
        }
        if (l1) cur->next=l1;
        else cur->next=l2;
        while (cur->next && carry) {
            cur=cur->next;
            sum=cur->val+carry;
            carry=sum/10;
            cur->val=sum%10;
        }
        if (carry) cur->next=new ListNode(carry);
        return ans->next;
    }
};