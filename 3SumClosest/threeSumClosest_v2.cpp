class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if (num.empty() || num.size() < 3)
        	return 0;
        sort(num.begin(), num.end());
        int ans = 0;
        bool flag = false;
        for (int i = 0; i < num.size() - 2; i++) {
        	int j = i + 1;
        	int k = num.size() - 1;
        	while (j < k) {
        		int sum = num[i] + num[j] + num[k];
        		if (!flag) {
        			ans  = sum;
        			flag = true;
        		} else {
	        		if (abs(sum - target) < abs(ans - target))
						ans = sum;
        		}
        		if (sum > target)
        			k--;
        		else if (sum < target)
        			j++;
        		else
        			return target;
        	}
        }
        return ans;
    }
};