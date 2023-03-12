class Solution {
public:
    int minPartitions(string n) {
        int max = '0';

        for(char c : n) {
            max = c > max ? c : max;
        }
        
        return max - '0';
    }
};