// First time
/*
    *Notice "while (oddTail->next && evenTail->next)" here need to judge odd->next first,
    to avoid odd elements in the linked list -> evenTail will become nullptr
    [1, 2, 3, 4, 5]
                 ^  ^
                odd  even
    T: O(n)/S: O(1)
*/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
      if (!head) return nullptr;
      ListNode *oddHead=head, *oddTail=oddHead;
      ListNode *evenHead=head->next, *evenTail=evenHead;
      while (oddTail->next && evenTail->next) {
        oddTail->next=oddTail->next->next;
        evenTail->next=evenTail->next->next;
        oddTail=oddTail->next;
        evenTail=evenTail->next;
      }
      oddTail->next=evenHead;
      return oddHead;
    }
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
      ListNode *oddHead=new ListNode(), *oddTail=oddHead;
      ListNode *evenHead=new ListNode(), *evenTail=evenHead;
      int cnt=1;
      while (head) {
        if (cnt&1) {
          oddTail->next=head;
          oddTail=oddTail->next;
        } else {
          evenTail->next=head;
          evenTail=evenTail->next;
        }
        head=head->next;
        cnt++;
      }
      oddTail->next=evenHead->next;
      evenTail->next=nullptr;
      return oddHead->next;
    }
};