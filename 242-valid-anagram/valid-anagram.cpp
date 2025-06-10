class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> charCounter;

        for (int i = 0; i < s.size(); i++) {
            charCounter[s[i]]++;
            charCounter[t[i]]--;
        }

        for (auto pair : charCounter) {
            if (pair.second)
                return false;
        }

        return true;
    }
};