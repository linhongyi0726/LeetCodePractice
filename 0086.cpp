// First time
/*
    Use small and large header to help
    T: O(n)/S: O(1)
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