class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> memo;
        int minCoins = dp(coins, amount, memo);

        return minCoins == INT_MAX ? -1 : minCoins;
    }

    int dp(vector<int>& coins, int amount, unordered_map<int, int>& memo) {
        if (amount == 0) return 0;

        if(memo.count(amount)) return memo[amount];

        int minCoins = INT_MAX;
        for(int coin : coins) {
            if ((amount - coin) >= 0) {
                int current = dp(coins, amount - coin, memo);
                minCoins = min(minCoins, current == INT_MAX ? current : current + 1);
            }
        }

        memo[amount] = minCoins;

        return minCoins;
    }
};