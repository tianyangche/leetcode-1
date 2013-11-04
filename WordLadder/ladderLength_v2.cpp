class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end)
        	return 1;
        if (dict.empty())
        	return 0;
        vector<string> startset(1, start);
        unordered_map<string, bool> recs;
        recs[start] = true;
        return ladderLength(startset, end, dict, recs, 1);
    }

    void ladderLength(vector<string> &startset, string end, unordered_set<string> &dict, unordered_map<string, bool> &recs, int nsteps) {
    	
    	vector<string> currset;
    	
    	for (vector<string>::size_type i = 0; i < startset.size(); i++) {
    		string copy = start[i];
    		for (string::size_type pos = 0; pos < copy.size(); pos++) {
    			for (char ch = 'a'; ch <= 'z'; ch++) {
    				if (startset[pos] != ch) {
    					copy[pos] = ch;
    					if (recs.count(copy) > 0) {
    						copy[pos] = startset[i][pos];
    						continue;
    					}
    					if (copy == end)
    						return nsteps + 1;
    					currset.push_back(copy);
    					recs[copy] = true;
    					copy[pos] = startset[i][pos];
 		   			}
    			}
    		}
    	}

    	return currset.empty() ? 0 : ladderLength(currset, end, dict, recs, nsteps+1);
    }
};