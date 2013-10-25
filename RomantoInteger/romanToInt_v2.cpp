class Solution {
public:
    int romanToInt(string s) {
        if (s.empty())
        	return 0;
        int res = 0;
        for (string::iterator iter = s.begin(); iter != s.end(); iter++) {
        	switch (*iter) {
        		case 'M': {
        				res += 1000;
        			}
        			break;
        		case 'D': {
        				res += 500;
        			}
        			break;
        		case 'C': {
        				if (iter + 1 != s.end() && (*(iter+1) == 'M' || *(iter+1) == 'D'))
        					res -= 100;
        				else
        					res += 100;
        			}
        			break;
        		case 'L': {
        				res += 50;
        			}
        			break;
        		case 'X': {
        				if (iter + 1 != s.end() && (*(iter+1) == 'C' || *(iter+1) == 'L'))
        					res -= 10;
        				else
        					res += 10;
        			}
        			break;
        		case 'V': {
        				res += 5;
        			}
        			break;
        		case 'I': {
        				if (iter + 1 != s.end() && (*(iter+1) == 'X' || *(iter+1) == 'V'))
        					res -= 1;
        				else
        			    	res += 1;
        			}
        			break;
        	}
        }
        return res;
    }
};