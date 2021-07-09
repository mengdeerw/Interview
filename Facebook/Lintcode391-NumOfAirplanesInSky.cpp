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

// METHOD-1: line sweep
// 扫描线的做法： 创建事件，按照事件发生的时间点排序。 需要注意的是，先离开再进入，不然答案会出错，因此排序时在事件发生时刻相同时，要保证离开事件优先
// time complexity: O(NlongN) where N is the number of airplanes
class Solution {
public:
    struct Event {
    public:
        int time, type;
        Event(int time, int type): time(time), type(type) {} // start: 0; end: 1
    };
    /**
     * @param airplanes: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        vector<Event> events;
        for (auto& interval: airplanes) {
            events.push_back(Event(interval.start, 0));
            events.push_back(Event(interval.end, 1));
        }
        sort(events.begin(), events.end(), [](auto& e1, auto& e2){
            if (e1.time == e2.time) {
                return e1.type >= e2.type; // 时间相同的话，先离开再进入
            }else {
                return e1.time < e2.time;
            }
        });
        int result = 0;
        int now = 0;
        for (auto& e: events) {
            if (e.type == 0) now++;
            else now--;
            result = max(result, now);
        }
        return result;
    }
};

// METHOD-2: greedy + min heap
class Solution {
public:
    /**
     * @param airplanes: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        sort(airplanes.begin(), airplanes.end(), [](auto& a, auto& b){
            return a.start < b.start;
        });
        // min heap
        priority_queue<int, vector<int>, greater<int>> pq; // save end time
        int result = 0;
        for (int i = 0; i < airplanes.size(); i++) {
            int cur_start = airplanes[i].start;
            int cur_end = airplanes[i].end;
            while (!pq.empty() && pq.top() <= cur_start) { // means no overlap
                pq.pop();
            }
            pq.push(cur_end);
            result = max(result, (int)pq.size());
        }
        return result;
    }
};
