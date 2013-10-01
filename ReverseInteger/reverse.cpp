class Solution {
public:
    int reverse(int x) {
        bool flag = false;
        if (x < 0) {
            flag = true;
        	x = -x;
        }
        int res = 0;
        int i = 0;
        while (x > 0) {
        	int temp = x % 10;
        	res = res*10 + temp;
        	x /= 10;
        }
        if (!flag)
            return res;
        else
            return -res;
    }
};