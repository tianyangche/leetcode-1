class Solution {
public:
    vector<int> grayCode(int n) {
        int m = 1 << n;
        vector<int> result;
        for (int i = 0; i < m; i++) {
        	result.push_back((i >> 1) ^ i);
        }
        return result;
    }
};