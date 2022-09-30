// First time
/*
    1. Brute-force
    2. Two pointer (similar with problem 141: find cycle in the linked list)
        Use slow and fast pointer
        fast = slow * 2
        When fast pointer traverse the linked list, slow pointer is the middle of the linked list
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

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
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        ListNode* ans = head;
        while (head) {
            head = head->next;
            ++len;
        }
        for (int i = 0; i < len/2; ++i)
            ans = ans->next;
        return ans;
    }
};