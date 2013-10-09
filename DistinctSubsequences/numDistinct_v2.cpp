class Solution {
public:
    int numDistinct(string S, string T) {
        if (S.empty())
            return 0;
        int ns = S.length();
        int nt = T.length();
        int opt[nt+1][ns+1];
        opt[0][0] = 1;
        for (int i = 1; i <= nt; i++) {
        	opt[i][0] = 0;
        }
        for (int i = 1; i <= ns; i++) {
        	opt[0][i] = 1;
        }
        for (int i = 0; i < nt; i++) {
        	for (int j = 0; j < ns; j++) {
        		if (T[i] == S[j]) {
        			opt[i+1][j+1] = opt[i][j] + opt[i+1][j];
        		} else {
        			opt[i+1][j+1] = opt[i+1][j];
        		}
        	}
        }
        return opt[nt][ns];
    }
};