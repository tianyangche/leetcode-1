class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        unordered_map <char, int> recs;
        vector<int> prev(s.length(), -1);
        for (string::size_type i = 0; i < s.length(); i++) {
            if (recs.count(s[i]) > 0) {
                prev[i] = recs[s[i]];
            }
            recs[s[i]] = i;
        }
        int maxLen = 1;
        int begin  = 0;
        int end    = 0;
        int len    = 0;
        while (end < s.length()) {
            if (prev[end] < begin) {
                len++;
            } else {
                maxLen = max(maxLen, len);
                begin  = prev[end] + 1;
                len    = end - begin + 1;
            }
            end++;
        }
        maxLen = max(maxLen, len);
        return maxLen;
    }
};