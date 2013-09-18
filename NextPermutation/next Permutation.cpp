class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.size() < 2)
            return;
        int i = num.size() - 2;
        while (i >= 0 && num[i] >= num[i+1])
        	i--;
        if (i == -1) {
        	reverse(num, 0, num.size()-1);
        } else {
        	int j = num.size() - 1;
        	while (j > i && num[j] <= num[i])
        		j--;
        	swap(num[i], num[j]);
        	reverse(num, i+1, num.size()-1);
        }
    }

    void reverse(vector<int> &num, int i, int j) {
    	while (i < j) {
    		swap(num[i], num[j]);
    		i++;
    		j--;
    	}
    }
};