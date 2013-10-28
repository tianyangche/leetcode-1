class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res;
        if (n < 0)
        	return res;
        searchRange(A, 0, n, n, target, res);
        return res;
    }

    void searchRange(int A[], int begin, int end, int n, int target, vector<int> &res) {
    	if (begin >= end) {
    		res.push_back(-1);
    		res.push_back(-1);
    		return;
    	}
    	int mid = (begin + end - 1) / 2;
    	if (A[mid] == target) {
    		int i = mid;
    		while (i - 1 >= 0 && A[i-1] == target)
    			i--;
    		res.push_back(i);
    		i = mid;
    		while (i + 1 < n && A[i+1] == target)
    			i++;
    		res.push_back(i);
    		return;
    	}
    	if (A[mid] < target) {
    		searchRange(A, mid+1, end, n, target, res);
    	} else {
    		searchRange(A, begin, mid, n, target, res);
    	}

    }
};