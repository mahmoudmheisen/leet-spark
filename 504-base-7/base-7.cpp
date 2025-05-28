class Solution {
public:
    string convertToBase7(int num) {
        string base7Representation = "";
        if (!num)
            return "0";

        bool isNegative = num < 0;
        num = abs(num);
        while (num) {
            base7Representation = to_string(num % 7) + base7Representation;
            num = num / 7;
        }

        return isNegative ? "-" + base7Representation : base7Representation;
    }
};