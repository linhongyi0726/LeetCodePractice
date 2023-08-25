// Second time
/*
    2 ptr
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy=new ListNode();
        dummy->next=head;
        ListNode *l=dummy, *r=dummy;
        for (int i=0; i<n; ++i) r=r->next;
        // Because of dummy head, r will not be nullptr,
        // here only need to check r->next
        while (r->next) {
            l=l->next;
            r=r->next;
        }
        ListNode *tmp=l->next;
        l->next=l->next->next;
        delete tmp;
        head=dummy->next;
        delete dummy;
        return head;
    }
};


// First time
/*
    two pointer
    let the interval between slow and fast ptr be n
    -> move slow and fast ptr together until the end of list,
    so slow->next postion is the Nth node from end

    *Notice the edge case (e.g. remove head)
    -> use r==null to judge or use another node "header" in front of head

    T: O(n)/S: O(1)
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* l=head;
        ListNode* r=head;
        for (int i=0; i<n; ++i) r=r->next;
        while (r && r->next) {
            l=l->next;
            r=r->next;
        }
        if (r) {
            l->next=l->next->next;
            return head;
        } else {
            return head->next;
        }
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* header=new ListNode();
        header->next=head;
        ListNode* l=header;
        ListNode* r=header;
        for (int i=0; i<n; ++i) r=r->next;
        while (r->next) {
            l=l->next;
            r=r->next;
        }
        l->next=l->next->next;
        // return l==header?header->next:head; -> l==header means we need to remove head
        return header->next;
    }
};