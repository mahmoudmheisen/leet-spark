class Solution {
public:
    int alternateDigitSum(int num) {
        int count = 0;
        int sum = 0;
        int sign = 1;

        while(num > 0) {
            int last = num % 10;
            num /= 10;
            sum += last * sign;
            sign *= -1;
            count++;
        }
        
        if(count%2 == 0) sum *= -1;

        return sum;
    }
};