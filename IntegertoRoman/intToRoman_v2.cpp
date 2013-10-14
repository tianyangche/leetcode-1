class Solution {
public:
    string intToRoman(int num) {
        string roman;
        if (num < 1 || num > 3999)
            return roman;
        check(roman, num, 1000,  "M");
        check(roman, num, 900,  "CM");
        check(roman, num, 500,   "D");
        check(roman, num, 400,  "CD");
        check(roman, num, 100,   "C");
        check(roman, num, 90,   "XC");
        check(roman, num, 50,    "L");
        check(roman, num, 40,   "XL");
        check(roman, num, 10,    "X");
        check(roman, num, 9,    "IX");
        check(roman, num, 5,     "V");
        check(roman, num, 4,    "IV");
        check(roman, num, 1,     "I");
        return roman;
    }

    void check(string &roman, int &num, int k, string next) {
    	while (num >= k) {
    		num -= k;
    		roman += next;
    	}
    }
};