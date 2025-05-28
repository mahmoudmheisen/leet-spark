class Solution {
public:
    string convertToBase7(int num) {
        string base7Representation = "";
        
        if (num == 0) return "0";
        if (num < 0) return "-" + convertToBase7(-num);

        while (num) {
            base7Representation = to_string(num % 7) + base7Representation;
            num /= 7;
        }

        return base7Representation;
    }
};