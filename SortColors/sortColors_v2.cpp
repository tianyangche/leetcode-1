class Solution {
public:
    void sortColors(int A[], int n) {
        if (n < 1)
        	return;
        int i = -1;
        int k = 0;
        int j = n;
        while (k < j) {
        	if (A[k] == 0) {
        		swap(A[++i], A[k++]);
        	} else if (A[k] == 2) {
        		swap(A[--j], A[k]);
        	} else if (A[k] == 1) {
        		k++;
        	}
        }
    }
};