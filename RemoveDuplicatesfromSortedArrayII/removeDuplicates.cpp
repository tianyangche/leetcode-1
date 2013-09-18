class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 2)
            return n;
        bool found = false;
        int pos   = 0;
        for (int i = 1; i < n; i++) {
            if (A[i] == A[pos]) {
        		if (!found) {
        			swap(A[++pos], A[i]);
        			found = true;
        		}
        	}
        	else {
        		swap(A[++pos], A[i]);
        		found = false;
        	}
        }
        return pos+1;
    }
};