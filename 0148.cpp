// First time
/*
    Use multiset to sort ListNode
    T: O(nlogn)/S: O(n)
    -----
    Merge sort (recursion)
    Find the middle to divide and merge them (problem 876 + problem 21)
    *Notice to handle only two nodes case, keep prev node or modify while loop condition
    T: O(nlogn)/S: O(logn)
    ----
    Try merge sort in iteration -> S: O(1)
*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *slow = head, *fast = head;
        // Need to handle two nodes case
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *tmp = slow->next;
        slow->next = nullptr;
        ListNode *left = sortList(head);
        ListNode *right = sortList(tmp);
        return merge(left, right);
    }
    ListNode *merge(ListNode *left, ListNode *right) {
        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;
        while (left && right) {
            if (left->val > right->val) {
                cur->next = right;
                right = right->next;
            } else {
                cur->next = left;
                left = left->next;
            }
            cur = cur->next;
        }
        if (left)
            cur->next = left;
        else if (right)
            cur->next = right;
        cur = dummy->next;
        delete dummy;
        return cur;
    }
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        ListNode *left = sortList(head);
        ListNode *right = sortList(slow);
        return merge(left, right);
    }
    ListNode *merge(ListNode *left, ListNode *right) {
        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;
        while (left && right) {
            if (left->val > right->val) {
                cur->next = right;
                right = right->next;
            } else {
                cur->next = left;
                left = left->next;
            }
            cur = cur->next;
        }
        if (left)
            cur->next = left;
        else if (right)
            cur->next = right;
        cur = dummy->next;
        delete dummy;
        return cur;
    }
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        auto comp = [](ListNode* a, ListNode* b) {return a->val < b->val;};
        multiset<ListNode *, decltype(comp)> ms;
        ListNode *cur = head;
        while (cur) {
            ms.insert(cur);
            cur = cur->next;
        }
        ListNode *dummy = new ListNode();
        cur = dummy;
        while (!ms.empty()) {
            cur->next = *ms.begin();
            ms.erase(ms.begin());
            cur = cur->next;
        }
        cur->next = nullptr;
        head = dummy->next;
        delete dummy;
        return head;
    }
};