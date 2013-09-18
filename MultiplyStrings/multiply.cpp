class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty())
            return "";
        if (num1.compare("0") == 0 || num2.compare("0") == 0)
            return "0";
        string curr;
        curr.push_back('0');
        for (int i = num1.length()-1; i >= 0; i--) {
        	int divd = 0;
        	for (int j = num2.length()-1; j >= 0; j--) {
        		int temp = (num1[i] - '0') * (num2[j] - '0');
        		size_t pos = num2.length() - j - 1 + num1.length() - i - 1;
        		if (curr.length() <= pos)
        			curr.push_back('0');
        		int sum = curr[pos] - '0' + temp + divd;
        		divd = sum / 10;
        		curr[pos] = sum % 10 + '0';
        	}
        	while (divd > 0) {
        		int temp = divd % 10;
        		curr.push_back(temp+'0');
        		divd = divd / 10;
        	}
        }
        int i = 0;
        int j = curr.length() - 1;
        while (i < j) {
        	char temp = curr[i];
        	curr[i] = curr[j];
        	curr[j] = temp;
        	i++;
        	j--;
        }
        return curr;
    }
};