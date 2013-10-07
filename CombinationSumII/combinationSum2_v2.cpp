class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > res;
        if (num.empty())
            return res;
        unordered_map<int, vector<int> > recs;
        vector<bool> used(target+1, false);
        used[0] = true;
        for (int i = 0; i < num.size(); i++) {
            for (int sum = target; sum >= 0; sum--) {
        		if (used[sum] && sum + num[i] <= target) {
        			used[sum+num[i]] = true;
        			recs[sum+num[i]].push_back(i);
        		}
        	}
        }
        if (!used[target])
        	return res;
        vector<int> onePath;
        buildPath(target, num, recs, onePath, res);
        return res;
    }

    void buildPath(int target, vector<int> &num, unordered_map<int, vector<int> > &recs, vector<int> &onePath, vector<vector<int> > &res) {
    	if (target == 0) {
    		vector<int> newPath;
    		for (int i = 0; i < onePath.size(); i++)
    			newPath.push_back(num[onePath[i]]);
    		sort(newPath.begin(), newPath.end());
    		if (find(res.begin(), res.end(), newPath) == res.end())
    			res.push_back(newPath);
    		return;
    	}
    	const vector<int> &paths = recs[target];
    	for (int i = 0; i < paths.size(); i++) {
    		if (find(onePath.begin(), onePath.end(), paths[i]) == onePath.end()) {
    			onePath.push_back(paths[i]);
    			buildPath(target-num[paths[i]], num, recs, onePath, res);
    			onePath.pop_back();
    		}
    	}
    }
};