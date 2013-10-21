class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if (digits.empty())
        	return digits;
        int temp = 1;
        int i = digits.size() - 1;
        while (i >= 0) {
        	temp += digits[i];
        	digits[i] = temp % 10;
        	temp /= 10;
        	i--;
        }
        while (temp != 0) {
        	digits.insert(digits.begin(), temp % 10);
        	temp /= 10;
    	}
    	return digits;
    }
};