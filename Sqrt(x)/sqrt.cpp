class Solution {
public:
    int sqrt(int x) {
        if (x <= 0)
            return 0;
        int i = 0;
        int j = x / 2 + 1;
        while (i <= j) {
        	long long mid = (i + j) / 2;
        	long long val = mid * mid;
        	if (val == x)
        		return mid;
        	if (val > x)
        		j = mid - 1;
        	else
        		i = mid + 1;
        }
        return j;
    }
};