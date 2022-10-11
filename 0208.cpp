// First time
class Trie {
public:
    struct Node
    {
        vector<Node*> children;
        bool end;
        Node() {
            children = vector<Node*>(26, 0);
            end = false;
        }
    };

    struct Node* root;

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;
        for (auto c : word) {
            if (!cur->children[c-'a'])
                cur->children[c-'a'] = new Node();
            cur = cur->children[c-'a'];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        for (auto c : word) {
            if (cur->children[c-'a'])
                cur = cur->children[c-'a'];
            else
                return false;
        }
        return cur->end;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for (auto c : prefix) {
            if (cur->children[c-'a'])
                cur = cur->children[c-'a'];
            else
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */