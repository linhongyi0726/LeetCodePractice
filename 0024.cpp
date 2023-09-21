// Second time
/*
    dummy/cur -> 1 -> 2 -> ...
    We only need to do swap when there are cur->next and cur->next->next
    T: O(n)/S: O(1)
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *cur = dummy;
        while (cur->next && cur->next->next) {
            ListNode *tmp = cur->next;
            cur->next = cur->next->next;
            tmp->next = cur->next->next;
            cur->next->next = tmp;
            cur = cur->next->next;
        }
        return dummy->next;
    }
};

// First time
/*
    Iteration

    1 -> 2 -> 3 -> 4   =>   1 <- 2   3 -> 4
    ^    ^    ^             ^    ^   ^
  head   |   tmp           cur   |  head
      cur/header               header
    
    T: O(n)/S: O(1)
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *header = new ListNode();
        ListNode *cur = header;
        while (head && head->next) {
            ListNode *tmp = head->next->next;
            cur->next = head->next;
            cur->next->next = head;
            head = tmp;
            cur = cur->next->next;
        }
        // if (head) cur->next = head;
        // else cur->next = nullptr;
        cur->next = head;
        cur = header->next; delete header;
        return cur;
    }
};

/*
    Recursion
                            |--------v
    1 -> 2 -> 3 -> 4   =>   1 <- 2   3 -> 4
    ^         ^                  ^   ^
 head/tmp    tail              head  tail

    T: O(n)/S: O(1)
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *tail = swapPairs(head->next->next);
        ListNode *tmp = head;
        head = head->next;
        head->next = tmp;
        head->next->next = tail;
        return head;
    }
};

/*
                            |--------v
    1 -> 2 -> 3 -> 4   =>   1 <- 2   3 -> 4
    ^    ^    ^             ^    ^
  head  ans               head  ans
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *ans = head->next;
        head->next = swapPairs(head->next->next);
        ans->next = head;
        return ans;
    }
};
