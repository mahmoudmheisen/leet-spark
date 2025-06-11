class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string target = "balloon";
        int maxBalloons = INT_MAX;
        unordered_map<char, int> processed;
        unordered_map<char, int> ht;

        for (char character : text) {
            if (ht.count(character))
                ht[character]++;
            else
                ht[character] = 1;
        }

        for (char character : target) {
            if (!processed.count(character)) {
                maxBalloons = min(maxBalloons, ht[character]);
                processed[character] = 1;
            } else {
                processed[character]++;
                maxBalloons =
                    min(maxBalloons, ht[character] / processed[character]);
            }
        }

        return maxBalloons;
    }
};