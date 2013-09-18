class Solution {
public:
    bool canJump(int A[], int n) {
        if (n == 0)
            return false;
        int j = 0;
        int i = 0;
        while (i <= j) {
        	if (i + A[i] < n-1) {
        		if (i + A[i] > j)
        			j = i + A[i];
        	} else
        		return true;
        	i++;
        }
        return false;
    }
};