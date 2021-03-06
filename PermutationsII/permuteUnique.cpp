class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        if (num.empty())
            return result;
        sort(num.begin(), num.end());
        vector<bool> used(num.size(), false);
        vector<int> comb;
        findPermuteUnique(num, used, comb, result, 0, num.size());
        return result;
    }

    void findPermuteUnique(vector<int> num, vector<bool> &used, vector<int> &comb, vector<vector<int> > &result, int curr, int size) {
        if (curr == size) {
            
            result.push_back(comb);
        } else {
            int flag = -1;
            bool find = false;
            for (int i = 0; i < size; i++) {
                if (!used[i]) 
                    if (!find || (find && flag != num[i])) {
                        used[i] = true;
                        comb.push_back(num[i]);
                        findPermuteUnique(num, used, comb, result, curr+1, size);
                        comb.pop_back();
                        used[i] = false;
                        find = true;
                        flag = num[i];
                    }
            }       
        }
    }
};