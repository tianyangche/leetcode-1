class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int size = m + n;
        if (size < 1)
        	return 0;
        if (size % 2) {
        	return findKth(A, m, B, n, size / 2 + 1);
        } else {
        	return (findKth(A, m, B, n, size / 2) + findKth(A, m, B, n, size / 2 + 1)) / 2.0;
        }
    }

    double findKth(int A[], int m, int B[], int n, int k) {
    	if (m > n) {
    		return findKth(B, n, A, m, k);
    	}
    	if (m == 0)
    		return B[k-1];
    	if (k == 1)
    		return min(A[0], B[0]);
    	int l = min(k/2, m);
    	int r = k - l;
    	if (A[l-1] < B[r-1]) {
    		return findKth(A+l, m-l, B, n, k-l);
    	} else {
    		return findKth(A, m, B+r, n-r, k-r);
    	}
    }
};