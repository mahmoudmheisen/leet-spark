class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int, int> memo;
        return dp(n, memo);
    }

    int dp(int n, unordered_map<int, int>& memo) {
        if (n <= 2) return n;

        if(memo.count(n)) return memo[n];

        memo[n] = dp(n-1, memo) + dp(n-2, memo);

        return memo[n];
    }
};