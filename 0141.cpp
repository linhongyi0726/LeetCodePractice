// First time
/*
    Use Floyd Cycle Detection Algorithm (Tortoise and Hare Algorithm)
    If there is a cycle, two pointer will be together
    T: O(n)/S: O(1)
    * Notice the while condition to avoid null pointer
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};