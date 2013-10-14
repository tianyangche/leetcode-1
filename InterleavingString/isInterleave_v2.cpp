class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if (len3 != len1 + len2)
        	return false;
        bool opt[len1+1][len2+1];
        memset(opt, 0, sizeof(opt));
        opt[0][0] = true;
        for (int i = 0; i < len1; i++) {
        	if (s1[i] == s3[i]) {
        		opt[i+1][0] = true;
        	} else
                break;
        }
        for (int i = 0; i < len2; i++) {
        	if (s2[i] == s3[i]) {
        		opt[0][i+1] = true;
        	} else
                break;
        }
        for (int i = 0; i < len1; i++) {
        	for (int j = 0; j < len2; j++) {
        		if (s1[i] == s3[i+j+1])
        			opt[i+1][j+1] = opt[i+1][j+1] || opt[i][j+1];
        		if (s2[j] == s3[i+j+1])
        			opt[i+1][j+1] = opt[i+1][j+1] || opt[i+1][j];
        	}
        }
        return opt[len1][len2];
    }
};