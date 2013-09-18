class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int result = 0;
        int i = 0;
        int j = n-1;
        while (i <= j) {
            if (A[i] != elem) {
                i++;
            } else {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                j--;
            }
        }
        return j+1;
    }
};