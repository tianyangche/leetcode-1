class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        if (numbers.empty())
            return res;
        int counter = 1;
        unordered_map<int, vector<int> > nums;
        for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++) {
            unordered_map<int, vector<int> >::iterator i = nums.find(*iter);
            if (i == nums.end()) {
        		vector<int> temp;
        		temp.push_back(counter++);
        		nums[*iter] = temp;
        	} else {
        		(i->second).push_back(counter++);
        	}
        }
        for (unordered_map<int, vector<int> >::iterator iter = nums.begin(); iter != nums.end(); iter++) {
        	int another = target - iter->first;
        	unordered_map<int, vector<int> >::iterator i = nums.find(another);
        	if (i != nums.end()) {
        		if ((iter->first == i->first && (iter->second).size() > 1 ) || (iter->first != i->first)) {
        			if (iter->first != i->first) {
                    	if (iter->second < i->second) {
        					res.push_back((iter->second)[0]);
        					res.push_back((i->second)[0]);
        				} else {
        					res.push_back((i->second)[0]);
        					res.push_back((iter->second)[0]);
        				}
        			} else {
        				if ((iter->second)[0] < (iter->second)[1]) {
        					res.push_back((iter->second)[0]);
        					res.push_back((iter->second)[1]);
        				} else {
        					res.push_back((iter->second)[1]);
        					res.push_back((iter->second)[0]);
        				}
        			}
        			return res;
        		}
        	}
        }
    }
};