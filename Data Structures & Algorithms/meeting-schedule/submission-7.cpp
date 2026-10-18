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
            int s0=intervals[i].start;
            int e0=intervals[i].end;
            int s1=intervals[i+1].start;
            int e1=intervals[i+1].end;
            if(s1<e0) return 0;

        }
        return 1;
    }
};
