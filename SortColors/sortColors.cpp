class Solution {
public:
    void sortColors(int A[], int n) {
        if (n < 1)
            return;
        int i = 0;
        int j = n - 1;
        int k = 0;
        while (k <= j) {
        	if (A[k] == 0) {
        		if (k > i) {
        			swap(A[i], A[k]);
                    i++;		
            	
        		}
        		else {
        			i++;
        			k++;
        		}
        	} else if (A[k] == 2) {
        		swap(A[k], A[j]);
        		j--;
        	} else
        		k++;
        }
    }
};