class Solution {
public:
    int romanToInt(string s) {
        if (s.empty())
    		return 0;
        map<char, int> roman;
        roman['M'] = 1000;
        roman['D'] = 500;
        roman['C'] = 100;
        roman['L'] = 50;
        roman['X'] = 10;
        roman['V'] = 5;
        roman['I'] = 1;
        int i = 0;
        int res = 0;
        while (i < s.length()-1) {
        	if (roman[s[i]] < roman[s[i+1]])
        		res -= roman[s[i]];
        	else
        		res += roman[s[i]];
        	i++;
        }
        res += roman[s[i]];
        return res;
    }
};