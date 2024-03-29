// First time
class MyQueue {
public:
    stack<int> s, q;
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        int ret = peek();
        q.pop();
        return ret;
    }
    
    int peek() {
        if (q.empty()) {
            while (!s.empty()) {
                q.push(s.top());
                s.pop();
            }
        }
        return q.top();
    }
    
    bool empty() {
        return s.empty() && q.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */