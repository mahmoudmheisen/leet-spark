class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;

        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int t = 1; t < amount + 1; t++) {
            for (int coin : coins) {
                if (t >= coin && dp[t - coin] != INT_MAX) {
                    dp[t] = min(dp[t], dp[t - coin] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};