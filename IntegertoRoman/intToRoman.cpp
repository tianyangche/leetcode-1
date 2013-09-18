class Solution {
public:
    string intToRoman(int num) {
        map<int, string> roman;
    	roman[1]    = "I";
		roman[4]    = "IV";
		roman[5]    = "V";
		roman[9]    = "IX";
		roman[10]   = "X";
		roman[40]   = "XL";
		roman[50]   = "L";
		roman[90]   = "XC";
		roman[100]  = "C";
		roman[400]  = "CD";
		roman[500]  = "D";
		roman[900]  = "CM";
		roman[1000] = "M";
		string res;
        for (map<int, string>::reverse_iterator iter = roman.rbegin(); iter != roman.rend(); iter++) {
        	while (num >= iter->first) {
        		res += iter->second;
        		num -= iter->first;
        	}
        }
        return res;
    }
};