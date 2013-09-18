class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (n < 1)
            return -1;
        int i = 0;
        int j = n -1;
        while (i <= j) {
        	int mid = (i + j) / 2;
        	if (A[mid] == target)
        		return mid;
        	if (A[mid] > target)
        		j = mid - 1;
        	else
        		i = mid + 1;
        }
        return i;
    }
};