// First time
/*
    LRU cache require
    1. O(1) to get value -> hash map
    2. O(1) to put, means O(1) remove and insert -> double linked list,
        because we can get prev and next node in O(1) in double linked list
    Use hash map and double linked list
        map(key, list node) -> help to locate which node need to be removed/inserted
        list(key, value) -> "key" help to locate which element in map need to be removed

    In c++ STL list, there is slice() API can be used,
    which can insert iterator in any position in list
    list1_name.splice (iterator position, list2, iterator i)
*/
// Put LRU element at the begin, without using STL list
class LRUCache {
private:
    struct ListNode {
        int key;
        int val;
        ListNode *prev;
        ListNode *next;
        ListNode() : key(0), val(0), prev(nullptr), next(nullptr) {}
        ListNode(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
    };
    unordered_map<int, ListNode *> mp;
    ListNode *head = nullptr, *tail = nullptr;
    int size = 0;
public:
    LRUCache(int capacity) {
        size = capacity;
        head = new ListNode();
        tail = head;
    }

    int get(int key) {
        if (!mp.count(key))
            return -1;
        // remove node
        // check size to avoid tail==head, it will have problem when put() use tail->prev->next
        if (mp[key] == tail && mp.size() > 1)
            tail = tail->prev;
        if (mp[key]->next)
            mp[key]->next->prev = mp[key]->prev;
        mp[key]->prev->next = mp[key]->next;
        // add node at the begin (after head)
        mp[key]->prev = head;
        mp[key]->next = head->next;
        if (mp[key]->next)
            mp[key]->next->prev = mp[key];
        head->next = mp[key];
        return mp[key]->val;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            // call get() to let node move to begin
            get(key);
            mp[key]->val = value;
        } else {
            // remove oldest node (tail node)
            if (mp.size() == size) {
                mp.erase(tail->key);
                ListNode *tmp = tail;
                tail->prev->next = tail->next;
                tail = tail->prev;
                delete tmp;
            }
            // add new node at the begin (after head)
            ListNode *node = new ListNode(key, value);
            if (!mp.size())
                tail = node;
            node->prev = head;
            node->next = head->next;
            if (node->next)
                node->next->prev = node;
            head->next = node;
            mp[key] = node;
        }
    }
};

// Put LRU element at the begin of list, it's better to put in hash map
class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> ls;
    int size = 0;
    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {
        if (!mp.count(key))
            return -1;
        ls.splice(ls.begin(), ls, mp[key]);
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        if (mp.count(key)) {
            ls.splice(ls.begin(), ls, mp[key]);
            mp[key]->second = value;
        } else {
            if (mp.size() == size) {
                mp.erase(ls.back().first);
                ls.pop_back();
            }
            ls.push_front({key, value});
            mp[key] = ls.begin();
        }
    }
};

// Put LRU element at the end of list
class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> ls;
    int size = 0;
    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {
        if (!mp.count(key))
            return -1;
        ls.splice(ls.end(), ls, mp[key]);
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        if (mp.count(key)) {
            ls.splice(ls.end(), ls, mp[key]);
            mp[key]->second = value;
        } else {
            if (mp.size() == size) {
                mp.erase(ls.front().first);
                ls.pop_front();
            }
            ls.push_back({key, value});
            mp[key] = prev(ls.end());
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */