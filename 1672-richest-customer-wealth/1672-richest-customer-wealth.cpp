class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        
        for(vector<int>& customer : accounts) {
            int sum = 0;
            for(int bankMoney: customer) {
                sum += bankMoney;
            }
            if(sum > maxWealth) maxWealth = sum;
        }
        
        return maxWealth;
    }
};