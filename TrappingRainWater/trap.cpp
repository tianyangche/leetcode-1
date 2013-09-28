class Solution {
public:
    int trap(int A[], int n) {
        if (n == 0)
            return 0;
        int left[n];
        left[0] = 0;
        for (int i = 1; i < n; i++) {
        	left[i] = max(left[i-1], A[i-1]);
        }
        int sum = 0;
        int right = 0;
        for (int i = n-2; i >= 0; i--) {
        	if (right < A[i+1])
        		right = A[i+1];
        	int temp = min(left[i], right);
        	if (temp > A[i])
        		sum += temp - A[i];
        }
        return sum;
    }
};