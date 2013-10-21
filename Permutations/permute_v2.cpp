class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        permute(0, num, res);
        return res;
    }

    void permute(int pos, vector<int> num, vector<vector<int> > &res) {
    	if (pos == num.size()) {
    		res.push_back(num);
    		return;
    	}
    	for (int i = pos; i < num.size(); i++) {
    		swap(num[i], num[pos]);
    		permute(pos+1, num, res);
    		swap(num[i], num[pos]);
    	}
    }
};