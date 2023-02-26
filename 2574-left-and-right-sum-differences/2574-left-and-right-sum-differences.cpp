class Solution {
    private:
    int summer(vector<int>& vec, int s, int e) {
        int sum = 0;
        for(int i = s; i < e; i++) {
            sum += vec[i];
        }

        return sum;
    }

public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int> leftSum, rightSum, ans;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(i == 0) {
                leftSum.push_back(0);
                if(n > 1) rightSum.push_back(summer(nums, i+1, n));
                else rightSum.push_back(0);

            } else if (i == n - 1) {
                rightSum.push_back(0);
                leftSum.push_back(summer(nums, 0, i));
            } else {
                leftSum.push_back(summer(nums, 0, i));
                rightSum.push_back(summer(nums, i+1, n));
            }
        }

        for(int i = 0; i < n; i++) {
            ans.push_back(abs(leftSum[i]-rightSum[i]));
        }

        return ans;
    }
};