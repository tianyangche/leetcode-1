class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        if (num1.empty() || num2.empty())
            return res;
        if (num1 == "0" || num2 == "0")
            return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string::size_type i = 0;
        while (i < num2.length()) {
            compute(res, num1, num2[i], i);
            i++;
        }
        reverse(res.begin(), res.end());
        string::iterator iter = res.begin();
        while (iter != res.end() && *iter == '0')
            iter++;
        return (iter != res.end()) ? string(iter, res.end()) : "0";
    }

    void compute(string &res, string num1, char ch, string::size_type pos2) {
        int temp = 0;
        for (string::size_type i = 0; i < num1.length(); i++) {
            temp += (num1[i] - '0') * (ch - '0');
            while (res.length() <= i + pos2) {
                res += '0';
            }
            temp += res[i+pos2] - '0';
            res[i+pos2] = temp % 10 + '0';
            temp /= 10;
        }
        while (temp != 0) {
            res += temp % 10 + '0';
            temp /= 10;
        }
    }
};