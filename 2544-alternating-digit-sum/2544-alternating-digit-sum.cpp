class Solution {
private:
    vector<int> numsOfDigits(int num) {
        vector<int> res;
        while(num > 0) {
            int n = num % 10;
            num /= 10;
            res.push_back(n);
        }

        return res;
    }

public:
    int alternateDigitSum(int n) {
        vector<int> digits = numsOfDigits(n);
        int sum = 0;

        int sign = 1;
        if(digits.size() % 2 == 0) sign *= -1;

        for(int digit : digits) {
            sum += digit*sign;
            sign *= -1;
        }
        
        return sum;
    }
};