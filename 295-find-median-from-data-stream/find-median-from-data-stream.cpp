class MedianFinder {
public:
    priority_queue<int> max_heap; // lower half
    priority_queue<int, vector<int>, greater<int>> min_heap; // upper half

    MedianFinder() {}

    void addNum(int num) {
        // Step 1: Insert
        if (max_heap.empty() || num <= max_heap.top()) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }

        // Step 2: Balance
        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else if (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    double findMedian() {
        if (max_heap.size() == min_heap.size()) {
            return (max_heap.top() + min_heap.top()) / 2.0;
        }
        return max_heap.top();
    }
};
