class Solution {
public:
    bool search(int A[], int n, int target) {
        if (n < 1)
            return false;
        int i = 0;
        int j = n - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (A[mid] == target)
                return true;
            if (A[mid] > A[i]) {
                if (A[mid] >= target && target >= A[i])
                    j = mid - 1;
                else
                    i = mid + 1;
            } else if (A[mid] < A[i]) {
                if (A[mid] >= target || target >= A[i])
                    j = mid - 1;
                else
                    i = mid + 1;
            } else
                i++;
        }
        return false;
    }
};