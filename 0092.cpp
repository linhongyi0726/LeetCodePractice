// First time
/*
    Follow the steps to reverse (*Note the prev and cur node is constant, no need to move on)
    c->next = t->next; (we won't let l==r, so t won't be NULL)
    t->next = p->next; (here need to connect to p->next NOT c)
    p->next = t;

    (1)
              l         r
    d -> 1 -> 2 -> 3 -> 4 -> 5
         p    c    t
          _________
         |         v
    d -> 1    2 <- 3    4 -> 5
              |_________^

    (2)
    d -> 1 -> 3 -> 2 -> 4 -> 5
         p         c    t
          ______________
         |              v
    d -> 1    3 -> 2    4    5
         p    ^____|____|    ^
                   |_________|
    (3)
    d -> 1 -> 4 -> 3 -> 2 -> 5
         p              c    t

    T: O(n)/S: O(1)
*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *prev = dummy, *cur = head;
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
            cur = cur->next;
        }
        for (int i = left; i < right; ++i) {
            ListNode *tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = prev->next;
            prev->next = tmp;
        }
        return dummy->next;
    }
};