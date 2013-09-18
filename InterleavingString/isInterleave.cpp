class Solution {
	public:
    	bool isInterleave(string s1, string s2, string s3) {

        	if (s3.length() != s1.length() + s2.length())
    			return false;
    		
        	bool opt[s1.length()+1][s2.length()+1];
        	memset(opt, 0, sizeof(opt));
           	opt[0][0] = true;
        
        	for (int i = 0; i < s1.length(); i++) {
        		if (s1[i] == s3[i]) {
        			opt[i+1][0] = true;
        		} else
        			break;
        	}

        	for (int i = 0; i < s2.length(); i++) {
        		if (s2[i] == s3[i]) {
        			opt[0][i+1] = true;
        		} else
        			break;
        	}

        	for (int i = 1; i <= s1.length(); i++) {
        		for (int j = 1; j <= s2.length(); j++) {
        			if (s1[i-1] == s3[i+j-1]) {
        				opt[i][j] = opt[i][j] || opt[i-1][j];
	        		}
    	    		if (s2[j-1] == s3[i+j-1]) {
        				opt[i][j] = opt[i][j] || opt[i][j-1];
        			}
        		}
        	}

        	return opt[s1.length()][s2.length()];
    	}
};