class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int closestNumber = INT_MAX;
        for (int num : nums) {
            if (abs(num) < abs(closestNumber)) {
                closestNumber = num;
            }
            if (abs(num) == abs(closestNumber)) {
                closestNumber = max(closestNumber, num);
            }
        }

        return closestNumber;
    }
};
