class Solution {
public:
    int reverse(int x) {
        bool flag = false;
        if (x < 0) {
        	flag = true;
        	x = -x;
        }
        int xx  = 0;
        while (x > 0) {
        	xx = 10 * xx + x % 10;
        	x /= 10;
        }
        return flag ? -xx : xx;
    }
};