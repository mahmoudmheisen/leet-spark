class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> memo;

        int coinsCount = dp(coins, amount, memo);

        return coinsCount == INT_MAX ? -1 : coinsCount;
    }

    int dp(vector<int>& coins, int amount, unordered_map<int, int>& memo) {
        if (amount == 0)
            return 0;

        if (memo.count(amount))
            return memo[amount];

        int minCoin = INT_MAX;
        for (int coin : coins) {
            if (amount >= coin) {
                int current = dp(coins, amount - coin, memo);
                 minCoin = min(minCoin, current == INT_MAX ? INT_MAX : current + 1);
            }
        }

        memo[amount] = minCoin;
        return minCoin;
    }
};