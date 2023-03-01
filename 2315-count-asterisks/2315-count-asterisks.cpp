class Solution {
public:
    int countAsterisks(string s) {
        int exclude = false;
        int count = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '*' && !exclude) count++;
            if(s[i] == '|') exclude = !exclude;
        }
        
        return count;
    }
};
