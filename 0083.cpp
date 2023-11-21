// First time
/*
    T: O(n)/S: O(1)
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head;
        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
        ListNode *ret = new ListNode(head->val), *cur = ret;
        while (head) {
            if (head->val != cur->val) {
                cur->next = new ListNode(head->val);
                cur = cur->next;
            }
            head = head->next;
        }
        return ret;
    }
};