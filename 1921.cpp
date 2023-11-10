// First time
/*
    Use dist array to store the arrive time,
    here we need to subtract 1,
    and the judgement for killing monster should be arrive time >= attack times
    e.g.
    dist:10, speed:5
    10/5=2, means we will lose at 2 minute, (10-1)/5=1.8 can judge it

    T: O(n)/S: O(1)
*/
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        for (int i = 0; i < n; ++i) {
            dist[i] = (dist[i] - 1) / speed[i];
        }
        sort(dist.begin(), dist.end());
        for (int i = 0; i < n; ++i) {
            if (dist[i] < i)
                return i;
        }
        return n;
    }
};

/*
    Sort the arrive time (notice to use double)
    If the arrive time > index (attack time), the monster can be eliminated

    T: O(n)/S: O(n)
*/
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> time(n, 0);
        for (int i = 0; i < n; ++i) {
            time[i] = (double)dist[i] / speed[i];
        }
        sort(time.begin(), time.end());
        for (int i = 0; i < n; ++i) {
            if (time[i] <= i)
                return i;
        }
        return n;
    }
};