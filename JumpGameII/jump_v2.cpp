class Solution {
public:
    int jump(int A[], int n) {
        if (n < 1)
            return -1;
        int steps = 0;
        int i = 0;
        int j = 0;
        int prev = 0;
        while (i < n) {
        	if (j >= n - 1)
        		break;
        	while (i <= prev) {
        		j = max(j, A[i]+i);
        		i++;
        	}
        	prev = j;
        	steps++;
        }
        return steps;
    }
};