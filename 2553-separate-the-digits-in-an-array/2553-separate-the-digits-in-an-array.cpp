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
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        
        for(int num : nums) {
            vector<int> digits = numsOfDigits(num);
            for(auto itr = digits.rbegin(); itr != digits.rend(); itr++) res.push_back(*itr);
        }
        
        return res;  
    }
};