// First time
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int times[26] = {0};
        for (char c : magazine)
            times[c-'a']++;
        for (char c : ransomNote) {
            times[c-'a']--;
            if (times[c-'a'] < 0)
                return false;
        }
        return true;
    }
};

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        int i;
        for (i = 0; i < magazine.size(); ++i)
            mp[magazine[i]]++;
        for (i = 0; i < ransomNote.size(); ++i) {
            if (mp.count(ransomNote[i])) {
                if (mp[ransomNote[i]] == 0)
                    return false;
                mp[ransomNote[i]]--;
            }
            else
                return false;
        }
        return true;
    }
};