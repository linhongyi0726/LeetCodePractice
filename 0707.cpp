// First time
/*
    Singly Linked List
*/
class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x): val(x), next(nullptr){}
    };
    struct ListNode *header;
    int size=0;

    MyLinkedList() {
        header=new ListNode(0);
        size=0;
    }
    
    int get(int index) {
        if (index>=size || index<0) return -1;
        ListNode *cur=header->next;
        while (index--) cur=cur->next;
        return cur->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index>size || index<0) return;
        ListNode *cur=header;
        ListNode *newNode=new ListNode(val);
        while (index--) cur=cur->next;
        newNode->next=cur->next;
        cur->next=newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index>=size || index<0) return;
        ListNode *cur=header;
        while (index--) cur=cur->next;
        ListNode *tmp=cur->next;
        cur->next=cur->next->next;
        delete tmp;
        size--;
    }
};

/*
    Doubly Linked List
    *Notice cur->next would be nullptr at tail
*/
class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode *prev;
        ListNode *next;
        ListNode(int x): val(x), prev(nullptr), next(nullptr){}
    };
    struct ListNode *header;
    int size=0;

    MyLinkedList() {
        header=new ListNode(0);
        size=0;
    }
    
    int get(int index) {
        if (index<0 || index>=size) return -1;
        ListNode *cur=header->next;
        while (index--) cur=cur->next;
        return cur->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index<0 || index>size) return;
        ListNode *cur=header;
        while (index--) cur=cur->next;
        ListNode *node=new ListNode(val);
        node->next=cur->next;
        node->prev=cur;
        cur->next=node;
        if (node->next) node->next->prev=node;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index<0 || index>=size) return;
        ListNode *cur=header->next;
        while (index--) cur=cur->next;
        cur->prev->next=cur->next;
        if (cur->next) cur->next->prev=cur->prev;
        delete cur;
        size--;
    }
};