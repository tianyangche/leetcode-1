class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i = 0;
        while (i < n) {
        	if (A[i] != i + 1 && A[i] > 0 && A[i] < n && A[i] != A[A[i]-1]) {
        		swap(A[i], A[A[i]-1]);
        	} else {
        		i++;
        	}
        }
        int result = 0;
        for (result = 0; result < n; result++) {
        	if (A[result] != result + 1)
        		break;
        }
        return result + 1;
    }
};