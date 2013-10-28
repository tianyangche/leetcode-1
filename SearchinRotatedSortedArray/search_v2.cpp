class Solution {
public:
    int search(int A[], int n, int target) {
        if (n < 1)
        	return -1;
        return search(A, 0, n-1, target);
    }

    int search(int A[], int begin, int end, int target) {
    	if (begin > end)
    		return -1;
    	int mid = (begin + end) / 2;
    	if (A[mid] == target)
    		return mid;
    	if (begin == end)
    		return -1;
    	if (A[mid] >= A[begin]) {
    		if (A[mid] > target && target >= A[begin])
    			return search(A, begin, mid-1, target);
    		else
    			return search(A, mid+1, end, target);
    	} else {
    		if (A[mid] > target || target >= A[begin])
    			return search(A, begin, mid-1, target);
    		else
    			return search(A, mid+1, end, target);
    	}
    }
};