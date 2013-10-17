class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.empty() || num.size() < 2)
        	return;
        for (int i = num.size() - 2; i >= 0; i--) {
        	if (num[i] < num[i+1]) {
        		int j = num.size() - 1;
        		while (i < j) {
        			if (num[i] < num[j]) {
        				swap(num[i], num[j]);
        				reverse(num.begin()+i+1, num.end());
        				return;
        			}
        			j--;
        		}
        	}
        }
        reverse(num.begin(), num.end());
        return;
    }
};