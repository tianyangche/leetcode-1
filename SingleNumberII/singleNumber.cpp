class Solution {
public:
    int singleNumber(int A[], int n) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (A[j] >> i & 1)
                    count = (count + 1) % 3;
            }
            res |= count << i;
        }
        return res;
    }
};