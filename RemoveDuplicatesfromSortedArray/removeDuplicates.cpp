class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 2)
        	return n;
        int pos = 0;
        for (int i = 1; i < n; i++) {
        	if (A[i] > A[pos])
        		swap(A[++pos], A[i]);
        }
        return pos+1;
    }
};