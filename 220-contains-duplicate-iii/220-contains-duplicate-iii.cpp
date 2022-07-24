class Solution {
    typedef long long ll;
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> window; // long type to handle INT_MAX and INT_MIN
        
        for (int i = 0; i < nums.size(); ++i) {
            long num = nums[i];
            
            // maintenance size k window
            if (i > k) window.erase(nums[i - k - 1]);
            auto pos = window.lower_bound(num - t);
            if (pos != window.end() && (*pos - num) <= t) return true;
            window.insert(num);
        }
        return false;
    }
};