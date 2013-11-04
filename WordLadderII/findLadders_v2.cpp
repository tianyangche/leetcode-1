class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > paths;
        if (start == end)
        	return paths;
        if (dict.empty())
        	return paths;
        vector<string> startset(1, start);
        unordered_map<string, vector<string> > recs;
        unordered_map<string, bool> used;
        for (auto iter = dict.begin(); iter != dict.end(); iter++) {
        	used[*iter] = false;
        }
        used[start] = true;
        findLadders(startset, end, dict, used, recs);
        if (recs.count(end) == 0)
            return paths;
        vector<string> onePath(1, end);
        findPath(start, end, recs, onePath, paths);
        return paths;
    }

    void findLadders(vector<string> &startset, string end, unordered_set<string> &dict, unordered_map<string, bool> &used, unordered_map<string, vector<string> > &recs) {
    	bool flag = false;
    	vector<string> newset;
    	for (vector<string>::size_type i = 0; i < startset.size(); i++) {
    		string copy = startset[i];
    		for (string::size_type pos = 0; pos < copy.size(); pos++) {
    			for (char ch = 'a'; ch <= 'z'; ch++) {
    				if (copy[pos] != ch) {
    					copy[pos] =  ch;
    					if (copy == end) {
    						recs[end].push_back(startset[i]);
    						copy[pos] = startset[i][pos];
    						flag = true;
    						continue;
    					}
    					if (dict.count(copy) > 0 && !used[copy]) {
    						if (find(newset.begin(), newset.end(), copy) == newset.end())
    							newset.push_back(copy);
    						recs[copy].push_back(startset[i]);
    					}
    					copy[pos] = startset[i][pos];
    				}
    			}
    		}
    	}
    	for (auto iter = newset.begin(); iter != newset.end(); iter++) {
    		used[*iter] = true;
    	}
    	if (!flag && !newset.empty())
    		findLadders(newset, end, dict, used, recs);
    }

    void findPath(string start, string target, unordered_map<string, vector<string> > &recs, vector<string> &onePath, vector<vector<string> > &paths) {
    	if (start == target) {
    		vector<string> path = onePath;
    		reverse(path.begin(), path.end());
    		paths.push_back(path);
    		return;
    	}
    	const vector<string> &prev = recs[target];
    	for (vector<string>::const_iterator iter = prev.begin(); iter != prev.end(); iter++) {
    		onePath.push_back(*iter);
    		findPath(start, *iter, recs, onePath, paths);
    		onePath.pop_back();
    	}
    }
};