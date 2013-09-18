class Solution {
public:
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > result;
		vector<int> t;
		findCombine(1, 0, n, k, result, t);
		return result;
	}
	
	void findCombine(int a, int len, int n, int k, vector<vector<int> > &result, vector<int> &t) {
	
		if (len == k) {
			result.push_back(t);
		} else {
			for (int i = a; i <= n; i++) {
				t.push_back(i);
				findCombine(i+1, len+1, n, k, result, t);
				t.pop_back();
			}
		}
	}
}