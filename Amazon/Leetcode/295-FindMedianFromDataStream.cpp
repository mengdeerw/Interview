// time complexity: 
// addNum: O(logN)
// findMedian: O(1)
// total time: O(NlongN) = log1 + log2 +...+logN
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // step-1: make sure left heap size >= right heap size
        if (left_.empty() || num <= left_.top() ) {
            left_.push(num);
        } else {
            right_.push(num);
        }
        
        // step-2: balance two heaps:
        // always make sure left_.size() == right_.size() or left_.size() == right_.size() + 1
        if (left_.size() < right_.size()) {
            left_.push(right_.top());
            right_.pop();
        } else if (left_.size() - right_.size() > 1) {
            right_.push(left_.top());
            left_.pop();
        }
    }
    
    double findMedian() {
        if (left_.size() > right_.size()) {
            return left_.top();
        } else {
            return static_cast<double>(left_.top() + right_.top()) / 2;
        }
    }
private:
    priority_queue<int, vector<int>, less<int>> left_; // max heap
    priority_queue<int, vector<int>, greater<int>> right_; // min heap
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
