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