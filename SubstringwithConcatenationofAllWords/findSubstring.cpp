class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if (S.empty() || L.empty())
            return res;
        map<string, int> matcher;
        map<string, int> matchee;
        for (vector<string>::iterator iter = L.begin(); iter != L.end(); iter++) {
            matcher[*iter]++;
        }
        int n = L.size();
        int m = L[0].size();
        for (int i = 0; i < S.size()-m*n+1; i++) {
            matchee.clear();
            int j = 0;
            for (j = 0; j < n; j++) {
                string substring = S.substr(i+j*m, m);
                if (matcher.find(substring) == matcher.end())
                    break;
                matchee[substring]++;
                if (matchee[substring] > matcher[substring])
                    break;
            }
            if (j == n)
                res.push_back(i);
        }
        return res;
    }
};