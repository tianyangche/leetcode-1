class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        if (numbers.empty())
        	return res;
        unordered_map<int, vector<int> > recs;
        for (vector<vector<int> >::size_type i = 0; i < numbers.size(); i++) {
        	recs[numbers[i]].push_back(i+1);
        } 
        for (unordered_map<int, vector<int> >::iterator iter = recs.begin(); iter != recs.end(); iter++) {
        	if (recs.count(target - *iter) > 0) {
        		const vector<int> &first  = iter->second;
        		const vector<int> &second = recs[target - *iter];
        		for (vector<int>::const_iterator i = first.begin(); i != first.end(); i++) {
        			for (vector<int>::const_iterator j = second.begin(); j != second.end(); j++) {
        				if (*i == *j)
        					continue;
        				res.push_back(min(*i, *j));
        				res.push_back(max(*i, *j));
        				return res;
        			}
        		}
        	}
        }
        return res;
    }
};