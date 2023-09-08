// First time
/*
    2 pass
    move one more time if still have remainder
    T: O(n)/S: O(1)
*/
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode *cur = head;
        while (cur) {
            cur = cur->next;
            ++n;
        }
        int cnt = n / k, rem = n % k;
        vector<ListNode *> ret(k, nullptr);
        ListNode *prev = new ListNode();
        cur = head;
        // --rem in every loops to make sure no extra remainder
        for (int i = 0; i < k; ++i, --rem) {
            ret[i] = cur;
            for (int j = 0; j < cnt + (rem > 0); ++j) {
                prev = cur;
                cur = cur->next;
            }
            prev->next = nullptr;
        }
        return ret;
    }
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode *cur = head;
        while (cur) {
            cur = cur->next;
            ++n;
        }
        int cnt = n / k, rem = n % k;
        vector<ListNode *> ret(k, nullptr);
        for (int i = 0; i < k; ++i) {
            ret[i] = head;
            cur = new ListNode();
            cur->next = head;
            for (int j = 0; j < cnt; ++j) {
                head = head->next;
                cur = cur->next;
            }
            if (i < rem) {
                head = head->next;
                cur = cur->next;
            }
            cur->next = nullptr;
        }
        return ret;
    }
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode *cur = head;
        while (cur) {
            cur = cur->next;
            ++n;
        }
        int cnt = n / k, rem = n % k;
        vector<ListNode *> ret(k, nullptr);
        for (int i = 0; i < k; ++i) {
            ListNode *header = new ListNode();
            cur = header;
            cur->next = head;
            for (int j = 0; j < cnt; ++j) {
                head = head->next;
                cur = cur->next;
            }
            if (i < rem) {
                head = head->next;
                cur = cur->next;
            }
            cur->next = nullptr;
            ret[i] = header->next;
        }
        return ret;
    }
};