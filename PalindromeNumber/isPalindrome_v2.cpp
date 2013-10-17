class Solution {
public:
    bool isPalindrome(int x) {
    	if (x < 0)
    	    return false;
    	x = x < 0 ? -x : x;
        int x1 = x, x2 = x;
    	int div1 = 1, div2 = 10;
    	while (x1 / div1 >= 10) {
    		div1 *= 10;
    	}
    	while (x1 > 0 && x2 > 0) {
    		int dvd1 = x1 / div1;
    		int dvd2 = x2 % div2;
    		if (dvd1 != dvd2)
    			return false;
    		x1 %= div1;
    		x2 /= div2;
    		div1 /= 10;
    	}
    	return true;
    }
};