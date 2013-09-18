class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n == 0)
            return 0;
        int res = A[0];
        int tmp = 0;
        for (size_t i = 0; i < n; i++) {
            tmp += A[i];
            res = max(res, tmp);
            if (tmp < 0) {
                tmp = 0;
            }
        }
        return res;
    }
};