class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 1)
        	return 0;
        bool flag = false;
        int i = 0;
        int j = 1;
        while (j < n) {
        	if (A[i] == A[j]) {
        		if (flag) {
        			j++;
        		} else {
        			swap(A[++i], A[j++]);
        			flag = true;
        		}
        	} else {
        		swap(A[++i], A[j++]);
        		flag = false;
        	}
        }
        return i + 1;
    }
};