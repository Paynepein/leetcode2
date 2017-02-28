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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.size() == 0) return res;
        auto cmp = [&](Interval& a, Interval& b) -> bool {
        	if (a.start == b.start) return a.end < b.end;
        	return a.start < b.start;
        };
        sort(intervals.begin(), intervals.end(), cmp);
        int left = intervals[0].start, right = intervals[0].end;
        for (Interval &item : intervals) {
        	if (item.start > right) {
        		res.emplace_back(left, right);
        		left = item.start;
        		right = item.end;
        	} else {
        		right = max(right, item.end);
        	}
        }
        res.emplace_back(left, right);
        return res;
    }
};