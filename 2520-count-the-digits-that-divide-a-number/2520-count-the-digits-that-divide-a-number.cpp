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
    int countDigits(int num) {
        vector<int> digits = numsOfDigits(num);
        int count = 0;
        
        for(int digit : digits) {
            if(num % digit == 0) count++;
        }
        
        return count;        
    }
};