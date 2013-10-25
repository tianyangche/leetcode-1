class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.empty())
        	return res;
        geneIP(s, 0, 0, "", res);
        return res;
    }

    void geneIP(string s, int pos, int segments, string oneIP, vector<string> &res) {
    	if (pos == s.length() && segments == 4) {
    	    oneIP.pop_back();
    		res.push_back(oneIP);
    		return;
    	}
    	if (segments == 4)
    		return;
    	if (pos > s.length())
    		return;
    	string temp(1, s[pos]);
    	geneIP(s, pos + 1, segments + 1, oneIP + temp + '.', res);
    	if (s[pos] == '0')
    		return;
    	if (pos + 1 < s.length()) {
    		temp += s[pos+1];
    		geneIP(s, pos + 2, segments + 1, oneIP + temp + '.', res);
    	}
    	if (pos + 2 < s.length()) {
    		temp += s[pos+2];
    		int val = stoi(temp);
    		if (val < 0 || val > 255)
    		    return;
            geneIP(s, pos + 3, segments + 1, oneIP + temp + '.', res);
    	}
    }
};