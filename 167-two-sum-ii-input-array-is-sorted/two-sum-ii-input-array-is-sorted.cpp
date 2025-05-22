class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if(sum > target) {
                right--;
                continue;
            } else if (sum < target) {
                left++;
                continue;
            } else {
                return {left+1, right+1};
            }
        }

        return {};
    }
};