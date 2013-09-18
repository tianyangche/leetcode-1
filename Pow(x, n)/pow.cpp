class Solution {
public:
    double pow(double x, int n) {
        if (n == 0)
        	return 1;
        if (x == 0)
        	return 0;
        bool nsign = false;
        if (n < 0) {
        	nsign = true;
        	n = -n;
        }
        double result = 1;
        double temp   = x;
        while (n > 0) {
        	if (n & 1)
        		result *= temp;
        	temp *= temp;
        	n >>= 1;
        }
        if (nsign)
        	result = 1.0 / result;
        return result;
    }
};