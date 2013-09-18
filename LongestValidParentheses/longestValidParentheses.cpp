struct Node {
    char ch;
    int  idx;
    Node(char c, int pos) : ch(c), idx(pos) {}
};

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty())
            return 0;
        stack<Node> rec;
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                rec.push(Node(s[i], i));
            } else {
                if (!rec.empty()) {
                    Node node = rec.top();
                    if (node.ch == '(') {
                        rec.pop();
                        if (!rec.empty()) {
                            res = max(res, i-rec.top().idx);
                        } else {
                            res = max(res, i+1);
                        }
                    } else {
                        rec.push(Node(s[i], i));
                    }
                } else {
                    rec.push(Node(s[i], i));
                }
            }
        }
        return res;
    }
};