class Solution {
public:
    int romanToInt(string s) {
        int number = 0;
        unordered_map<char, int> ht = {
            {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000},
        };

        for (int i = 0; i < s.size() - 1; i++) {
            if (ht[s[i]] < ht[s[i + 1]])
                number -= ht[s[i]];
            else
                number += ht[s[i]];
        }

        return number + ht[s[s.size() - 1]];
    }
};