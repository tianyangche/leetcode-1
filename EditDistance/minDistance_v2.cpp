class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty() && word2.empty())
            return 0;
        int len1 = word1.length();
        int len2 = word2.length();
        int opt[len1+1][len2+1];
        opt[0][0] = 0;
        for (int i = 1; i <= len1; i++) {
        	opt[i][0] = opt[i-1][0] + 1;
        }
        for (int i = 1; i <= len2; i++) {
        	opt[0][i] = opt[0][i-1] + 1;
        }
        for (int i = 0; i < len1; i++) {
        	for (int j = 0; j < len2; j++) {
        		opt[i+1][j+1] = min(opt[i][j+1], opt[i+1][j]) + 1;
        		if (word1[i] == word2[j])
        			opt[i+1][j+1] = min(opt[i+1][j+1], opt[i][j]);
                else
                    opt[i+1][j+1] = min(opt[i+1][j+1], opt[i][j]+1);
        	}
        }
        return opt[len1][len2];
    }
};