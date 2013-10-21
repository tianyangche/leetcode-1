class Solution {
public:
    double pow(double x, int n) {
        if (x == 0)
        	return 0;
        if (n == 0)
        	return 1;
        bool sign = false;
        if (n < 0) {
        	sign = true;
        	n = -n;
        }
        double temp = x;
        double res  = 1;
        while (n > 0) {
        	if (n & 1)
        		res *= temp;
        	temp *= temp;
        	n >>= 1;
        }
        if (sign)
        	res = 1.0 / res;
        return res;
    }
};