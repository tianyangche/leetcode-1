class Solution {
public:
    bool isValid(string s) {
        if (s.empty())
        	return false;
        stack<char> state;
        for (string::iterator iter = s.begin(); iter != s.end(); iter++) {
        	if (*iter == '(' || *iter == '{' || *iter == '[')
        		state.push(*iter);
        	else {
        		if (state.empty())
        			return false;
        		char temp = state.top();
        		if (temp == '(' && *iter == ')')
        			state.pop();
        		else if (temp == '[' && *iter == ']')
        			state.pop();
        		else if (temp == '{' && *iter == '}')
        			state.pop();
        		else
        			return false;
        	}
        }
        if (state.empty())
        	return true;
        else
        	return false;
    }
};