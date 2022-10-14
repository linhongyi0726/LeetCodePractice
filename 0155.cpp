// First time
/*
    Implement by two stack/vector
    T: O(1)/S: (n)
*/
class MinStack {
public:
    vector<pair<int,int>> v;
    MinStack() {
        
    }
    
    void push(int val) {
        if (v.empty())
            v.push_back({val,val});
        else
            v.push_back({val,min(val,v.back().second)});
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second;
    }
};

class MinStack {
public:
    stack<int> s;
    stack<int> ms;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if (!ms.empty())
            ms.push(min(val,ms.top()));
        else
            ms.push(val);
    }
    
    void pop() {
        s.pop();
        ms.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ms.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */