// First time
/*
    3 cases needed to handle
    1. pre <= insertVal <= cur
    2. insertVal > max value
    3. insertVal < min value
    T: O(n)/S: O(1)
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        Node *cur = head->next, *pre = head;
        // while (1)
        while (pre->next != head) {
            // 1 -> (2) -> 3
            if (pre->val <= insertVal && cur->val >= insertVal)
                break;
            // 3 -> (0) -> 1
            if (pre->val > cur->val && insertVal < cur->val)
                break;
            // 3 -> (4) -> 1
            if (pre->val > cur->val && insertVal > pre->val)
                break;
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = new Node(insertVal, cur);
        return head;
    }
};