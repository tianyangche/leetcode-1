class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if (digits.empty())
            return digits;
        vector<int> res;
        int k = 1;
        for (vector<int>::reverse_iterator iter = digits.rbegin(); iter != digits.rend(); iter++) {
        	int val = *iter + k;
        	k = val / 10;
        	res.push_back(val % 10);
        }
        while (k > 0) {
        	res.push_back(k % 10);
        	k /= 10;
        }
        int i = 0;
        int j = res.size() - 1;
        while (i < j) {
        	int temp = res[i];
        	res[i] = res[j];
        	res[j] = temp;
            i++;
            j--;
        }
        return res;
    }
}; 