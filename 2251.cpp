// First time
/*
    Binary search

    0, 1, 2, 3, 4, 5, 6, 7
      |____|
         |________|
                     |____|
          p
          e           s    => 2-0 = 2
    use upper_bound() to find the start -> s = 2
    -> can remain the person's position
    use lower_bound() to find the end -> e = 0
    -> not include the person's position

    T: O(nlogn)/S: O(n)
*/
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start, end;
        for (auto flower : flowers) {
            start.push_back(flower[0]);
            end.push_back(flower[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int n = people.size();
        vector<int> ret(n, 0);
        for (int i = 0; i < n; ++i) {
            int s = upper_bound(start.begin(), start.end(), people[i]) - start.begin();
            int e = lower_bound(end.begin(), end.end(), people[i]) - end.begin();
            ret[i] = s - e;
        }
        return ret;
    }
};

/*
    Sweep line algorithm (difference array) + ordered structure (map, sorted vector, priority queue)
    Use diff array to record the change in the flower bloom interval
    then use binary search to find the interval or directly use two ptr to sweep
    T: O(nlogn)/S: O(n)
*/
// map + binary search
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> diff;
        // [start, end] -> so the end time need to plus one
        for (auto flower : flowers) {
            diff[flower[0]]++;
            diff[flower[1] + 1]--;
        }
        int sum = 0;
        // It will represent the amount of bloom flowers in the day
        for (auto &[day, cnt] : diff) {
            sum += cnt;
            cnt = sum;
        }
        int n = people.size();
        vector<int> ret(n, 0);
        // Use binary search instead of sorting people and sweeping
        for (int i = 0; i < n; ++i) {
            auto it = diff.upper_bound(people[i]);
            if (it != diff.begin())
                ret[i] = prev(it)->second;
        }
        return ret;
    }
};

// map + 2 ptr
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> diff;
        for (auto flower : flowers) {
            diff[flower[0]]++;
            diff[flower[1] + 1]--;
        }
        // {day, cnt}
        vector<pair<int, int>> cnt(diff.begin(), diff.end());
        // {day, people idx}
        vector<pair<int, int>> p;
        int n = people.size();
        for (int i = 0; i < n; ++i)
            p.push_back({people[i], i});
        sort(p.begin(), p.end());

        // use two ptr to sweep and count the diff array
        vector<int> ret(n, 0);
        int j = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            // accumulate the diff
            while (j < cnt.size() && cnt[j].first <= p[i].first) {
                sum += cnt[j].second;
                j++;
            }
            ret[p[i].second] = sum;
        }
        return ret;
    }
};

// sorted array + traversal
class Solution {
    enum {
        start, end, person
    };
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<vector<int>> v;
        int n = people.size();
        for (auto flower : flowers) {
            v.push_back({flower[0], start});
            v.push_back({flower[1] + 1, end});
        }
        for (int i = 0; i < n; ++i) {
            v.push_back({people[i], person, i});
        }
        sort(v.begin(), v.end());

        vector<int> ret(n, 0);
        int sum = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i][1] == start)
                sum++;
            else if (v[i][1] == end)
                sum--;
            else
                ret[v[i][2]] = sum;
        }
        return ret;
    }
};