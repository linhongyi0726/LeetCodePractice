// First time
/*
    Use small and large header to help
    T: O(n)/S: O(1)
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *sh=new ListNode();    // small header
        ListNode *lh=new ListNode();    // larger header
        ListNode *st=sh, *lt=lh;
        while (head) {
            if (head->val >= x) {
                lt->next = head;
                lt = lt->next;
            } else {
                st->next = head;
                st = st->next;
            }
            head = head->next;
        }
        st->next = lh->next;
        lt->next = nullptr;
        return sh->next;
    }
};