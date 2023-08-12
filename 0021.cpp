// Second time
/*
    T: O(n)/S: O(n)
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
};

// First time
/*
    Iterative approach
    Declare a linked list "head" and initialize it to the smaller value in list1/list2 or 0
    Then use the same linked list "cur" to point current position in list1/list2
    At last, fill the last value of list1 or list2 to "head"
    * Notice the edge case: if list1 or list2 is null
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        else if (!list2)
            return list1;
        ListNode *head;
        if (list1->val > list2->val) {
            head = list2;
            list2 = list2->next;
        } else {
            head = list1;
            list1 = list1->next;
        }
        ListNode *cur = head;
        while (list1 && list2) {
            if (list1->val > list2->val) {
                cur->next = list2;
                list2 = list2->next;
            } else {
                cur->next = list1;
                list1 = list1->next;
            }
            cur = cur->next;
        }
        if (list1)
            cur->next = list1;
        else if (list2)
            cur->next = list2;
        return head;
    }
};

// optimize
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode();
        ListNode *cur = head;
        while (list1 && list2) {
            if (list1->val > list2->val) {
                cur->next = list2;
                list2 = list2->next;
            } else {
                cur->next = list1;
                list1 = list1->next;
            }
            cur = cur->next;
        }
        if (list1)
            cur->next = list1;
        else if (list2)
            cur->next = list2;
        cur = head->next;
        delete head;
        return cur;
    }
};

/*
    Recursive approach
    Use list1 or list2 to be the merging list (depend on which first value is smaller)
    Then compare list->next and another list again
    * Edge case: if list1 or list2 is null (it's also the end of recursive function)
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        else if (!list2)
            return list1;

        if (list1->val > list2->val) {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        } else {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
    }
};