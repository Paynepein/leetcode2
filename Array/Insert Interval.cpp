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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int i = 0;
        while (i < intervals.size() && intervals[i].end < newInterval.start) {
        	res.push_back(intervals[i++]);
        }
        if (i == intervals.size()) {
        	res.push_back(newInterval);
        	return res;
        }
        int j = i;
        while (j < intervals.size() && intervals[j].start <= newInterval.end) ++j;
        if (j == 0) {
        	res.push_back(newInterval);
        } else {
        	res.emplace_back(min(intervals[i].start, newInterval.start), max(intervals[j-1].end, newInterval.end));
        }
        while (j < intervals.size()) {
        	res.push_back(intervals[j++]);
        }
        return res;
    }
};