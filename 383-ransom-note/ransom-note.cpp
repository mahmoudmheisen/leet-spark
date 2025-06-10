class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> counter(26, 0);

        for (char c : magazine) {
            counter[c - 'a']++;
        }

        for (char c : ransomNote) {
            if (counter[c - 'a'])
                counter[c - 'a']--;
            else
                return false;
        }

        return true;
    }
};