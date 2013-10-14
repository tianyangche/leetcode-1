struct Node {
	char signal;
	int index;
	Node(char s, int i) : signal(s), index(i) {}
};

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty())
        	return 0;
        stack<Node> recs;
        int maxLen = 0;
        for (string::size_type i = 0; i < s.length(); i++) {
        	if (s[i] != ')' || recs.empty() || recs.top().signal != '(') {
        		recs.push(Node(s[i], i));
        	} else {
        		recs.pop();
        		int len = recs.empty() ? i+1 : i-recs.top().index;
        		maxLen = max(maxLen, len);
        	}
        }
        return maxLen;
    }
};