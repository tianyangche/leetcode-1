class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (n < 1)
        	return 0;
        int i = 0;
        int j = n - 1;
        while (i <= j) {
        	if (A[i] == elem) {
        		swap(A[i], A[j--]);
        	} else {
        		i++;
        	}
        }
        return i;
    }
};