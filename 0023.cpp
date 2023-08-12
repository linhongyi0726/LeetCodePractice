// First time
/*
    Divide and Conquer -> reduce to merge two lists
    T: O(nlog⁡k)/S: O(1)
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ans = new ListNode();
        ListNode *cur = ans;
        while (list1 && list2) {
            if (list1->val > list2->val) {
                cur->next = list2;
                cur = cur->next;
                list2 = list2->next;
            } else {
                cur->next = list1;
                cur = cur->next;
                list1 = list1->next;
            }
        }
        if (list1) cur->next = list1;
        else cur->next = list2;
        return ans->next;
    }
/*
    Put the merged list to the end, and erase the first two list in lists
*/
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        while (lists.size()>1) {
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.empty() ? nullptr : lists[0];
    }

/*
    0 1 2 3 4 -> 0 1 2 -> 0 1 -> 0
    ^       ^    ^   ^    ^ ^
*/
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        while (n>1) {
            for (int i=0; i<n/2; ++i) {
                lists[i]=mergeTwoLists(lists[i], lists[n-1-i]);
            }
            n=(n+1)/2;
        }
        return lists.empty() ? nullptr : lists[0];
    }

/*
    0 1 2 3 4 5 6 7 8  n=9
    _ _ _ _ _ _ _ _ _  len=1
    ___ ___ ___ ___ _  len=2
    _______ _______ _  len=4
    _______________ _  len=8
    _________________  len=16>n -> end loop
*/
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size(), len=1;
        while (len<n) {
            for (int i=0; i+len<n; i+=len*2) {
                lists[i]=mergeTwoLists(lists[i], lists[i+len]);
            }
            len*=2;
        }
        return lists.empty() ? nullptr : lists[0];
    }
};

/*
    Use heap
    T: O(nlogk)/S: O(n)
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode* l1, ListNode* l2) {return l1->val > l2->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        for (auto list : lists) {
            while (list) {
                pq.push(list);
                list=list->next;
            }
        }
        ListNode *header = new ListNode();
        ListNode *cur = header;
        while (!pq.empty()) {
            cur->next = pq.top();
            pq.pop();
            cur = cur->next;
        }
        cur->next=nullptr;  // ***NOTICE to set the end of linked list to avoid to create a loop
        return header->next;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode* l1, ListNode* l2) {return l1->val > l2->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        for (auto list : lists) {
            if (list) pq.push(list);
        }
        ListNode *header = new ListNode();
        ListNode *cur = header;
        while (!pq.empty()) {
            cur->next = pq.top();
            if (pq.top()->next) pq.push(pq.top()->next);
            pq.pop();
            cur = cur->next;
        }
        return header->next;
    }
};