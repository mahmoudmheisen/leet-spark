class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        while (1) {
            slow = getNextNumber(slow);
            fast = getNextNumber(getNextNumber(fast));

            if (fast == 1)
                return true;
            if (fast == slow)
                return false;
        }

        return false;
    }

    int getNextNumber(int n) {
        int res = 0;
        while (n) {
            int digit = n % 10;
            n /= 10;
            res += digit * digit;
        }

        return res;
    }
};