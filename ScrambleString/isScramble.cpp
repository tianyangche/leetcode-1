class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.empty() || s2.empty())
            return false;
        if (s1.length() != s2.length())
        	return false;
        if (s1 == s2)
            return true;
        map<char, int> occurs;
        for (int i = 0; i < s1.length(); i++) {
        	occurs[s1[i]]++;
        	occurs[s2[i]]--;
        }
        for (map<char, int>::iterator iter = occurs.begin(); iter != occurs.end(); iter++)
        	if (iter->second != 0)
        		return false;
        for (int i = 1; i < s1.length(); i++) {
        	string sub1_1 = s1.substr(0, i);
        	string sub1_2 = s1.substr(i);

        	string sub2_1 = s2.substr(0, i);
        	string sub2_2 = s2.substr(i);

        	if (isScramble(sub1_1, sub2_1) && isScramble(sub1_2, sub2_2))
        		return true;

        	sub2_1 = s2.substr(s2.length() - i);
        	sub2_2 = s2.substr(0, s2.length() - i);

        	if (isScramble(sub1_1, sub2_1) && isScramble(sub1_2, sub2_2))
				return true;
        }
        return false;
    }
};