class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > res;
        if (candidates.empty())
            return res;
        unordered_map<int, vector<int> > path;
        vector<bool> used(target+1, false);
        used[0] = true;
        for (int i = 0; i < target; i++) {
        	if (used[i]) {
        		for (vector<int>::iterator iter = candidates.begin(); iter != candidates.end(); iter++) {
        			if ((*iter) + i <= target) {
        				used[(*iter)+i] = true;
        				path[(*iter)+i].push_back(i);
        			}
        		}
        	}
        }
        if (!used[target])
        	return res;
        vector<int> onePath;
        buildPath(target, path, onePath, res);
        return res;
    }

    void buildPath(int target, unordered_map<int, vector<int> > &paths, vector<int> &onePath, vector<vector<int> > &res) {
    	if (target == 0) {
            vector<int> newPath = onePath;
    		sort(newPath.begin(), newPath.end());
            if (find(res.begin(), res.end(), newPath) == res.end())
    		    res.push_back(newPath);
    		return;
    	}
    	const vector<int> &path = paths[target];
    	for (int i = 0; i < path.size(); i++) {
    		onePath.push_back(target-path[i]);
    	    buildPath(path[i], paths, onePath, res);
    		onePath.pop_back();
    	}
    }
};