class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.empty() && s2.empty())
        	return true;
        if (s1.empty() || s2.empty())
        	return false;
        if (s1.length() != s2.length())
        	return false;
        if (s1 == s2)
        	return true;
        return isScramble(s1.begin(), s1.end(), s2.begin(), s2.end());
    }

    bool isScramble(string::iterator begin1, string::iterator end1, string::iterator begin2, string::iterator end2) {

    	if (string(begin1, end1) == string(begin2, end2))
    		return true;

    	unordered_map<char, int> recs;

    	for (string::size_type i = 0; begin1 + i != end1; i++) {
    		recs[*(begin1+i)]++;
    		recs[*(begin2+i)]--;
    	}

    	for (auto iter = recs.begin(); iter != recs.end(); iter++) {
    		if (iter->second != 0)
    			return false;
    	}

    	for (string::size_type i = 1; begin1 + i != end1; i++) {
    		if (isScramble(begin1, begin1+i, begin2, begin2+i) && isScramble(begin1+i, end1, begin2+i, end2))
    			return true;
    		if (isScramble(begin1, begin1+i, end2-i, end2) && isScramble(begin1+i, end1, begin2, end2-i))
    			return true;
    	}

    	return false;
    }
};