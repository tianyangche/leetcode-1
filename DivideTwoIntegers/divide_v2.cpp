class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0 || divisor == 0)
            return 0;
        if (divisor == 1)
            return dividend;
        if (divisor == -1)
        	return -dividend;
        bool flag = false;
        long long dvd = (long long)dividend;
        long long dvr = (long long)divisor;
        flag = dvd < 0 ? !flag : flag;
        flag = dvr < 0 ? !flag : flag;
        dvd	 = dvd < 0 ? -dvd  : dvd;
        dvr	 = dvr < 0 ? -dvr  : dvr;
        long long inc[50];
        int i = 0;
        long long temp = dvr;
        while (dvd >= temp) {
        	inc[i] = temp;
        	temp = temp << 1;
        	i++;
        }
        i--;
        int res = 0;
        while (dvd > 0 && i >= 0) {
        	if (dvd >= inc[i]) {
        		dvd -= inc[i];
        		res += 1 << i;
        	}
        	i--;
        }
        res = flag ? -res : res;
        return res;
    }
};