class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if (n == 0)
        	return;
        if (m == 0) {
        	memcpy(A, B, sizeof(int)*n);
        	return;
        }
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (i >= 0 && j >= 0) {
        	if (A[i] > B[j]) {
        		A[k] = A[i];
        		i--;
        	} else {
        		A[k] = B[j];
        		j--;
        	}
        	k--;
        }
        while (i >= 0) {
        	A[k] = A[i];
        	i--; k--;
        }
        while (j >= 0) {
        	A[k] = B[j];
        	j--; k--;
        }
    }
};