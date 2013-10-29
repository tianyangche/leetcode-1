class Solution {
public:
    int trap(int A[], int n) {
        if (n < 1)
        	return 0;
        
        vector<int> leftMostHeight(n, -1);
        vector<int> rightMostHeight(n, -1);

        for (int i = 1; i < n - 1; i++) {
        	leftMostHeight[i] = max(leftMostHeight[i-1], A[i-1]);
        }
        for (int i = n - 2; i > 0; i--) {
        	rightMostHeight[i] = max(rightMostHeight[i+1], A[i+1]);
        }

        int res = 0;
        for (int i = 1; i < n - 1; i++) {
        	int minHeight = min(leftMostHeight[i], rightMostHeight[i]);
        	if (minHeight > A[i]) {
        		res += minHeight - A[i];
        	}
        }

        return res;
    }
};