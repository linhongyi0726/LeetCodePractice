// Second time
// Second time
/*
    T: O(n)/S: O(1)
*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy=new ListNode();
        ListNode *cur=dummy;
        while (head) {
            if (head->val != val) {
                cur->next=head;
                head=head->next;
                cur=cur->next;
            } else {
                ListNode *tmp=head;
                head=head->next;
                delete tmp;
            }
        }
        cur->next=nullptr;
        cur=dummy->next;
        delete dummy;
        return cur;
    }
};

// First time
/*
    See current node is val or not, and use another list "tail" to link non-val node
    T: O(n)/S: O(1)
*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *header = new ListNode();
        ListNode *tail = header;
        while (head) {
            if (head->val == val) {
                ListNode *tmp = head;
                head = head->next;
                delete tmp;
            } else {
                tail->next = head;
                tail = tail->next;
                head = head->next;
            }
        }
        tail->next = nullptr;
        tail = header->next;
        delete header;
        return tail;
    }
};

/*
    See the next node is val or not
    T: O(n)/S: O(1)
*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *header = new ListNode();
        header->next = head;
        ListNode *tail = header;
        while (tail->next) {
            if (tail->next->val == val) {
                ListNode *tmp = tail->next;
                tail->next = tail->next->next;
                delete tmp;
            } else {
                tail = tail->next;
            }
        }
        tail = header->next;
        delete header;
        return tail;
    }
};
