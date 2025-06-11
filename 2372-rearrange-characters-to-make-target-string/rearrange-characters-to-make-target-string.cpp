class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int maxTarget = INT_MAX;
        unordered_map<char, int> occurrenceS;
        unordered_map<char, int> occurrenceT;

        for (char c : s) {
            occurrenceS[c]++;
        }

        for (char c : target) {
            occurrenceT[c]++;
        }

        for (auto pair : occurrenceT) {
            maxTarget = min(maxTarget, occurrenceS[pair.first] / pair.second);
        }

        return maxTarget;
    }
};