class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > res;
        if (num.empty() || num.size() < 3)
        	return res;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size() - 2; i++) {
        	int j = i + 1;
        	int k = num.size() - 1;
        	while (j < k) {
        		int sum = num[i] + num[k] + num[j];
        		if (sum > 0)
        			k--;
        		else if (sum < 0)
        			j++;
        		else {
        			vector<int> new_ans;
        			new_ans.push_back(num[i]);
        			new_ans.push_back(num[j]);
        			new_ans.push_back(num[k]);
        			if (find(res.begin(), res.end(), new_ans) == res.end())
        				res.push_back(new_ans);
        			j++;
        			k--;
        		}
        	}
        }
        return res;
	}
};