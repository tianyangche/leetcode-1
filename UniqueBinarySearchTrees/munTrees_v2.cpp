class Solution {
public:
    int numTrees(int n) {
        if (n <= 2)
        	return n;
        return numTrees(1, n);
    }

    int numTrees(int begin, int end) {
    	if (begin >= end)
    		return 1;
    	int sum = 0;
    	for (int i = begin; i <= end; i++) {
    		sum += numTrees(begin, i-1) * numTrees(i+1, end);
    	}
    	return sum;
    }
};