class Solution {
public:
    bool canJump(int A[], int n) {
        if (n < 1)
            return false;
        bool opt[n];
        memset(opt, 0, sizeof(opt));
        opt[0] = true;
        for (int i = 1; i < n; i++) {
        	int j = i - 1;
        	while (j >= 0) {
        		if (opt[j] && j + A[j] >= i) {
        			opt[i] = true;
        			break;
        		}
                j--;
        	}
        }
        return opt[n-1];
    }
};