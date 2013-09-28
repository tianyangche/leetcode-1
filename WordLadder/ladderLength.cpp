class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (dict.empty())
            return false;
        unordered_map<string, bool> recs;
        for (unordered_set<string>::iterator iter = dict.begin(); iter != dict.end(); iter++)
            recs[*iter] = false;
        int nsteps = 1;
        vector<string> prev;
        prev.push_back(start);
        while (!prev.empty()) {
            vector<string> curr;
        	for (vector<string>::iterator iter = prev.begin(); iter != prev.end(); iter++) {
        		for (int i = 0; i < (*iter).size(); i++) {
        			for (int k = 'a'; k <'z'; k++) {
        				if ((*iter)[i] == k)
        					continue;
        				char temp = (*iter)[i];
        				(*iter)[i] = k;
        				if ((*iter).compare(end) == 0)
        					return nsteps+1;
        				if (dict.count(*iter) > 0 && !recs[*iter]) {
        					curr.push_back(*iter);
        					recs[*iter] = true;
        				}
        				(*iter)[i] = temp;
        			}
        		}
        	}
        	prev = curr;
        	nsteps++;
        }
        return 0;
    }

    bool transfer(string st1, string st2) {
    	int dif = 0;
    	for (int i = 0; i < st1.length(); i++) {
    		if (st1[i] != st2[i]) {
    			dif++;
    			if (dif > 1)
    				return false;
    		}
    	}
    	return dif;
    }
};