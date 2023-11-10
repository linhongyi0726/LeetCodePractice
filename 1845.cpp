// First time
/*
    Use counter to record the maximum unreserved seat,
    if there is any seat be unreserved, push into min-heap
    (the seat in the min-heap must smaller than the counter)
    Thus, we don't need to store all the seat in the min-heap

    T: O(nlogn)/S: O(n)
*/
class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int mx = 1;
    SeatManager(int n) {
    }
    
    int reserve() {
        int cur;
        if (!pq.empty()) {
            cur = pq.top();
            pq.pop();
        } else {
            cur = mx;
            mx++;
        }
        return cur;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/*
    Use min-heap or set to store all unreserved seat
    T: O(nlogn)/S: O(n)
*/
class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    SeatManager(int n) {
        for (int i = 1; i <= n; ++i)
            pq.push(i);
    }
    
    int reserve() {
        int cur = pq.top();
        pq.pop();
        return cur;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

class SeatManager {
public:
    set<int> s;
    SeatManager(int n) {
        for (int i = 1; i <= n; ++i)
            s.insert(i);
    }
    
    int reserve() {
        int cur = *s.begin();
        s.erase(cur);
        return cur;
    }
    
    void unreserve(int seatNumber) {
        s.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */