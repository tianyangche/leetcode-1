class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.empty())
            return res;
        string one;
        genIP(0, 4, 0, one, s, res);
    	return res;
    }

    void genIP(int curr, int final, int pos, string ip, string s, vector<string> &res) {
    	if (curr == final) {
    		if (find(res.begin(), res.end(), ip) == res.end())
    			res.push_back(ip);
    	} else {
    		string temp;
    		for (int i = 0; i < 3; i++) {
    			if (pos+i >= s.length())
    				break;
 				temp += s[pos+i];
 				if (curr+1 == final && pos+i+1 < s.length())
 					continue;
 				if (temp.length() > 1 && temp[0] == '0')
 					break;
 				int val = stoi(temp);
 				if (val < 0 || val > 255)
 					continue;
 				string st;
 				if (curr+1 == final)
 					st = ip + temp;
 				else
 					st = ip + temp + ".";
 				genIP(curr+1, final, pos+i+1, st, s, res);

    		}
    	}
    }
};