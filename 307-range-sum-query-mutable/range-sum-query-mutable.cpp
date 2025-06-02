class NumArray {
private:
    vector<int> _prefixSum;

public:
    NumArray(vector<int>& nums) {
        vector<int> _prefixSum(nums.size(), 0);

        _prefixSum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            _prefixSum[i] = _prefixSum[i - 1] + nums[i];
        }

        this->_prefixSum = _prefixSum;
    }

    void update(int index, int val) {
        int num = index > 0
                      ? this->_prefixSum[index] - this->_prefixSum[index - 1]
                      : this->_prefixSum[0];
        for (int i = index; i < _prefixSum.size(); i++) {
            this->_prefixSum[i] += (val - num);
        }
    }

    int sumRange(int left, int right) {
        return left != 0 ? this->_prefixSum[right] - this->_prefixSum[left - 1]
                          : this->_prefixSum[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */