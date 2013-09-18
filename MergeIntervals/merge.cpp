/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool smaller(const Interval &x, const Interval &y) {
        return x.start < y.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.empty())
            return intervals;
        sort(intervals.begin(), intervals.end(), smaller);
        Interval curr = intervals[0];
        vector<Interval> result;
        for (int i = 1; i < intervals.size(); i++) {
        	if (intervals[i].start > curr.end) {
        		result.push_back(curr);
        		curr = intervals[i];
        	} else {
        		if (curr.end < intervals[i].end) {
        			curr.end = intervals[i].end;
        		}
        	}
        }
        result.push_back(curr);
        return result;
    }
};