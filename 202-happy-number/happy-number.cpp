class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> ht;

        int res = 0;
        while (n) {
            int digit = n % 10;
            n /= 10;
            res += digit * digit;

            if (n == 0 && res == 1)
                return true;
            else if (n == 0) {
                n = res;
                if (ht.count(res))
                    return false;
                ht.insert(res);
                res = 0;
            }
        }

        return false;
    }
};