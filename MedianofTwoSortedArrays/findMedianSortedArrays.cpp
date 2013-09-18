class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if (m == 0) {
        	return findMedian(B, n);
        }
        if (n == 0) {
        	return findMedian(A, m);
        }
        bool flag = (m+n)%2 ? true : false;
        int k = (m + n) / 2;
        double res = findkth(A, 0, m, B, 0, n, k);
        if (!flag) {
        	double tmp = findkth(A, 0, m, B, 0, n, k+1);
        	res = (res + tmp) / 2;
        }
        return res;
    }

    double findMedian(int A[], int n) {
    	if (n % 2 == 0) {
    		return (A[n/2]+A[n/2-1])/2;
    	} else {
    		return A[n/2];
    	}
    }

    double findkth(int A[], int s1, int e1, int B[], int s2, int e2, int k) {
    	if (e1-s1 == 0) {
    		return findOneArray(B, s2, e2, k);
    	} else if (e2-s2 == 0) {
    		return findOneArray(A, s1, e1, k);
    	} else {
    		if (k == 1) {
    			if 
    		}
    	}
    }

};