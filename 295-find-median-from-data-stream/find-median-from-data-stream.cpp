class MedianFinder {
private:
    priority_queue<int> leftHeap;
    priority_queue<int, vector<int>, greater<int>> rightHeap;

public:
    MedianFinder() {}

    void addNum(int num) {
        if (leftHeap.empty() || num <= leftHeap.top()) {
            leftHeap.push(num);
            if (leftHeap.size() - rightHeap.size() > 1) {
                int left = leftHeap.top();
                leftHeap.pop();
                rightHeap.push(left);
            }
        } else {
            rightHeap.push(num);
            if (rightHeap.size() > leftHeap.size()) {
                int right = rightHeap.top();
                rightHeap.pop();
                leftHeap.push(right);
            }
        }
    }

    double findMedian() {
        double median = 0;
        if (leftHeap.size() == rightHeap.size()) {
            median = (leftHeap.top() + rightHeap.top()) / 2.0;
        } else {
            median = leftHeap.top();
        }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */