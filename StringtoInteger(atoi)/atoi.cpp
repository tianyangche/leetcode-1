class Solution {
public:
    int atoi(const char *str) {
        if (str == NULL)
            return 0;
        bool assigned = false;
        while (*str == ' ' || *str == '\t')
        	str++;
        if (*str == '+')
            str++;
        if (*str == '-') {
        	assigned = true;
        	str++;
        }
        long long res = 0;
        while (*str != '\0') {
            if (*str > '9' || *str < '0')
                break;
        	int temp = *str - '0';
        	res = 10*res + temp;
        	str++;
        }
        if (assigned)
        	res = -res;
        if (res > INT_MAX)
            return INT_MAX;
        if (res < INT_MIN)
            return INT_MIN;
        return res;
    }
};