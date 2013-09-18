class Solution {
public:
    int minDistance(string word1, string word2) {
        const int len1 = word1.length();
        const int len2 = word2.length();
        int dist[len1+1][len2+1];
        memset(dist, 0, sizeof(dist));
        for (int i = 0; i <= len1; i++) {
            dist[i][0] = i;
        }
        for (int i = 0; i <= len2; i++) {
        	dist[0][i] = i;
        }
        for (int i = 0; i < len1; i++) {
        	for (int j = 0; j < len2; j++) {
        		dist[i+1][j+1] = min(dist[i][j+1], dist[i+1][j]) + 1;
        		if (word1[i] == word2[j]) {
        			dist[i+1][j+1] = min(dist[i+1][j+1], dist[i][j]);
 				} else {
     				dist[i+1][j+1] = min(dist[i+1][j+1], dist[i][j] + 1);
	 			}
        	}
        }
        return dist[len1][len2];
    }

    int min(int x, int y) {
    	if (x < y)
    		return x;
    	else
    		return y;
    }
};