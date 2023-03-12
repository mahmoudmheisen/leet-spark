class Solution {
private:
    int getMaxDigit(string n) {
        int max = 0;

        for(char c : n) {
            int num = c - '0';
            max = num > max ? num : max;
        }
        
        return max;
    }
    
public:
    int minPartitions(string n) {
        return getMaxDigit(n);
    }
};