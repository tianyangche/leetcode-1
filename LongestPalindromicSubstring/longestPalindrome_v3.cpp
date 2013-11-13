class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        if (s.empty())
            return res;
        res.push_back(s[0]);
        for (int i = 0; i < s.length(); i++) {
            string temp;
            findPalindrome(s, i, i+1, temp);
            if (temp.length() > res.length())
                res = temp;
            findPalindrome(s, i-1, i, temp);
            if (temp.length() > res.length())
                res = temp;
            findPalindrome(s, i-1, i+1, temp);
            if (temp.length() > res.length())
                res = temp;
        }
        return res;
    }
    
    void findPalindrome(const string &s, int posi, int posj, string &temp) {
        
        if (posi < 0 || posj >= s.length() || s[posi] != s[posj]) {
            temp = "";
            return;
        }
        
        while (posi >= 0 && posj < s.length()) {
            if (s[posi] != s[posj]) {
                break;
            }
            posi--; posj++;
        }
        temp = s.substr(posi+1, posj-posi-1);
    }
};