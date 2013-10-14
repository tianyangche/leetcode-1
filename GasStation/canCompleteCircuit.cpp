class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (gas.empty() || cost.empty())
        	return -1;
        if (gas.size() != cost.size())
        	return -1;
        int index = -1;
        int tank  = 0;
        int total = 0;
        for (vector<int>::size_type i = 0; i < gas.size(); i++) {
        	total += gas[i] - cost[i];
        	tank  += gas[i] - cost[i];
        	if (tank < 0) {
        		tank = 0;
        		index = i;
        	}
        }
        return total >= 0 ? (index+1) % gas.size() : -1;
    }
};