class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        if (a.empty() && b.empty())
            return ans;
        if (a.empty())
            return b;
        if (b.empty())
            return a;
        int posa = a.length() - 1;
        int posb = b.length() - 1;
        int temp  = 0;
        while (posa >= 0 && posb >= 0) {
            temp += a[posa] - '0' + b[posb] - '0';
            ans.push_back(temp % 2 + '0');
            temp /= 2;
            posa--;
            posb--;
        }
        compString(a, posa, ans, temp);
        compString(b, posb, ans, temp);
        while (temp > 0) {
            ans.push_back(temp % 2 + '0');
            temp /= 2;
        }
        return string(ans.rbegin(), ans.rend());
    }

    void compString(const string &st, int pos, string &ans, int &temp) {
        while (pos >= 0) {
            temp += st[pos] - '0';
            ans.push_back(temp % 2 + '0');
            temp /= 2;
            pos--;
        }
    }
};