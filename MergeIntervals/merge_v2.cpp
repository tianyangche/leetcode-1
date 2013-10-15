/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(const Interval &i, const Interval &j) {return i.start < j.start; }

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        if (intervals.empty())
        	return res;
        Interval newInterval;
        bool flag = false;
        sort(intervals.begin(), intervals.end(), compare);
        for (vector<Interval>::iterator iter = intervals.begin(); iter != intervals.end(); iter++) {
        	if (!flag) {
        		newInterval = Interval(iter->start, iter->end);
        		flag = !flag;
        		continue;
        	}
        	if (newInterval.end < iter->start) {
        		res.push_back(newInterval);
        		newInterval = Interval(iter->start, iter->end);
        		continue;
        	}
        	if (newInterval.start > iter->end) {
        		res.push_back(*iter);
        		continue;
        	}
        	newInterval.start = min(newInterval.start, iter->start);
        	newInterval.end   = max(newInterval.end,     iter->end);
        }
        res.push_back(newInterval);
        return res;
    }

};