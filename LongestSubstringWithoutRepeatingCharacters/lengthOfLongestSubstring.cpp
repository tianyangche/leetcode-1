class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        unordered_map<char, int> rec;
        vector<int> repetition;
        int i = 0;
        for (string::iterator iter = s.begin(); iter != s.end(); iter++) {
            unordered_map<char, int>::iterator pos = rec.find(*iter);
            if (pos == rec.end()) {
        		rec.insert(make_pair(*iter, i));
        		repetition.push_back(-1);
        	} else {
        		repetition.push_back(pos->second);
        		pos->second = i;
        	}
        	i++;
        }
        int pos = 0;
        int tmp = 0;
        int res = 0;
        i = 0;
        while (i < repetition.size()) {
        	if (repetition[i] < pos) {
        		tmp++;
        		i++;
        	} else {
        		i = repetition[i] + 1;
        		pos = i;
        		res = max(res, tmp);
        		tmp = 0;

        	}
        }
        res = max(res, tmp);
        return res;
    }
};