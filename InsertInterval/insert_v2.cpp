/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        bool flag = false;
        for (int i = 0; i < intervals.size(); i++) {
        	if (flag) {
        		res.push_back(intervals[i]);
        		continue;
        	}
        	if (newInterval.end < intervals[i].start) {
        		flag = true;
        		res.push_back(newInterval);
        		res.push_back(intervals[i]);
        		continue;
        	}
        	if (newInterval.start > intervals[i].end) {
        		res.push_back(intervals[i]);
        		continue;
        	}
        	newInterval.start = min(newInterval.start, intervals[i].start);
        	newInterval.end   = max(newInterval.end,   intervals[i].end  );
        }
        if (!flag)
            res.push_back(newInterval);
        return res;
    }
};