/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) {
            return a.start < b.start;
        });
        for(int i=0;i<n-1;i++){
            int s0=min(intervals[i].start,intervals[i].end);
            int e0=max(intervals[i].start,intervals[i].end);
            int s1=min(intervals[i+1].start,intervals[i+1].end);
            int e1=max(intervals[i+1].start,intervals[i+1].end);
            if(s1<e0) return 0;

        }
        return 1;
    }
};
