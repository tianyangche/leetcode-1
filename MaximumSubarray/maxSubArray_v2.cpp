class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n < 1)
        	return 0;
        int sum = 0;
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
        	sum += A[i];
        	res = max(res, sum);
        	sum = sum < 0 ? 0 : sum;
        }
        return res;
    }
};