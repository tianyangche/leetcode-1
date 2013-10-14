class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if (num.empty())
        	return 0;
        unordered_map<int, bool> recs;
        for (vector<int>::iterator iter = num.begin(); iter != num.end(); iter++) {
        	recs[*iter] = true;
        }
        int longestLen = 0;
        for (unordered_map<int, bool>::iterator iter = recs.begin(); iter != recs.end(); iter++) {
        	if (iter->second) {
        		iter->second = false;
        		int len = checkConsecutive(recs, (iter->first)-1, true) + checkConsecutive(recs, (iter->first)+1, false) + 1;
        		longestLen = max(longestLen, len);
        	}
        }
        return longestLen;
    }

    int checkConsecutive(unordered_map<int, bool> &recs, int num, bool left) {
    	int len = 0;
    	while (recs.count(num) > 0 && recs[num]) {
    		recs[num] = false;
    		len++;
    		num = left ? num - 1 : num + 1;
    	}
    	return len;
    }
};