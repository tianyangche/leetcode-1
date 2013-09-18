class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res;
        if (n <= 0)
            return res;
    	findRange(A, 0, n, n, target, res);
    	return res;
    }

    void findRange(int A[], int first, int last, int n, int target, vector<int> &res) {
    	if (first > last) {
    		res.push_back(-1);
    		res.push_back(-1);
    		return;
    	}
    	int mid = (first + last) / 2;
    	if (A[mid] == target) {
    		int i = mid;
    		while (i > 0 && A[i-1] == target)
    			i--;
    		res.push_back(i);
    		i = mid;
    		while (i < n-1 && A[i+1] == target)
    			i++;
    		res.push_back(i);
    		return;
    	}
    	if (A[mid] < target)
    		findRange(A, mid+1, last, n, target, res);
    	else
    		findRange(A, first, mid-1, n, target, res);
    }
};