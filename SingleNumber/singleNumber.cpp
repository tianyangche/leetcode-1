/*
(A XOR B) XOR C = A XOR (B XOR C).
*/
class Solution {
public:
    int singleNumber(int A[], int n) {
        if (n < 0)
        	return -1;
        int res = 0;
        for (int i = 0; i < n; i++)
        	res ^= A[i];
        return res;
    }
};