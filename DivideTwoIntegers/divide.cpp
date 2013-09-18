class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0 || divisor == 0)
        	return 0;
        if (divisor == 1)
        	return dividend;
        if (divisor == -1)
        	return (0 - dividend);
        int result = 0;
        bool flag = false;
        if (dividend < 0) {
        	flag = !flag;
        	dividend = 0 - dividend;
        }
        if (divisor < 0) {
        	flag = !flag;
        	divisor = 0 - divisor;
        }
        while (dividend > 0) {
			dividend -= divisor;
			result++;
        }
        if (flag)
        	result = 0 - result;
        return result;
    }
};