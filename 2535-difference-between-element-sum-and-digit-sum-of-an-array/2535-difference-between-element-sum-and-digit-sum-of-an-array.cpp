class Solution {
private:
    int sumOfDigits(int num) {
        int sum = 0;
        while(num > 0) {
            int n = num % 10;
            num /= 10;
            sum += n;
        }
        
        return sum;
    }

public:
    int differenceOfSum(vector<int>& nums) {
        int elSum = 0;
        int diSum = 0;
        
        for(int num : nums) {
            elSum += num;
            diSum += sumOfDigits(num);
        }
        
        return abs(elSum-diSum);
    }
};