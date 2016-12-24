// insert and merge, slow solution
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
        if(intervals.size() == 0){
            res.push_back(newInterval);
            return res;
        }
        intervals.push_back(newInterval);
        res = merge(intervals);
        return res;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.size() == 0) return res;
        sort(intervals.begin(), intervals.end(), cmp());
        int j = 0;
        int s = intervals[0].start, e = intervals[0].end;
        while(j < intervals.size()){
            if(j == intervals.size() - 1){
                s = min(s, intervals[j].start);
                e = max(e, intervals[j].end);
                res.push_back(Interval(s, e));
                break;
            }
            if(e >= intervals[j + 1].start){
                s = min(s, min(intervals[j + 1].start, intervals[j].start));
                e = max(e, max(intervals[j + 1].end, intervals[j].end));
            }else{
                s = min(s, intervals[j].start);
                e = max(e, intervals[j].end);
                res.push_back(Interval(s, e));
                s = intervals[j + 1].start, e = intervals[j + 1].end;
            }
            ++j;
        }
        return res;
    }
    struct cmp{
        bool operator()(Interval a, Interval b){
            return a.start < b.start;
        }
    };
};