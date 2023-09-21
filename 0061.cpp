// First time
/*
    1 pass: find the length of list
    2 pass: rotate k%n nodes
    T: O(n)/S: O(1)
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;
        ListNode *cur = head;
        int n = 1;
        while (cur->next) {
            cur = cur->next;
            ++n;
        }
        cur->next = head;
        cur = head;
        k %= n;
        for (int i = 0; i < n - k - 1; ++i)
            cur = cur->next;
        head = cur->next;
        cur->next = nullptr;
        return head;
    }
};