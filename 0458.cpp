// First time
/*
    It can be represented to times+1 based number
    https://leetcode.com/problems/poor-pigs/solutions/94273/solution-with-detailed-explanation/
    e.g.
        buckets=4, minutesToDie=15, minutesToTest=15
        -> can test 1 times
        buckets:   0  1  2  3
        1th round: -- -B A- AB -> 'A', 'B' means two different pigs
                   00 01 10 11 -> '1' means drink at 1th rounds

        buckets=4, minutesToDie=15, minutesToTest=30
        -> can test 2 times
        buckets:   0  1  2  3
        1th round: -- -B -- A-
        2th round: -- -- -B --
                   00 01 02 10 -> like 3-based number (times+1)

        buckets=8, minutesToDie=15, minutesToTest=40
        -> can test 2 times
        buckets:   0  1  2  3  4  5  6  7
        1th round: -- -B -- A- AB A- -- -B
        2th round: -- -- -B -- -- -B A- A-
                   00 01 02 10 11 12 20 21

        So the number of pigs means the "bit" number of bucket,
        and the n-based is times+1 based
        -> (times+1)^x = bucket
           x*log2(times+1) = log2(bucket)
           x = log2(bucket) / log2(times+1) -> do ceil() to get larger integer

    p.s. use ceil(log(buckets)/log(times+1)) will fail at this case:
         buckets=125, minutesToDie=1, minutesToTest=4

    T: O(1)/S: O(1)
*/
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int times = minutesToTest / minutesToDie;
        return ceil(log2(buckets) / log2(times + 1));
    }
};