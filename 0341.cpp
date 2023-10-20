// First time
/*
    Just use one stack and add the next integer in the stack when every time we call hasNext()
*/
// stack with iterator
class NestedIterator {
public:
    stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> s;
    NestedIterator(vector<NestedInteger> &nestedList) {
        s.push({nestedList.begin(), nestedList.end()});
    }
    
    int next() {
        auto cur = s.top();
        s.top().first++;
        return cur.first->getInteger();
    }
    
    bool hasNext() {
        while (!s.empty()) {
            if (s.top().first == s.top().second) {
                s.pop();
            } else if (s.top().first->isInteger()) {
                return true;
            } else {
                auto cur = s.top();
                s.top().first++;
                s.push({cur.first->getList().begin(), cur.first->getList().end()});
            }
        }
        return false;
    }
};

// stack with every nodes
class NestedIterator {
public:
    stack<NestedInteger> s;
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; --i)
            s.push(nestedList[i]);
    }
    
    int next() {
        // the top element must be integer
        int cur = s.top().getInteger();
        s.pop();
        return cur;
    }
    
    bool hasNext() {
        while (!s.empty()) {
            if (s.top().isInteger()) {
                return true;
            } else {
                auto cur = s.top().getList();
                s.pop();
                for (int i = cur.size() - 1; i >= 0; --i)
                    s.push(cur[i]);
            }
        }
        return false;
    }
};

/*
    Use dfs/stack to traverse the nestedList and push the integer in a queue
    we can add when we initialize NestedIterator() or when we call hasNext()
*/
// use stack to add integer when we initialize
class NestedIterator {
public:
    queue<int> q;
    NestedIterator(vector<NestedInteger> &nestedList) {
        stack<NestedInteger> s;
        for (int i = nestedList.size() - 1; i >= 0; --i)
            s.push(nestedList[i]);
        while (!s.empty()) {
            auto cur = s.top();
            s.pop();
            if (cur.isInteger()) {
                q.push(cur.getInteger());
            } else {
                auto v = cur.getList();
                for (int i = v.size() - 1; i >= 0; --i)
                    s.push(v[i]);
            }
        }
    }
    
    int next() {
        int cur = q.front();
        q.pop();
        return cur;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

// use dfs to add integer when we initialize
class NestedIterator {
public:
    queue<int> q;
    void dfs(vector<NestedInteger> &nestedList) {
        for (int i = 0; i < nestedList.size(); ++i) {
            if (nestedList[i].isInteger())
                q.push(nestedList[i].getInteger());
            else
                dfs(nestedList[i].getList());
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
    }
    
    int next() {
        int cur = q.front();
        q.pop();
        return cur;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */