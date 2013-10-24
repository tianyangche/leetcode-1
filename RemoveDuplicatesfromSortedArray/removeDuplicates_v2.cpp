class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 1)
        	return 0;
        int i = 0;
        int j = 0;
        while (j < n) {
        	if (A[i] == A[j]) {
        		j++;
        	} else {
        		swap(A[++i], A[j++]);
        	}
        }
        return i + 1;
    }
};