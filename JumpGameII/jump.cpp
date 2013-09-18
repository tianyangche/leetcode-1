class Solution {
public:
    int jump(int A[], int n) {
        if (n == 0)
            return -1;
        int nstep[n];
        memset(nstep, 0, sizeof(int)*n);
        for (int i = 1; i < n; i++) {
            nstep[i] = INT_MAX;
        }
        for (int i = 0; i < n; i++) {
            int k = i + A[i];
            if (k > n-1)
                k = n-1;
            for (int j = i+1; j <= k; j++) {
                if (nstep[i] + 1 < nstep[j])
                    nstep[j] = nstep[i] + 1;
            }
        }
        return nstep[n-1];
    }
};