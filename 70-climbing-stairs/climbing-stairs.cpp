class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;

        int prev = 2;
        int pre_prev = 1;

        for(int i = 3; i<= n; i++) {
            int current = prev + pre_prev;
            pre_prev = prev;
            prev = current;
        }

        return prev;
    }
};