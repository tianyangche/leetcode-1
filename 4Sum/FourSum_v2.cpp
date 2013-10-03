class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        if (num.empty() | num.size() < 4)
            return res;
        map<int, vector<vector<int> > > twoSum;
        for (int i = 0; i < num.size() - 1; i++) {
        	for (int j = i + 1; j < num.size(); j++) {
        		vector<int> pos;
        		pos.push_back(i);
        		pos.push_back(j);
        		twoSum[num[i]+num[j]].push_back(pos);
        	}
        }
        unordered_map<int, bool> flag;
        for (map<int, vector<vector<int> > >::iterator iter = twoSum.begin(); iter != twoSum.end(); iter++) {
        	int firstValue  = iter->first;
        	int secondValue = target - (iter->first);
        	if (flag.count(firstValue) <= 0 && twoSum.count(secondValue) > 0 && flag.count(secondValue) <= 0) {
        		const vector<vector<int> > &firstPart  = twoSum[firstValue];
        		const vector<vector<int> > &secondPart = twoSum[secondValue];
        		for (int i = 0; i < firstPart.size(); i++) {
        			int pos0 = firstPart[i][0];
        			int pos1 = firstPart[i][1];
        			for (int j = 0; j < secondPart.size(); j++) {
        				int pos2 = secondPart[j][0];
        				int pos3 = secondPart[j][1];
        				if (pos0 != pos2 && pos0 != pos3 && pos1 != pos2 && pos1 != pos3) {
        					vector<int> newElem;
        					newElem.push_back(num[pos0]);
        					newElem.push_back(num[pos1]);
        					newElem.push_back(num[pos2]);
        					newElem.push_back(num[pos3]);
        					sort(newElem.begin(), newElem.end());
        					if (find(res.begin(), res.end(), newElem) == res.end())
                                res.push_back(newElem);
        				}
        			}
        		}
        		flag[firstValue]  = true;
        		flag[secondValue] = true;
        	}
        }
        return res;
     }
};