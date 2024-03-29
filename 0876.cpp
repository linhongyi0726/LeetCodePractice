// Second time
/*
    T: O(n)/S: O(1)
*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

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