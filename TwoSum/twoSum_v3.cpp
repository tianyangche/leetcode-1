class Solution {
public:
    vector<int> twoSum(vector<int> &vals, int target) {
        
        if (vals.empty())
            return vals;
        vector<int> res;
        unordered_map<int, vector<int> > pos;
        for (int i = 0; i < vals.size(); i++) {
            pos[vals[i]].push_back(i+1);
        }
        for (auto iter = pos.begin(); iter != pos.end(); iter++) {
            if (pos.count(target - iter->first) > 0) {
                const vector<int> &first  = pos[iter->first];
                const vector<int> &second = pos[target - iter->first];
                for (const int &i : first) {
                    for (const int &j : second) {
                        if (i != j) {
                            res.push_back(min(i, j));
                            res.push_back(max(i,j));
                            return res;
                        }
                    }
                }
            }
        }
        return res;
    }

};