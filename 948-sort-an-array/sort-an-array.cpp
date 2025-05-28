class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);

        return nums;
    }

    void quickSort(vector<int>& nums, int l, int r) {
        if (l >= r)
            return;
        
        int randIdx = rand()%(r-l) + l;
        swap(nums[randIdx], nums[r]);
        int p = partition(nums, l, r);
        quickSort(nums, l, p - 1);
        quickSort(nums, p + 1, r);
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
