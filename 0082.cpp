// First time
/*
    without variable to record the same node or not
    *Notice to add nullptr at last to avoid remaining the same value in the end
    e.g. [1,2,2]

    T: O(n)/S: O(1)
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;
        while (head) {
            if (!head->next || (head->val != head->next->val)) {
                cur->next = head;
                cur = cur->next;
            } else {
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
            }
            head = head->next;
        }
        cur->next = nullptr;
        return dummy->next;
    }
};

/*
    use a variable to record that we have visited the same node, then skip it
    T: O(n)/S: O(1)
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;
        bool thesame = false;
        while (head) {
            thesame = false;
            while (head->next && head->val == head->next->val) {
                thesame = true;
                head = head->next;
            }
            if (!thesame) {
                cur->next = head;
                cur = cur->next;
            }
            head = head->next;
        }
        cur->next = nullptr;
        return dummy->next;
    }
};