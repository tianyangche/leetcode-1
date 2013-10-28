class Solution {
public:
    int atoi(const char *str) {
        if (str == NULL)
        	return 0;
        while (*str != '\0' && (*str == ' ' || *str == '\t'))
        	str++;
        bool assigned = false;
        if (*str == '+' || *str == '-') {
        	if (*str == '-')
        		assigned = true;
        	str++;
        }
        long long val = 0;
        while (*str != '\0') {
        	if (*str > '9' || *str < '0')
        		break;
       		val = 10 * val + *str - '0';
       		str++;
        }
        if (assigned)
        	val = -val;
        if (val > INT_MAX)
        	return INT_MAX;
        if (val < INT_MIN)
        	return INT_MIN;
        return (int) val;
    }
};