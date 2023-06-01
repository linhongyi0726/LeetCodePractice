// First time
/*
    1. Sort
        Sort by pow of distance then return
        T: O(nlogn)/S: O(1)
    2. nth_element
        nth_element is implemented by introselect
        T: O(n)/S: O(1)
    3. Quick select
        T: O(n)
    4. Heap
        T: O(nlogk)/S: O(k) -> if use max-heap
*/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) {
        //     return pow(a[0],2)+pow(a[1],2) < pow(b[0],2)+pow(b[1],2);
        //     });
        nth_element(points.begin(), points.begin()+k-1, points.end(), [](vector<int> a, vector<int> b) {
            return pow(a[0],2)+pow(a[1],2) < pow(b[0],2)+pow(b[1],2);
            });
        return {points.begin(), points.begin()+k};
    }
};

/*
    Heap (priority queue) -> Can be used to solve kth closest/kth smallest/kth largest problem
    Here we use max-heap instead of min-heap because we only need to store k point in max-heap
    If we use min-heap, we need to store all points
*/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, pair<int,int>>> pq;
        for (auto point : points) {
            int dist = pow(point[0],2) + pow(point[1],2);
            // pq.push({dist, {point[0], point[1]}});
            pq.push(make_pair(dist, make_pair(point[0], point[1])));
            if (pq.size() > k)
                pq.pop();
        }
        while (!pq.empty()) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};