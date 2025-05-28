class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k);
    }

    int quickSelect(vector<int>& nums, int l, int r, int k) {
        int n = nums.size();
        if (l >= r)
            return nums[l];

        int randIdx = rand() % (r - l) + l;
        swap(nums[randIdx], nums[r]);
        int p = partition(nums, l, r);

        if (p > (n - k))
            return quickSelect(nums, l, p - 1, k);
        else if (p < n - k)
            return quickSelect(nums, p + 1, r, k);
        else
            return nums[n - k];
    }

    int partition(vector<int>& nums, int l, int r) {
        int p = nums[r];
        int lo = l;

        for (int i = l; i < r; i++) {
            if (nums[i] < p) {
                swap(nums[lo], nums[i]);
                lo++;
            }
        }
        swap(nums[lo], nums[r]);
        return lo;
    }
};