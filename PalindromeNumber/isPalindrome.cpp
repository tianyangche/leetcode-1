class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int divd = 0;
        int temp = 10;
        while (x / temp > 0 && divd < 9) {
            divd++;
            temp = temp * 10;
        }
        for (int i = 0; i < (divd+1)/2; i++) {
        	int m = x / (int)(pow(10, divd-i));
        	if ( i != 0)
        		m = m % 10;
        	int n = x % (int)(pow(10,i+1));
        	if ( i != 0)
        		n = n / (int)(pow(10, i));
        	if (m != n)
        		return false;
        }
        return true;
    }
};