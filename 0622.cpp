// First time
/*
    max size = 5
    _, 1, 2, 3, _
       ^        ^
     start     end
*/

class MyCircularQueue {
private:
    vector<int> v;
    int start, end, count, size;
public:
    MyCircularQueue(int k) {
        v.resize(k);
        start = 0;
        end = 0;
        count = 0;
        size = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        v[end] = value;
        end = (end + 1) % size;
        count++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        start = (start + 1) % size;
        count--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        else return v[start];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        else return v[(end - 1 + size) % size];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */