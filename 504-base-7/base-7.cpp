class Solution {
public:
    string convertToBase7(int num) {
        int res = 0;
        
        int i = 1;
        while (num) {
            res += (num % 7) * i;
            num /= 7;
            i *= 10;
        }

        return to_string(res);
    }
};