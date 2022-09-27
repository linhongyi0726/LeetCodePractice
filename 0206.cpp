// First time
/*
    Iteration
    Need to save prev and cur pointer
    Try recursion?
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