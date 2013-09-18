class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if (num.empty())
            return 0;
        unordered_map<int, bool> rec;
        for (vector<int>::iterator iter = num.begin(); iter != num.end(); iter++) {
        	if (rec.empty()) {
        		rec.insert(make_pair(*iter, true));
        	} else {
        		unordered_map<int, bool>::iterator it = rec.find(*iter);
        		if (it == rec.end()) {
        			rec.insert(make_pair(*iter, true));
        		}
        	}
        }
        int res = 0;
        for (vector<int>::iterator iter = num.begin(); iter != num.end(); iter++) {
        	if (rec.empty())
        		break;
        	unordered_map<int, bool>::iterator pos = rec.find(*iter);
        	if (pos != rec.end()) {
        		rec.erase(pos);
        		res = max(res, findConsecutive(rec, (*iter)-1, true)+findConsecutive(rec, (*iter)+1, false)+1);
        	}
        }
        return res;
    }

    int findConsecutive(unordered_map<int, bool> &rec, int n, bool dec) {
    	int len = 0;
    	if (rec.empty())
    		return len;
    	unordered_map<int, bool>::iterator pos = rec.find(n);
    	while (!rec.empty() && pos != rec.end()) {
    		rec.erase(pos);
    		len++;
    		if (dec) {
    			n--;
    		} else {
    			n++;
    		}
            pos = rec.find(n);
    	}
    	return len;
    }
};