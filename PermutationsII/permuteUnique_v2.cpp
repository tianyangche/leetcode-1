class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        do {
            res.push_back(num);
            nextPermute(num);
        } while (!equal(res[0].begin(), res[0].end(), num.begin()));
        return res;
    }

    void nextPermute(vector<int> &num) {
        int i = num.size()-2;
        while (i >= 0 && num[i] >= num[i+1])
            i--;
        if (i < 0) {
            reverse(num.begin(), num.end());
            return;
        }
        int j = num.size()-1;
        while (i < j && num[i] >= num[j])
            j--;
        swap(num[i], num[j]);
        reverse(num.begin()+i+1, num.end());
    }

};