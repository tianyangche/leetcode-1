class Solution {
public:
    string countAndSay(int n) {
        if (n < 1)
            return NULL;
        string result = "1";
        while (n > 1) {
        	ostringstream temp;
        	int i = 0; 	
        	while (i < result.size()) {
        		int j = i;
        		while (j < result.size() && result[j] == result[i])
        			j++;
        		temp << j - i << result[i];
                i = j;
        	}
        	result = temp.str();
        	n--;
        }
        return result;
    }
};