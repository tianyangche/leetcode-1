class Solution {
public:
    int numDistinct(string S, string T) {
        int sizeS = S.size();
        int sizeT = T.size();
        int numDist[sizeT+1][sizeS+1];
        memset(numDist, 0, sizeof(numDist));
        numDist[0][0] = 1;
        for (int i = 1; i <= sizeT; i++) {
        	numDist[i][0] = 0;
        }
        for (int i = 1; i <= sizeS; i++) {
        	numDist[0][i] = 1;
        }
        for (int i = 0; i < sizeT; i++) {
        	for (int j = 0; j < sizeS; j++) {
        		if (T[i] == S[j]) {
        			numDist[i+1][j+1] = numDist[i][j] + numDist[i+1][j];
        		} else {
        			numDist[i+1][j+1] = numDist[i+1][j];
        		}
        	}
        }
        return numDist[sizeT][sizeS];
    }
};