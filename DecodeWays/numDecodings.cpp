class Solution {
public:
    int numDecodings(string s) {
        if (s.empty())
            return 0;
        const int len = s.length();
        int result[len];
        memset(result, 0, sizeof(result));
        for (int i = 0; i < s.size(); i++) {
            if (i == 0) {
                if (s[0] == '0')
                    break;
                else
                    result[0] = 1;
            } else {
                int curr = s[i]   - '0';
                int prev = s[i-1] - '0';
                result[i] = result[i-1];
                if (curr == 0) {
                    result[i] = 0;
                }
                if ((prev == 1) || (prev ==2 && curr < 7)) {
                    if (i == 1)
                        result[i] += 1;
                    else 
                        result[i] += result[i-2];
                }
            }
            
        }
        return result[s.size()-1];
    }
};