// First time
/*
    use array to handle O(1) access and linked list to handle collision
*/
// STL list
class MyHashMap {
private:
    int size = 10000;
    vector<list<pair<int, int>>> bucket;
    int hash(int key) {
        return key % size;
    }
public:
    MyHashMap() {
        bucket.resize(size);
    }
    
    void put(int key, int value) {
        int idx = hash(key);
        for (auto &node : bucket[idx]) {
            if (node.first == key) {
                node.second = value;
                return;
            }
        }
        bucket[idx].push_back({key, value});
        return;
    }
    
    int get(int key) {
        int idx = hash(key);
        for (auto node : bucket[idx]) {
            if (node.first == key)
                return node.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = hash(key);
        for (auto node : bucket[idx]) {
            if (node.first == key) {
                bucket[idx].remove(node);
                return;
            }
        }
        return;
    }
};

// self made linked list
class MyHashMap {
private:
    struct ListNode {
        int key, val;
        ListNode *next;
        ListNode(int key, int val, ListNode *next): key(key), val(val), next(next) {}
    };
    int size = 10000;
    vector<ListNode *> bucket;

    int hash(int key) {
        return key % size;
    }

public:
    MyHashMap() {
        bucket.resize(size);
    }
    
    void put(int key, int value) {
        int idx = hash(key);
        if (get(key) != -1) {
            ListNode *cur = bucket[idx];
            while (cur) {
                if (cur->key == key) {
                    cur->val = value;
                    return;
                }
                cur = cur->next;
            }
        } else {
            bucket[idx] = new ListNode(key, value, bucket[idx]);
        }
        return;
    }
    
    int get(int key) {
        int idx = hash(key);
        ListNode *cur = bucket[idx];
        while (cur) {
            if (cur->key == key)
                return cur->val;
            cur = cur->next;
        }
        return -1;
    }
    
    void remove(int key) {
        if (get(key) == -1)
            return;
        int idx = hash(key);
        ListNode *dummy = new ListNode(0, 0, nullptr);
        dummy->next = bucket[idx];
        ListNode *cur = dummy;
        while (cur->next) {
            if (cur->next->key == key) {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                bucket[idx] = dummy->next;
                delete tmp;
                return;
            }
            cur = cur->next;
        }
        return;
    }
};

/*
    only implement by array
*/
class MyHashMap {
private:
    vector<int> map;
public:
    MyHashMap() {
        map = vector<int>(1000001, -1);
    }
    
    void put(int key, int value) {
        map[key] = value;
    }
    
    int get(int key) {
        return map[key];
    }
    
    void remove(int key) {
        map[key] = -1;
    }
};