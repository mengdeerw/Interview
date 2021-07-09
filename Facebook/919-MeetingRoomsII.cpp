/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

// METHOD-1: greedy + heap
class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        if (intervals.size() == 0) return 0;

        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b){
            if (a.start == b.start) return a.end < b.end;
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> pq; //min heap to save end time
        pq.push(intervals[0].end);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start >= pq.top()) { // no overlap
                pq.pop();
            }
            pq.push(intervals[i].end);
        }
        return pq.size();
    }
};

 /* METHOD-2: Line sweep
扫描线，把所有的时间排序，按照开始时间升序，开始时间相同结束时间升序的方式进行排序，如果时间相同，结束时间在前，
扫描一遍，当扫描到开始时间，就会多一个房间，当扫描到结束时间就少一个房间，这样扫描到i时候就是i时间所需要的最少的房间
我们的房间数量要满足所有时间的需求，所以答案就是对所有时间所需要的最少房间取最大值，这样就能满足所有时间的开会需求了。
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        vector<pair<int, int>> times;
        
        for (int i = 0; i < intervals.size(); i++) {
            times.emplace_back(intervals[i].start, 1); 
            times.emplace_back(intervals[i].end, -1);
        }
        // sort by times; end event should be before start event if they have the same timestamp
        sort(times.begin(), times.end(), [](auto& a, auto& b){
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });

        int cur = 0;
        int result = 0;
        for (int i = 0; i < times.size(); i++) {
            cur += times[i].second; // start time will add one more room, end time minus one room
            result = max(result, cur);
        }
        return result;
    }
};
