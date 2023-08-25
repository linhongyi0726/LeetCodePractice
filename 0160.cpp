// First time
/*
    Length compare solution optimize -> 2 ptr solution
    A: a+c
    B: b+c
    So use 2 ptr to traverse a+b+c length will must meet each other someday,
    Otherwise there isn't intersection, they will all be nullptr
    T: O(m+n)/S: O(1)
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a=headA, *b=headB;
        while (a!=b) {
            if (a) a=a->next;
            else a=headB;
            if (b) b=b->next;
            else b=headA;
        }
        return a;
    }
};

/*
    Length compare solution
    A: a+c
    B: b+c
    If a>b, let A ptr back to headA then traverse together again
    It will become:
    A: a-(a-b)+c
    B: b+c
    Then traverse together again will visit the same node

    T: O(m+n)/S: O(1)
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a=headA, *b=headB;
        while (a&&b) {
            a=a->next;
            b=b->next;
        }
        if (a) {
            // len(a)>len(b)
            b=a;
            a=headA;
            while (a&&b) {
                a=a->next;
                b=b->next;
            }
            b=headB;
            while (a&&b) {
                if (a==b) return a;
                a=a->next;
                b=b->next;
            }
        } else {
            // len(b)>=len(a)
            a=b;
            b=headB;
            while (a&&b) {
                a=a->next;
                b=b->next;
            }
            a=headA;
            while (a&&b) {
                if (a==b) return a;
                a=a->next;
                b=b->next;
            }
        }
        return nullptr;
    }
};

// Optimize
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a=headA, *b=headB;
        while (a&&b) {
            a=a->next;
            b=b->next;
        }
        // Let len(a) always >= len(b)
        if (b) {swap(a, b); swap(headA, headB);}
        b=headA;
        while (a&&b) {
            a=a->next;
            b=b->next;
        }
        a=headB;
        while (a&&b) {
            if (a==b) return a;
            a=a->next;
            b=b->next;
        }
        return nullptr;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a=headA, *b=headB;
        while (a&&b) {
            a=a->next;
            b=b->next;
        }
        // Let len(a) always >= len(b)
        if (b) {swap(a, b); swap(headA, headB);}
        while (a) {
            a=a->next;
            headA=headA->next;
        }
        while (headA!=headB) {
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};

/*
    T:O(n)/ S:O(n)
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s;
        ListNode *cur=headA;
        while (cur) {
            s.insert(cur);
            cur=cur->next;
        }
        cur=headB;
        while (cur) {
            if (s.count(cur)) return cur;
            cur=cur->next;
        }
        return nullptr;
    }
};