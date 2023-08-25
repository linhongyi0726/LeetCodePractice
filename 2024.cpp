// First time
/*
    map + sliding windows (it's same with problem 424)
    T: O(n)/S: O(1) -> map will only contain 2 elements
*/
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        unordered_map<char, int> freq;
        int ans=0, maxf=0, l=0, r=0;
        for (; r<answerKey.length(); ++r) {
            maxf=max(maxf, ++freq[answerKey[r]]);
            if (r-l+1-maxf > k) --freq[answerKey[l++]];
            ans=r-l+1;
        }
        return ans;
    }
};

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        unordered_map<char, int> freq;
        int maxf=0, l=0, r=0;
        for (; r<answerKey.length(); ++r) {
            maxf=max(maxf, ++freq[answerKey[r]]);
            if (r-l+1-maxf > k) --freq[answerKey[l++]];
        }
        return r-l;
    }
};

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        unordered_map<char, int> freq;
        int size=0, maxf=0;
        for (int i=0; i<answerKey.length(); ++i) {
            maxf=max(maxf, ++freq[answerKey[i]]);
            size++;
            if (size-maxf > k) --freq[answerKey[i-(--size)]];
        }
        return size;
    }
};