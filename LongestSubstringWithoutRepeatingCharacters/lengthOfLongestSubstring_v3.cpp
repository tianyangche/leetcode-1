class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        unordered_map<char, int> prev;
        int posi = 0;
        int len  = 0;
        for (int i = 0; i < s.length(); i++) {
            if (prev.count(s[i]) > 0 && prev[s[i]] >= posi){
                posi = prev[s[i]] + 1;
            }
            prev[s[i]] = i;
            len = max(len, i - posi + 1);
        }
        return len;
    }
};