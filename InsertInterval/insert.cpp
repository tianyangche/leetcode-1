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
        
        vector<Interval> result;
        bool flag = false;
        for (vector<Interval>::iterator iter = intervals.begin(); iter != intervals.end(); iter++) {
            if (newInterval.start <= iter->end && newInterval.end >= iter->start) {
                if (iter->start < newInterval.start)
                    newInterval.start = iter->start;
                if (iter->end > newInterval.end)
                    newInterval.end = iter->end;
                continue;
            }
            if (!flag && newInterval.end < iter->start) {
                result.push_back(newInterval);
                flag = true;
            }
            result.push_back(*iter);
        }
        if (!flag)
            result.push_back(newInterval);
        return result;
    }
};