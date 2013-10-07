class Solution {
public:
    int candy(vector<int> &ratings) {
        if (ratings.empty())
        	return 0;
        int n = ratings.size();
        vector<int> nums(n, 0);
        for (int i = 1; i < n; i++) {
        	if (ratings[i] > ratings[i-1]) {
        		if (nums[i-1] == 0)
        			nums[i-1] = 1;
        		nums[i] = nums[i-1] + 1;
        	}
        }
        if (nums[n-1] == 0)
            nums[n-1]++;
        int res = nums[n-1];
        for (int i = n - 2; i >= 0; i--) {
        	if (nums[i] != 0) {
        		if (ratings[i] > ratings[i+1]) {
        			if (nums[i] <= nums[i+1])
        				nums[i] = nums[i+1] + 1;
        		}
        		res += nums[i];
        	} else if (ratings[i] > ratings[i+1]) {
        		nums[i] = nums[i+1] + 1;
        		res += nums[i];
        	} else {
        		nums[i] = 1;
        		res += nums[i];
        	}
        }
        return res;
    }
};