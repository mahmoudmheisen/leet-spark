class MinStack {
    private:
    vector<int> _internal;
    vector<int> _minTracker;

public:
    MinStack() {
    }
    
    void push(int val) {
        _internal.push_back(val);

        if(_minTracker.empty()) {
            _minTracker.push_back(val);
        } else {
            _minTracker.push_back(min(val, _minTracker.back()));
        }
    }
    
    void pop() {
        _internal.pop_back();
        _minTracker.pop_back();
    }
    
    int top() {
        return _internal.back();
    }
    
    int getMin() {
        return _minTracker.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */