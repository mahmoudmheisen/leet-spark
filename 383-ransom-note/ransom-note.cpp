class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> ht;

        for (char c : magazine) {
            if (ht.count(c))
                ht[c]++;
            else
                ht[c] = 1;
        }

        for (char c : ransomNote) {
            if (ht.count(c) && ht[c] > 0)
                ht[c]--;
            else
                return false;
        }

        return true;
    }
};