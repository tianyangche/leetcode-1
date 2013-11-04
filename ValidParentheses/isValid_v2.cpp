class Solution {
public:
    bool isValid(string s) {
        if (s.empty())
        	return true;
        if (s.length() % 2 == 1)
        	return false;
        stack<char> status;
        for (string::size_type i = 0; i < s.length(); i++) {
        	if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
        		status.push(s[i]);
        		continue;
        	}
        	if (status.empty())
        		return false;
        	if (s[i] == ')') {
        		if (status.top() != '(')
        			return false;
        		status.pop();
        	} else if (s[i] == '}') {
        		if (status.top() != '{')
        			return false;
        		status.pop();
        	} else if (s[i] == ']') {
        		if (status.top() != '[')
        			return false;
        		status.pop();
        	} else
        		return false;
        }
        return status.empty() ? true : false;
    }
};