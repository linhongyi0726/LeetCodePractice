// First time
/*
    Ignore the ants will change direction
    Because when two ants meet and both change direction,
    looks like they don't change direction and continually walk
    a->
    |--|--|--|--|
              <-b
          a->
    |--|--|--|--|
        <-b
    the walk distance is the same as ants don't change direction
    (looks like b ants help a ants finish its walk distance, and vice versa)
        <-a                           a->
    |--|--|--|--|  the same as  |--|--|--|--|
          b->                       <-b
    
    So we just need to find the farthest ants (to left: biggest, to right: smallest)

    T: O(n)/S: O(1)
*/
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ret = 0;
        for (int i : left)
            ret = max(ret, i);
        for (int i : right)
            ret = max(ret, n - i);
        return ret;
    }
};